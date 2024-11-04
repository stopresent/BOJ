#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    string T;
    cin >> T;

    int S = 0; // 한쪽만 모르는 쌍의 수
    int U = 0; // 양쪽 모두 모르는 쌍의 수
    bool flag = true; // 팰린드롬 여부를 확실히 알 수 있는지

    for (int i = 0; i < N / 2; ++i) {
        int j = N - 1 - i;
        char left = T[i];
        char right = T[j];

        if (left != '?' && right != '?') {
            if (left != right) {
                // 두 문자가 다르면 팰린드롬이 아님을 알 수 있음
                cout << "0";
                return;
            }
            // 두 문자가 같으면 추가 질의 불필요
        }
        else if (left != '?' || right != '?') {
            // 한쪽만 모르는 경우
            S += 1;
        }
        else {
            // 양쪽 모두 모르는 경우
            U += 1;
        }
    }

    // 만약 N이 홀수이고 가운데 문자가 '?'인 경우, 이는 팰린드롬 여부에 영향을 주지 않음
    // 따라서 별도의 처리가 필요 없음

    // 최소 질의 횟수 계산
    int K = S + 26 * U;
    cout << K;
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