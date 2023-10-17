#include <iostream>
#include <algorithm>

using namespace std;

long long Factorial(int n)
{
	if (n == 1)
		return 1;
	return n * Factorial(n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	if (N == 0)
	{
		cout << 1;
		return 0;
	}

	long long fac = Factorial(N);
	cout << fac;

	return 0;
}
