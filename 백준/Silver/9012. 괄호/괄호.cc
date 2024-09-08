#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

bool CheckVPS(string str)
{
	int firstCount = 0, secondCount = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (secondCount > firstCount)
			return false;

		char strIndex = str[i];
		if (strIndex == '(')
			firstCount++;
		else
			secondCount++;
	}

	if (firstCount != secondCount)
		return false;

	return true;
}

int main()
{
	int N;
	char first = '(';
	char second = ')';
	string inputString;
	cin >> N;

	vector<string> ans;

	while (true)
	{
		if (N == 0)
			break;

		cin >> inputString;

		if (CheckVPS(inputString))
			ans.push_back("YES");
		else
			ans.push_back("NO");

		N--;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
}
