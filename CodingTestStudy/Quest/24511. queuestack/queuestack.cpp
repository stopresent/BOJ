#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int N;
	int tempInt;
	int element;
	vector<int> v;
	vector<int> ans;
	stack<int> s;
	queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tempInt;
		v.push_back(tempInt);
	}
	
	for (int i = 0; i < N; i++)
	{
		cin >> tempInt;
		if (v[i] == 0)
			s.push(tempInt);
	}

	cin >> tempInt;
	for (int i = 0; i < tempInt; i++)
	{
		cin >> element;
		q.push(element);
		if (!s.empty())
		{
			int value = s.top();
			ans.push_back(value);
			s.pop();
		}
		else
		{
			int value = q.front();
			ans.push_back(value);
			q.pop();
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}
