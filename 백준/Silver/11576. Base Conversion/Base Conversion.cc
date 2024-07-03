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

void solve()
{
	int A, B, m;
	cin >> A >> B >> m;
	int num = 0, temp = 0;
	for (int i = m; i > 0; --i)
	{
		cin >> temp;
		num += pow(A, i - 1) * temp;
	}

	vector<int> ans;
	while (num > 0)
	{
		ans.push_back(num % B);
		num /= B;
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
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