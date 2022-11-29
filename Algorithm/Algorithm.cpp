#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

int g_count = 0;

int cache[50][50];

int combination(int n, int r)
{
	// ±âÀú »ç·Ê
	if (r == 0 || n == r)
		return 1;

	if (cache[n][r] != -1)
		return cache[n][r];

	return cache[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	int lotto = combination(45, 6);
	cout << lotto << " " << g_count << endl;

}