#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve()
{
	cin >> t;
	while (t--)
	{
		cin >> n;

		// 스티커의 점수를 저장할 벡터
		vector<int> top(n), bottom(n);

		// 위쪽 스티커 점수 입력
		for (int i = 0; i < n; ++i) cin >> top[i];
		// 아래쪽 스티커 점수 입력
		for (int i = 0; i < n; ++i) cin >> bottom[i];

		// dp 초기화 : 이전 열의 상태
		// prev0 : 이전 열에서 스티커를 선택하지 않은 경우
		// prev1 : 이전 열에서 위쪽 스티커를 선택한 경우
		// prev2 : 이전 열에서 아래쪽 스티커를 선택한 경우
		int prev0 = 0, prev1 = 0, prev2 = 0;

		// 각 열을 순회하며 dp 갱신
		for (int i = 0; i < n; ++i) {
			// 현재 열의 상태를 계산
			int current0 = max({ prev0, prev1, prev2 });
			int current1 = max(prev0, prev2) + top[i];
			int current2 = max(prev0, prev1) + bottom[i];

			// 이전 열의 상태를 갱신
			prev0 = current0;
			prev1 = current1;
			prev2 = current2;
		}

		// 최종 결과는 마지막 열의 최댓값
		int ret = max({ prev0, prev1, prev2 });
		cout << ret << '\n';
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