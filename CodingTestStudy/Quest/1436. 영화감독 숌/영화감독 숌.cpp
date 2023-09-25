#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N;
int sixNumCount = 0;

int NSqaure(int n)
{
	int result = 1;

	for (int i = 0; i < n; i++)
		result *= 10;

	return result;
}

// 연속된 666 이 있는지 없는지 판별하는 함수
bool IsInclude666(int num)
{
	int digit = 0;

	int temp = num;
	while (true)
	{
		temp /= 10;
		digit++;

		if (temp == 0)
			break;
	}

	for (int i = 0; i < digit; i++)
	{
		int six1 = (num % (10 * NSqaure(i))) / (1 * NSqaure(i));
		int six2 = (num % (100 * NSqaure(i))) / (10 * NSqaure(i));
		int six3 = (num % (1000 * NSqaure(i))) / (100 * NSqaure(i));

		if (six1 == 6 && six2 == 6 && six3 == 6)
			return true;
	}

	return false;
}

int main()
{
	cin >> N;

	int i = 0;
	int num = 660;

	while (true)
	{
		if (IsInclude666(num))
			i++;

		if (i == N)
		{
			cout << num;
			break;
		}

		num++;

	}

}
