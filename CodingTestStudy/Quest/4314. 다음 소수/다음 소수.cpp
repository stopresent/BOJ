#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int T;

map<long long, int> primeCheck;

bool isPrime(long long num)
{
	if (num <= 1)
		return false;

	if (num == 2 || num == 3)
		return true;

	if (num % 2 == 0 || num % 3 == 0)
		return false;

	for (long long i = 5; i * i <= num; i++)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}

	return true;
}

long long FindNextPrime(long long x)
{
	long long index = 2;

	if (x == 0 || x == 1)
	{
		return 2;
	}

	while (true)
	{
		if (x % index == 0)
		{
			x++;
			index = 2;
		}

		index++;

		if (index * index >= x)
		{
			return x;
			break;
		}
	}
}

int main()
{
	cin >> T;

	long long tempInt;
	for (int i = 0; i < T; i++)
	{
		cin >> tempInt;

		while (true)
		{
			if (isPrime(tempInt))
			{
				cout << tempInt << '\n';
				break;
			}
			tempInt++;
		}
	}
}
