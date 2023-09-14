#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int T, N;
int minNum = 101, maxNum = -1;

int main()
{
	cin >> T;
	// 최소 최대 차이 곱하기 2
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int num;

		for (int j = 0; j < N; j++)
		{
			cin >> num;
			if (num >= maxNum)
				maxNum = num;
			if (num <= minNum)
				minNum = num;
		}
		cout << (maxNum - minNum) * 2 << endl;
		minNum = 101, maxNum = -1;
	}
}