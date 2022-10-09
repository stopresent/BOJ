#include <iostream>
using namespace std;
#include <string>
#include "math.h"

/*

10. �ڸ����� ��

N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ����ϴ� ���α׷��� �ۼ��ϼ���.
�� �ڿ����� �ڸ����� ���� ���ϴ� �Լ��� int digit_sum(int x)�� �� �ۼ��ؼ� ���α׷��� �ϼ���.

�� �Է¼���
ù �ٿ� �ڿ����� ���� N(3<=N<=100)�� �־�����, �� ���� �ٿ� N���� �ڿ����� �־�����.
�� �ڿ����� ũ��� 10,000,000�� ���� �ʴ´�.

�� ��¼���
�ڸ����� ���� �ִ��� �ڿ����� ����Ѵ�. �ڸ����� ���� �ִ��� �ڿ����� �������� ��� ��
�� ���� ���� ū ���� ����մϴ�.

�� �Է¿��� 1
5
125 15232 79 1325 97

�� ��¿��� 1
97

*/

int digit_sum(int x)
{
	int sum = 0;

	while (true)
	{
		if (x == 0) break;

		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int main()
{
	int n, num, max = 0, maxNum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (max == digit_sum(num))
		{
			if (num > maxNum) maxNum = num;
		}
		if (max < digit_sum(num))
		{
			max = digit_sum(num);
			maxNum = num;
		}
	}

	cout << maxNum;
	return 0;
}