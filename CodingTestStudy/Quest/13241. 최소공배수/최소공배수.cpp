#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long Divide(long long x, long long y)
{
	if (x % y == 0)
		return y;
	else
		return Divide(y, x % y);
}

long long A, B;

int main()
{
	cin >> A >> B;

	cout << A * B / Divide(max(A, B), min(A, B)) << '\n';
}