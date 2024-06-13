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

bool isValid(vector<string>& board) 
{
    vector<int> row(8, 0), col(8, 0);
    vector<int> diag1(15, 0), diag2(15, 0); // 주대각선과 부대각선
    int queenCount = 0;

    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            if (board[i][j] == '*') 
            {
                queenCount++;
                if (++row[i] > 1 || ++col[j] > 1 || ++diag1[i - j + 7] > 1 || ++diag2[i + j] > 1) 
                {
                    return false; // 하나의 행, 열, 주대각선, 부대각선에 두 개 이상의 여왕이 존재
                }
            }
        }
    }

    return queenCount == 8; // 여왕의 수가 정확히 8이어야 함
}

void solve()
{
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) 
    {
        cin >> board[i];
    }

    if (isValid(board)) 
    {
        cout << "valid" << endl;
    }
    else 
    {
        cout << "invalid" << endl;
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