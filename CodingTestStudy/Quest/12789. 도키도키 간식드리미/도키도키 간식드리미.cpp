#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N;

bool CanGetSnack(queue<int> line)
{
	int index = 1;
	int lineSize = line.size();
	stack<int> s;

	while (!line.empty())
	{
		int lineFront = line.front();
		line.pop();
		s.push(lineFront);

		if (lineFront == index)
		{
			s.pop();
			index++;
			while (true)
			{
				if (!s.empty() && s.top() == index)
				{
					s.pop();
					index++;
				}
				else if (!s.empty() && s.top() != index)
					break;
				else if (s.empty())
					break;
			}
		}
	}
		
	if (s.empty())
		return true;
	else
		return false;
}

int main()
{
	cin >> N;
	int tempInt;

	queue<int> q;

	while (N > 0)
	{
		cin >> tempInt;
		q.push(tempInt);

		N--;
	}

	if (CanGetSnack(q))
		cout << "Nice" << '\n';
	else
		cout << "Sad" << '\n';

}
