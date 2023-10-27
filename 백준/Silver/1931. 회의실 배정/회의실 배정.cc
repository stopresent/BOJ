#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>


using namespace std;

int n, s, temp, maxCount;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; // 데이터의 크기

	v.resize(n);

	// 회의 기록 삽입
	int startTime, endTime;
	for (int i = 0; i < n; i++)
	{
		cin >> startTime >> endTime;
		v[i].first = endTime;
		v[i].second = startTime;
	}

	std::sort(v.begin(), v.end());

	int curTime = v[0].first;
	maxCount = 1;
	for (int i = 1; i < n; i++)
	{
		if (curTime <= v[i].second)
		{
			curTime = v[i].first;
			maxCount++;
		}
	}

	// 결과 출력
	cout << maxCount<< endl;
}
