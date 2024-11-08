namespace ServerCore
{
    internal class Program
    {
        //static void MainThread()
        //{
        //    //while (true)
        //    //    Console.WriteLine("Hello Thread!");
        //}
        private static void MainThread(object? state)
        {
            for (int i = 0; i < 5; ++i)
            {
                Console.WriteLine("Hello Tread!");
            }
        }

        static void Main(string[] args)
        {
            ThreadPool.SetMinThreads(1, 1);
            ThreadPool.SetMaxThreads(5, 5);

            for (int i = 0; i < 5; ++i)
            {
                Task t = new Task(() => { while (true) { } }, TaskCreationOptions.LongRunning);
                t.Start();
            }

            //for (int i = 0; i < 5; ++i) // 5개의 작업을 물고있으면 인력이 부족해짐.
            //{
            //    ThreadPool.QueueUserWorkItem((obj) => { while (true) { } });
            //}
            // 쓰레드풀에 쓰레드를 다 사용하면 작동되지 않는다.
            ThreadPool.QueueUserWorkItem(MainThread);

            //for (int i = 0; i < 1000; ++i)
            //{
            //    Thread t = new Thread(MainThread);
            //    t.Name = "Test Thread";
            //    t.IsBackground = true; // 기본적으로는 false인 상태.
            //                           // false라면 메인 함수가 끝나도 쓰레드는 끝나지 않는다.
            //    t.Start();
            //}

            //Console.WriteLine("Waiting for Thread!");

            //t.Join(); // t의 작업이 끝날 때까지 기다린다.

            //Console.WriteLine("Hello, World!");

            while (true)
            {

            }
        }


    }
}