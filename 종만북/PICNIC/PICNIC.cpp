#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 코드 6.5 소풍 문제를 해결하는 재귀 호출 코드

bool taken[10] = { 0, };
int n;
bool areFriend[10][10];
// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10])
{
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	// 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) return 1;
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
	{
		if (!taken[pairWith] && areFriend[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

// 코드 6.4 소풍 문제를 해결하지 (잘못된) 재귀 호출 코드

// int n; // 총 학생의 수
// bool areFriend[10][10];
// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings1(bool taken[10])
{
	// 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	bool finished = true;
	for (int i = 0; i < n; ++i)
		if (!taken[i])
			finished = false;
	if (finished) return 1;
	int ret = 0;
	// 서로 친구인 두 학생을 찾아 짝을 지어 준다.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!taken[i] && !taken[j] && areFriend[i][j])
			{
				taken[i] = taken[j] = true;
				ret += countPairings1(taken);
				taken[i] = taken[j] = false;

			}
		}
	}
	return ret;
}

void Picnic()
{
	int c; // 테스트 케이스
	int m; // 학생 쌍의 수

	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		cin >> n;
		cin >> m;

		int fInput, sInput;
		for (int i = 0; i < m; ++i)
		{
			cin >> fInput >> sInput;
			areFriend[fInput][sInput] = true;
		}

		for (int i = 0; i < 10; ++i)
			taken[i] = false;

		cout << countPairings(taken) << endl;
	}
}



int main()
{
	Picnic();
}
