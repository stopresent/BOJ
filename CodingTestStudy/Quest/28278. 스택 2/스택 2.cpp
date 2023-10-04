#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<int> ans;

template <typename T>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void top()
	{
		if (_container.size() == 0)
		{
			ans.push_back(-1);
		}
		else
		{
			ans.push_back(_container.back());
		}
	}

	void pop()
	{
		if (_container.size() == 0)
		{
			ans.push_back(-1);
		}
		else
		{
			ans.push_back(_container.back());
			_container.pop_back();
		}
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	vector<T> _container;
};

int N;
int inputInt;

int main()
{
	cin >> N;

	Stack<int> s;

	while (N > 0)
	{
		cin >> inputInt;

		switch (inputInt)
		{
		case 1:
			cin >> inputInt;
			s.push(inputInt);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			ans.push_back(s.size());
			break;
		case 4:
			ans.push_back(s.empty());
			break;
		case 5:
			s.top();
			break;
		}

		N--;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
}
