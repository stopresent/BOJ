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
    int n;
    cin >> n;

    vector<vector<int>> classes(n, vector<int>(5));

    // 학생별 학년별 반 정보를 입력받기
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
        {
            cin >> classes[i][j];
        }
    }

    int maxCount = 0;
    int leader = 0;

    // 각 학생별로 같은 반이었던 학생 수 계산
    for (int i = 0; i < n; ++i) 
    {
        int count = 0;
        for (int j = 0; j < n; ++j) 
        {
            if (i != j) 
            {
                for (int k = 0; k < 5; ++k) 
                {
                    if (classes[i][k] == classes[j][k]) 
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        // 가장 많은 친구를 가진 학생을 찾음
        if (count > maxCount) 
        {
            maxCount = count;
            leader = i + 1;
        }
    }
    if (leader == 0)
        leader = 1;
    // 결과 출력
    cout << leader << '\n';

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