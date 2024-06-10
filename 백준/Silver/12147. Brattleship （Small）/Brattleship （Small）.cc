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
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) 
    {
        int R, C, W;
        cin >> R >> C >> W;

        // 각 행마다 W 길이의 배를 찾기 위해 필요한 최소 시도 횟수
        int moves_per_row = C / W;

        // 마지막 부분에서 배의 위치를 정확히 찾기 위해 W-1번의 추가 시도가 필요
        int additional_moves = W - 1;

        // 모든 행에서 기본적인 시도 횟수를 계산
        int total_moves = moves_per_row * R + additional_moves;

        // 배가 정확히 C와 일치하지 않을 경우를 위해 추가 점검
        if (C % W != 0) 
        {
            total_moves += 1;
        }

        cout << "Case #" << t << ": " << total_moves << '\n';
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