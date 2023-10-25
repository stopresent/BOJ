#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <math.h>

using namespace std;


int n, temp;
vector<int> v;

int operators[4];

int minNum = INT32_MAX;
int maxNum = INT32_MIN;

void GetMinAndMax(int result, int idx)
{
	if (idx == n)
	{
		if (result > maxNum) maxNum = result;
		if (result < minNum) minNum = result;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			if (i == 0) // 더하기
				GetMinAndMax(result + v[idx], idx + 1);
			else if (i == 1) // 빼기
				GetMinAndMax(result - v[idx], idx + 1);
			else if (i == 2) // 곱하기
				GetMinAndMax(result * v[idx], idx + 1);
			else // 나누기
				GetMinAndMax(result / v[idx], idx + 1);
			operators[i]++;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v[i] = temp;
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> temp;
		operators[i] = temp;
	}

	GetMinAndMax(v[0], 1);
	cout << maxNum << '\n' << minNum;
}
