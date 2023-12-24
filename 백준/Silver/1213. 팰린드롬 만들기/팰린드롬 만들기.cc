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

// 단어가 모두 짝수개이면 팰린드롬 가능
// 하나만 홀수개여도 가능

string str;
string impos = "I'm Sorry Hansoo";
int cache[30], checkCnt = 0, odd;

void solve()
{
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		cache[str[i] - 'A']++;
	}

	// 팰린드롬 가능 여부 체크
	for (int i = 0; i < 30; ++i)
	{
		if (cache[i] % 2 != 0)
		{
			odd = i;
			checkCnt++;
		}
		if (checkCnt >= 2)
		{
			cout << impos;
			return;
		}
	}

	stack<char> s;
	char oddChar = odd + 'A';
	// 팰린드롬으로 만들기
	if (checkCnt == 0) // 짝수개만 있을 때
	{
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < cache[i] / 2; ++j)
			{
				cout << (char)(i + 'A');
				s.push(i + 'A');
			}
		}

		while (s.empty() == false)
		{
			cout << s.top();
			s.pop();
		}
	}
	else // 홀수가 하나 있을 때
	{
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < cache[i] / 2; ++j)
			{
				cout << (char)(i + 'A');
				s.push(i + 'A');
			}
		}
		cout << oddChar;
		while (s.empty() == false)
		{
			cout << s.top();
			s.pop();
		}
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