#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	int sum = a + b + c;
	int max = 0;
	if (max < a) max = a;
	if (max < b) max = b;
	if (max < c) max = c;

	if ((sum - max) <= max)
		cout << (sum - max) * 2 - 1;
	else
		cout << sum;
}
