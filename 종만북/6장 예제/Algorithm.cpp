#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 코드 6.1 1부터 n까지의 합을 계산하는 반복 함수와 재귀 함수

// 필수 조건: n >= 1
// 결과: 1부터 n까지의 합을 반환한다.
int sum(int n)
{
	int ret = 0;
	for (int i = 0; i <= n; i++)
		ret += i;
	return ret;
}
// 필수 조건: n >= 1
// 결과: 1부터 n까지의 합을 반환한다.
int recursiveSum(int n)
{
	if (n == 1) return 1; // 더이상 쪼개지지 않을 때
	return n + recursiveSum(n - 1);
}


#pragma region printPicked
void printPicked(vector<int>& pick)
{
	for (int i = 0; i < pick.size(); ++i)
	{
		cout << pick[i] + 1 << " ";
	}
	cout << '\n';
}
#pragma endregion


// 코드 6.2 n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘

// n: 전체 원소의 수
// picked: 지금까지 고른 원소들의 번호
// toPick: 더 고를 원소의 수
// 일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
void pick(int n, vector<int>& picked, int toPick)
{
	// 기저 사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if (toPick == 0)
	{
		printPicked(picked);
		return;
	}
	// 고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// 이 단계에서 원소 하나를 고른다.
	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main()
{

}
