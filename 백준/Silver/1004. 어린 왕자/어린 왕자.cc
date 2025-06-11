#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t, n;

// 문제 : 원의 최소 진입/이탈 횟수 구하기

// 원의 중심 좌표와 반지름을 저장하기 위한 구조체 정의
struct Circle
{
	int x, y, r;
};

void solve()
{
	int x1, y1, x2, y2; // 출발지, 도착지 좌표
	cin >> t;
	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		int cx, cy, r; // 원의 중심 좌표와 반지름
		vector<Circle> circleData(n); // 원의 정보 저장을 위한 벡터
		for (int i = 0; i < n; ++i)
		{
			// 원의 중심 좌표와 반지름 입력 받기
			cin >> cx >> cy >> r;
			circleData[i].x = cx;
			circleData[i].y = cy;
			circleData[i].r = r;
		}

		int cnt = 0; // 진입/이탈 횟수 카운트

		for (int i = 0; i < n; ++i)
		{
			// 원의 중심과 출발지, 도착지 사이의 거리 계산
			int startDist = (x1 - circleData[i].x) * (x1 - circleData[i].x) +
				(y1 - circleData[i].y) * (y1 - circleData[i].y);
			int endDist = (x2 - circleData[i].x) * (x2 - circleData[i].x) +
				(y2 - circleData[i].y) * (y2 - circleData[i].y);
			int radiusSquared = circleData[i].r * circleData[i].r;
			// 출발지와 도착지가 원의 내부에 있는지 확인
			bool startInside = startDist < radiusSquared;
			bool endInside = endDist < radiusSquared;
			// 진입/이탈 횟수 카운트
			if (startInside && !endInside)
				cnt++; // 원에 진입
			else if (!startInside && endInside)
				cnt++; // 원에서 이탈
		}

		// 결과 출력
		cout << cnt << '\n';
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