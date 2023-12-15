#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

class Queue
{
public:
	void push(const int& value)
	{
		_container.push_back(value);
	}

	int pop()
	{
		if (_container.empty())
			return -1;

		int ret = _container.front();
		_container.pop_front();
		return ret;
	}

	int front()
	{
		if (!_container.empty())
			return _container.front();
		else
			return -1;
	}

	int back()
	{
		if (!_container.empty())
			return _container.back();
		else
			return -1;
	}

	int size() { return _container.size(); }
	bool empty() { return _container.empty(); }

public:
	list<int> _container;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int tempInt;
	string tempString;
	Queue q;

	cin >> N;

	while (N > 0)
	{
		cin >> tempString;

		if (tempString == "push")
		{
			cin >> tempInt;
			q.push(tempInt);
		}
		else if (tempString == "pop")
		{
			cout << q.pop() << '\n';
		}
		else if (tempString == "size")
		{
			cout << q.size() << '\n';
		}
		else if (tempString == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (tempString == "front")
		{
			cout << q.front() << '\n';
		}
		else if (tempString == "back")
		{
			cout << q.back() << '\n';
		}

		N--;
	}
}
