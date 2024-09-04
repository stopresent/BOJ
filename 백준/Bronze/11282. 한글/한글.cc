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
	int n; // 입력으로 주어지는 숫자 (1-Based)
	string s; // 출력되는 한글 (UTF-8 : 3Byte)
	cin >> n;
	n += 3071; // 1-Based를 0-Based로 변환
	s.push_back(n / 4096 + 234);
	s.push_back(n / 64 % 64 + 128);
	s.push_back(n % 64 + 128);
	cout << s;
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