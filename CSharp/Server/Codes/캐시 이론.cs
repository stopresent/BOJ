namespace ServerCore
{
    internal class Program
    {
        // 캐시 이론
        // Temporal locality
        //  시간적으로 보면, 방금 주문한 테이블에서 추가 주문이 나올 확률이 높다.
        //  방금 주문한 걸 메모해 놓으면 편하지 않을까?
        // Spacial locality
        //  공간적으로 보면, 방금 주문한 사람 근처에 있는 사람이 추가 주문을 할 확률이 높다.
        //  방금 주문한 사람과 합석하고 있는 사람들의 주문 목록도 메모해 놓으면 편하지 않을까?

        static void Main(string[] args)
        {
            int[,] arr = new int[10000, 10000];

            // 5 * 5 배열
            {
                long now = DateTime.Now.Ticks;
                for (int y = 0; y < 10000; ++y)
                    for (int x = 0; x < 10000; ++x)
                        arr[y, x] = 1;
                long end = DateTime.Now.Ticks;
                Console.WriteLine($"(y, x) 순서 걸린 시간 {end - now}");
            }

            {
                long now = DateTime.Now.Ticks;
                for (int y = 0; y < 10000; ++y)
                    for (int x = 0; x < 10000; ++x)
                        arr[x, y] = 1;
                long end = DateTime.Now.Ticks;
                Console.WriteLine($"(x, y) 순서 걸린 시간 {end - now}");
            }
        }
    }
}
