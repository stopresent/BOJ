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

	int a, b;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		temp = 1;
		for (int j = 0; j < b; ++j)
		{
			temp = temp * a;
			temp = temp % 10;
		}

		temp = temp % 10;
		if (temp == 0)
			cout << 10 << '\n';
		else
			cout << temp << '\n';
	}
}
