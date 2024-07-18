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
int answer = 0;
void solve()
{
    int N, M;

    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int start = 0;
    int end = 0;
    int sum = arr[0];
    while (end < N) {
        if (sum < M) {
            end++;
            if (end < N)
                sum += arr[end];
        }
        else if (sum > M) {
            sum -= arr[start];
            start++;
        }
        else if (sum == M) {
            sum -= arr[start];
            start++;
            end++;
            if (end < N)
                sum += arr[end];
            answer++;
        }
    }

    cout << answer;
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