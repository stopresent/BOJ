#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class balloon
{
public:
	int _index;
	int _next;
};

int main()
{
	int N;
	int tempInt;
	vector<balloon> balloons;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> tempInt;
		balloons.push_back({ i, tempInt });
	}

	while (!balloons.empty())
	{
		cout << balloons.front()._index << " ";
		int next = balloons.front()._next;
		balloons.erase(balloons.begin());

		if (balloons.empty())
			break;

		if (next > 0)
		{
			for (int i = 0; i < next - 1; i++)
			{
				balloons.push_back(balloons.front());
				balloons.erase(balloons.begin());
			}
		}
		else
		{
			for (int i = 0; i < ((-1) * next); i++)
			{
				balloons.insert(balloons.begin(), balloons.back());
				balloons.erase(balloons.end() - 1);
			}
		}
	}

}
