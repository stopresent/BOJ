#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Divide(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return Divide(y, x % y);
}

int T, A, B;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		cout << A * B / Divide(max(A, B), min(A, B)) << '\n';
	}
}
