#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, w, L;
// n : 트럭의 수
// w : 다리의 길이
// L : 최대 하중
vector<int> bridge;

// n = 1000, w = 100, L = 1000
// 시간 복잡도를 신경안써도 될정도
// 그럼 매 순간 다리위 무게를 계산해서 움직이기?

void solve()
{
	cin >> n >> w >> L;
	bridge = vector<int>(w); // 다리 길이 설정
	queue<int> trucks;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		trucks.push(temp);
	}

	int res = 0;

	// 큐가 빌 때 동안
	while (trucks.empty() == false)
	{
		// 다리 위 트럭 무게 확인
		int sum = 0;
		for (int i = 0; i < w; ++i)
		{
			sum += bridge[i];
		}

		int temp = sum + trucks.front() - bridge[w - 1];
		if (temp <= L)
		{
			// 이동하기
			for (int i = w - 1; i > 0; --i)
			{
				bridge[i] = bridge[i - 1];
			}

			bridge[0] = trucks.front();
			trucks.pop();

			res++;
		}
		else
		{
			// 이동하기
			for (int i = w - 1; i > 0; --i)
			{
				bridge[i] = bridge[i - 1];
			}
			bridge[0] = 0;

			res++;
		}
	}

	// 다리에 남은거 움직이기
	for (int i = 0; i < w; ++i)
	{
		if (bridge[i] != 0)
		{
			temp = i;
			break;
		}
	}
	res += (w - temp);

	// 결과 출력
	cout << res;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}