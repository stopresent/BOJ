#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, K;
map<int, int> scores;

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int score;
		cin >> score;
		scores[i] = score;
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (scores[x + 1] > scores[x])
			{
				int temp = 0;
				temp = scores[x];
				scores[x] = scores[x + 1];
				scores[x + 1] = temp;
			}
		}
	}

	cout << scores[K - 1];
}
