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

vector<string> split(const string& input, string delimiter)
{
	vector<string> result;
	int start = 0;
	int end = input.find(delimiter);
	while (end != string::npos)
	{
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));

	return result;
}

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> ch = split(s, "*");
	int size1 = ch[0].size();
	int size2 = ch[1].size();

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		int size = str.size();
		if (size < (size1 + size2))
		{
			cout << "NE" << '\n';
			continue;
		}

		string substr1 = str.substr(0, size1);
		string substr2 = str.substr(size - size2);

		if (substr1 == ch[0] && substr2 == ch[1])
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
	}
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