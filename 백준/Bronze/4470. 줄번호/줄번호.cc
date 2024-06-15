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

using namespace std;

void solve()
{
	int N;
	cin >> N;
	cin.ignore(); // 버퍼에 남아있는 개행 문자를 무시

	for (int i = 1; i <= N; ++i) 
	{
		string line;
		getline(cin, line);
		cout << i << ". " << line << endl;
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