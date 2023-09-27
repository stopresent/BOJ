#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 자리수를 구하고 그것을 배열에 넣은 후 정렬된 값으로 호출

int N, temp;

int main()
{
	cin >> N;

	int digitArr[11] = { 0 };

	while (true)
	{
		if (N == 0)
			break;

		temp = N % 10;
		digitArr[temp]++;
		N = N / 10;
	}

	for (int i = 10; i >= 0; i--)
	{
		if (digitArr[i] == 0)
			continue;

		for (int digitCount = 0; digitCount < digitArr[i]; digitCount++)
		{
			cout << i;
		}
	}
}
