#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n;
int cache[1000] = { 0, }, s[1000];

int lis(int start)
{
	int& ret = cache[start];
	if (ret != 0)
		return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next)
	{
		if (s[start] < s[next])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		s[i] = temp;
	}

	int ret = 1;
	for (int i = 0; i < n; ++i)
	{
		ret = max(ret, lis(i));
	}

	cout << ret;
}
