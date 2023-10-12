#include <iostream>
#include <algorithm>

using namespace std;

int cache[101][101];

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
	for (int y = 0; y < 101; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			cache[y][x] = -1;
		}
	}

	int N, K;

	cin >> N >> K;

	int ret = Combination(N, K);

	cout << ret << endl;
}
