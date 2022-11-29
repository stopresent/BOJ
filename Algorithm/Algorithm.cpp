#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// 동적 계획법 (DP)
// LIS : Longest Increasing Sequence

// Seq : 1 9 2 5 7
// 부분 수열 : 일부 (0개 이상) 숫자를 지우고 남은 수열
// ex ) 1 2 5
// ex ) 1 9 5 7
// 순 증가 부분 수열
// ex ) 1 2 5

// LIS : 제일 긴 [순 증가 부분 수열]의 길이
// 1 2 5 7 = 길이 4

vector<int> seq;
int cache[100];

int LIS(int idx)
{
	// 기저 사례
	if (idx >= seq.size() - 1)
		return 1;

	// 메모이제이션
	if (cache[idx] != -1)
		return cache[idx];

	// 문제 해결
	cache[idx] = 1;

	for (int nextPos = idx + 1; nextPos < seq.size(); nextPos++)
		if (seq[idx] < seq[nextPos])
			cache[idx] = max(cache[idx], LIS(nextPos) + 1);

	return cache[idx];
}

int LIS_Rookiss(int pos)
{
	// 기저 사항
	//if (pos == seq.size() - 1)
	//	return 1;

	// 캐시 확인
	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	// 구하기

	// 최소 seq[pos]은 있으니 1부터 시작
	ret = 1;

	// 구하기
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS_Rookiss(next));

	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	seq = vector<int>{ 1, 9, 2, 5, 7 };

	int ret = 0;

	for (int i = 0; i < seq.size() - 1; i++)
		ret = max(ret, LIS(i));

	cout << ret << endl;

}