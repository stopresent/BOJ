#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			cout << " ";
		}
		
		for (int j = 0; j < 2 * i + 1; ++j)
		{
			cout << "*";
		}

		cout << '\n';
	}
}
