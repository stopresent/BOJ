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

    int count = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        // '-' 위치 찾기
        size_t pos = s.find('-');
        if (pos == string::npos || pos == s.length() - 1) {
            // '-'가 없거나 '-' 뒤에 숫자가 없으면 무시
            continue;
        }

        // '-' 뒤의 숫자 부분 추출
        string num_str = s.substr(pos + 1);
        int xi;
        try {
            xi = stoi(num_str);
        }
        catch (...) {
            // 숫자 변환에 실패하면 무시
            continue;
        }

        // 유효기간이 90일 이하인 경우 카운트
        if (xi <= 90) {
            count++;
        }
    }

    cout << count;
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