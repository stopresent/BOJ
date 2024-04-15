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
#include <string>
#include <sstream>

using namespace std;

vector<char> vowel = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

void solve()
{
	string input;
	while (true)
	{
		std::getline(std::cin, input);
		if (input == "#")
			break;

		int cnt = 0;
		for (int i = 0; i < input.size(); ++i)
		{
			for (int j = 0; j < vowel.size(); ++j)
			{
				if (input[i] == vowel[j])
				{
					cnt++;
					break;
				}
			}
		}

		cout << cnt << '\n';
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