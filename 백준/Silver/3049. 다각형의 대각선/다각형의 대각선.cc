#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;

    // 대각선 교차점 개수를 계산하기 위한 조합 C(N, 4)
    if (N < 4) {
        // 4각형 미만에서는 교차점이 존재하지 않음
        cout << "0" << endl;
    }
    else {
        // C(N, 4) = N * (N-1) * (N-2) * (N-3) / 24
        long long combination = 1;
        combination *= N;
        combination *= (N - 1);
        combination *= (N - 2);
        combination *= (N - 3);
        combination /= 24;
        cout << combination << endl;
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