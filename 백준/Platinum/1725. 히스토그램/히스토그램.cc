#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n;

// 코드 19.1 스택을 사용해 울타리 자르기 문제를 해결하는 스위핑 알고리즘

// 각 판자의 높이를 저장하는 배열
vector<int> h;
// 스택을 사용한 O(n) 해법
int solveStack()
{
	// 남아있는 판자들의 위치들을 저장한다.
	stack<int> remaining;
	h.push_back(0);
	int ret = 0;
	for (int i = 0; i < h.size(); ++i)
	{
		// 남아 있는 판자들 중 오른쪽 끝 판자가 h[i]보다 높으면
		// 이 판자의 최대 사각형은 i에서 끝난다.
		while (!remaining.empty() && h[remaining.top()] >= h[i])
		{
			int j = remaining.top();
			remaining.pop();
			int width = -1;
			// j번째 판자 왼쪽에 판자가 하나도 안 남아 있는 경우 left[j] = -1,
			// 아닌 경우 left[j] = 남아 있는 판자 중 가장 오른쪽에 있는 판자의 번호
			// 가 된다.
			if (remaining.empty())
				width = i;
			else
				width = (i - remaining.top() - 1);
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	return ret;
}

void board()
{
	cin >> n;
	h.push_back(0);

	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		h.push_back(temp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	board();
	cout << solveStack();
}
