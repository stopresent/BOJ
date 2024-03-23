#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
vector<pair<int, int>> x;
vector<int> ans, idx;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		x.push_back({ a, b });
	}
	sort(x.begin(), x.end());

	ans.push_back(x.front().second);
	idx.push_back(0);

	for (int i = 1; i < x.size(); ++i)
	{
		int next = x[i].second;
		if (ans.back() < next)
		{
			ans.push_back(next);
			idx.push_back(ans.size() - 1);
		}
		else
		{
			int left = 0, right = ans.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (ans[mid] < next)
					left = mid + 1;
				else
					right = mid;
			}

			ans[left] = next;
			idx.push_back(left);
		}
	}

	cout << x.size() - ans.size() << '\n';

	int cur = ans.size() - 1;
	vector<int> v;
	for (int i = idx.size() - 1; i >= 0; --i)
	{
		if (cur == idx[i])
			cur--;
		else
			v.push_back(x[i].first);
	}

	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << '\n';

}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}