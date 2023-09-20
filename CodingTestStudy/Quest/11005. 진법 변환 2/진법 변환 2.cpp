#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, b;
	cin >> n >> b;

	string answer;
	while (n != 0)
	{
		int tmp = n % b; // 나머지를 넣는다.
		if (tmp > 9)
		{
			tmp = tmp - 10 + 'A';
			answer += tmp;
		}
		else
		{
			answer += ('0' + tmp);
		}
		n /= b;
	}
	reverse(answer.begin(), answer.end());

	cout << answer << endl;

	return 0;
}