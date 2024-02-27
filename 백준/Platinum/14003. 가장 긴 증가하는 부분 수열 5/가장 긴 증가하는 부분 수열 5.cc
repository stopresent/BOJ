#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int arr[1000010];
int indexArr[1000010];
vector<int> v;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		if (v.size() == 0 || v[v.size() - 1] < arr[i])
		{
			v.push_back(arr[i]);
			indexArr[i] = v.size() - 1;
		}
		else
		{
			int left = 0;
			int right = v.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;

				if (v[mid] >= arr[i])
					right = mid;
				else
					left = mid + 1;
			}
			v[left] = arr[i];
			indexArr[i] = left;
		}
	}

	cout << v.size() << '\n';

	stack<int> ans;
	int idx = v.size() - 1;
	for (int i = n; i > 0; --i)
	{
		if (indexArr[i] == idx)
		{
			idx--;
			ans.push(arr[i]);
		}
	}

	while (ans.empty() == false)
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}