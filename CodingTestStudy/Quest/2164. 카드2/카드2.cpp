#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int N;

int main()
{
	cin >> N;

	list<int> li;

	for (int i = 0; i < N; i++)
	{
		li.push_back(i + 1);
	}

	while (li.size() > 1)
	{
		li.pop_front();
		int liFront = li.front();
		li.pop_front();
		li.push_back(liFront);
	}

	cout << li.front() << endl;
}
