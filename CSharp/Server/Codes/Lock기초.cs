using System.Collections.Specialized;

namespace ServerCore
{
    // 경합 조건 (race condition)

    internal class Program
    {
        static int number = 0;
        static object _obj = new object();

        static void Thread_1()
        {
            for (int i = 0; i < 100000; ++i)
            {
                // 상호배제 Mutual Exclusive

                // c++ : CriticalSection, c++표준 : std::mutex
                Monitor.Enter(_obj); // 문을 잠구는 행위
                {
                    number++;
                }
                Monitor.Exit(_obj); // 잠금을 풀어준다
                // Enter와 짝을 맞춰야한다.

                {
                    // 해결방안 1
                    try
                    {
                        Monitor.Enter(_obj);
                        number++;
                    }
                    finally
                    {
                        Monitor.Exit(_obj); // 무조건 Exit를 실행하게 된다.
                    }
                }

                lock (_obj)
                {
                    // 해결방안 2
                    number++;
                }
            }
        }

        // DeadLock

        static void Thread_2()
        {
            for (int i = 0; i < 100000; ++i)
            {
                Monitor.Enter(_obj);

                number--;

                Monitor.Exit(_obj);
            }
        }

        static void Main(string[] args)
        {
            Task t1 = new Task(Thread_1);
            Task t2 = new Task(Thread_2);
            t1.Start();
            t2.Start();

            Task.WaitAll(t1, t2);

            Console.WriteLine($"number : {number}");
        }
    }
}