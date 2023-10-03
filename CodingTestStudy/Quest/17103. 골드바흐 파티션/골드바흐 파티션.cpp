#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;
const int maxNum = 1000000;

int arr[maxNum + 1] = { 0, };

bool isPrime(int num)
{
	if (num <= 1)
		return false;

	if (num == 2 || num == 3)
		return true;

	if (num % 2 == 0 || num % 3 == 0)
		return false;

	for (int i = 5; i * i <= num; i++)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false; 
	}

	return true;
}

void checkingPrime()
{
	// ¼Ò¼ö¸é 0?
	arr[0] = 1;

	for (int i = 2; i * i <= maxNum; i++)
	{
		for (int index = i * 2; index < maxNum; index += i)
		{
			arr[index] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	checkingPrime();
	int T;

	cin >> T;

	int tempInt;
	int goldPartitionCount = 0;
	for (int index = 0; index < T; index++)
	{
		cin >> tempInt;
		for (int i = 2; i <= tempInt / 2; i++)
		{
			//if (isPrime(tempInt - i) && isPrime(i))
			//	goldPartitionCount++;

			if (arr[i] == 0 && arr[tempInt - i] == 0)
				goldPartitionCount++;
		}
		cout << goldPartitionCount << '\n';
		goldPartitionCount = 0;
	}
}
