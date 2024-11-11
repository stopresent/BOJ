using System.Collections.Specialized;

namespace ServerCore
{
    // 경합 조건 (race condition)

    internal class Program
    {
        static int number = 0;

        static void Thread_1()
        {
            // atomic = 원자성

            for (int i = 0; i < 100000; ++i)
            {
                // All or Nothing
                // 실행이 되거나 실행이 안되거나.
                Interlocked.Increment(ref number); // 성능에서 손해를 보지만 원자적으로 코드가 실행된다.

                //number++;
            }
        }

        static void Thread_2()
        {
            for (int i = 0; i < 100000; ++i)
            {
                Interlocked.Decrement(ref number);

                //number--;
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