#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
int n;
vector<int> seq;

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}

	int min_num = INT_MAX;
	pair<int, int> ans;

	int left = 0, right = n - 1;
	while (left < right)
	{
		if (abs(seq[left] + seq[right]) == 0)
		{
			ans.first = seq[left];
			ans.second = seq[right];
			break;
		}

		if (abs(seq[left] + seq[right]) < abs(min_num))
		{
			min_num = abs(seq[left] + seq[right]);
			ans.first = seq[left];
			ans.second = seq[right];
		}

		if (seq[left] + seq[right] > 0)
			right--;
		else
			left++;
	}

	cout << ans.first << " " << ans.second;
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