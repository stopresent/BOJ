#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// Stack (LIFO) : Last In First Out 선입후출

template <typename T>
class Stack
{
public:

	void push(const T& value)
	{
		_container.push_back(value);
	}

	T& top()
	{
		return _container.back();
	}

	void pop()
	{
		_container.pop_back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	vector<T> _container;
};

int n;

int main()
{
	Stack<int> s;

	cin >> n;

	int tempInt;
	string temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;

		if (temp == "push")
		{
			cin >> tempInt;
			s.push(tempInt);
		}
		else if (temp == "pop")
		{
			if (s.size() == 0)
				cout << -1 << endl;
			else
			{
				int v = s.top();
				cout << v << endl;
				s.pop();
			}
		}
		else if (temp == "size")
		{
			cout << s.size() << endl;
		}
		else if (temp == "empty")
		{
			if (s.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (temp == "top")
		{
			if (s.size() == 0)
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
	}
}