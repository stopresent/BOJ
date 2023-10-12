#include <iostream>
#include <algorithm>

using namespace std;

int cache[30][30];

int Combination(int n, int k)
{
	if (k == 0 || n == k)
		return 1;

	int& ret = cache[n][k];
	if (ret != -1)
		return ret;

	return ret = Combination(n - 1, k) + Combination(n - 1, k - 1);
}

int main()
{
	int T;
	int N, M;

	cin >> T;

	while (T > 0)
	{
		for (int y = 0; y < 30; y++)
		{
			for (int x = 0; x < 30; x++)
			{
				cache[y][x] = -1;
			}
		}

		cin >> N >> M;
		cout << Combination(M, N) << "\n";

		T--;
	}
}
