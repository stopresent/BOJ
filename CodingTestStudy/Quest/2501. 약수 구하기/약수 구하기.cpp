#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, K;
map<int, int> answer;

int main()
{
	cin >> N >> K;
	int index = 1;
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			answer[index] = i;
			index++;
		}
	}

	if (K > index || K <= 0)
	{
		cout << 0;
	}
	else
	{
		cout << answer[K];
	}
}
