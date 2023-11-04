#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n, k;
vector<int> ans;
queue<int> q;

void Setting()
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		q.push(i + 1);
	}
}

void Josephus()
{
	int jCount = 0;
	while (q.empty() == false)
	{
		jCount++;
		if (jCount % k != 0)
		{
			int value = q.front();
			q.pop();
			q.push(value);
		}
		else
		{
			jCount = 0;
			ans.push_back(q.front());
			q.pop();
		}
	}

	cout << "<" << ans[0];
	for (int i = 1; i < ans.size(); ++i)
	{
		cout << ", " << ans[i];
	}
	cout << ">";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Setting();
	Josephus();
}
