#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str.size() > 10)
			continue;

		bool flag = true;
		int Large = 0, Small = 0, numCount = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] >= 'A' && str[j] <= 'Z')
				Large++;
			else if (str[j] >= 'a' && str[j] <= 'z')
				Small++;
			if (str[j] >= '0' && str[j] <= '9')
				numCount++;
		}
		if (Large > Small)
			continue;

		if (numCount == str.size())
			continue;

		cout << str << "\n";
	}
	return 0;
}