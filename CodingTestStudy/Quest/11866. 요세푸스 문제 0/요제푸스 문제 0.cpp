#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	list<int> li;
	vector<int> ans;

	for (int i = 0; i < N; i++)
	{
		li.push_back(i + 1);
	}

	list<int> ::iterator it = li.begin();

	while (!li.empty())
	{
		
		for (int i = 0; i < K - 1; i++)
		{
			if (it == li.end())
				it = li.begin();
			it++;
			if (it == li.end())
				it = li.begin();
		}

		ans.push_back(*it);
		
		it = li.erase(it);
	}

	cout << '<' << ans[0];
	for (int i = 0; i < ans.size() - 1; i++)
	{
		cout << ", " << ans[i + 1];
	}
	cout << '>';
}
