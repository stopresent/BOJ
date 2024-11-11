using System.Collections.Specialized;

namespace ServerCore
{
    class SessionManager
    {
        static object _lock = new object();

        public static void TestSession()
        {
            lock (_lock)
            {

            }
        }

        public static void Test()
        {
            lock (_lock)
            {
                UserManager.TestUser();
            }
        }
    }

    class UserManager
    {
        static object _lock = new object();

        public static void TestUser()
        {
            lock (_lock)
            {
                
            }
        }

        public static void Test()
        {
            lock (_lock)
            {
                SessionManager.TestSession();
            }
        }
    }

    internal class Program
    {
        static int number = 0;
        static object _obj = new object();

        static void Thread_1()
        {
            for (int i = 0; i < 10000; ++i)
            {
                SessionManager.Test();
            }
        }

        // DeadLock

        static void Thread_2()
        {
            for (int i = 0; i < 10000; ++i)
            {
                UserManager.Test();
            }
        }

        static void Main(string[] args)
        {
            Task t1 = new Task(Thread_1);
            Task t2 = new Task(Thread_2);
            t1.Start();

            //Thread.Sleep(100);

            t2.Start();

            Task.WaitAll(t1, t2);

            Console.WriteLine($"number : {number}");
        }
    }
}