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
    int N, K;
    cin >> N >> K;

    vector<long long> arr(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> arr[i];
    }

    // 수열 정렬
    sort(arr.begin(), arr.end());

    // 누적 변화량을 저장할 배열
    vector<long long> delta(N + 1, 0);

    // 각 쿼리에 대해 처리
    for (int i = 0; i < K; ++i) 
    {
        int L, R;
        long long X;
        cin >> L >> R >> X;
        L--; R--; // 1부터 시작하는 인덱스를 0부터 시작하는 인덱스로 변환

        // delta 배열에 구간 변경 사항 기록
        delta[L] += X;
        if (R + 1 < N) 
        {
            delta[R + 1] -= X;
        }
    }

    // 누적 합 계산 및 적용
    long long cumulative = 0;
    for (int i = 0; i < N; ++i) 
    {
        cumulative += delta[i];
        arr[i] += cumulative;
    }

    // 최종 수열을 다시 정렬
    sort(arr.begin(), arr.end());

    // 최종 결과 출력
    for (int i = 0; i < N; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
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