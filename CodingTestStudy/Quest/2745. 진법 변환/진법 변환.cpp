#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

string inputString;
int bNum;

int ConvertChar(char input)
{
	return (input >= 48 && input <= 57) ? input - 48 : input - 55;
}

int main()
{
	int result = 0;
	cin >> inputString >> bNum;
	int sqr = 0;
	// A = 10
	// Z = 35
	for (int i = inputString.length() - 1; i >= 0; i--)
	{
		// �� �ڸ����� �°� ���ϱ�.
		
		int sqrResult = 1;
		
		for (int i = 0; i < sqr; i++)
		{
			if (sqr == 0) continue;
			sqrResult *= bNum;
		}

		int digit = ConvertChar(inputString[i]);
		sqrResult *= digit; // �ڸ����� �����ִ°� ���ϱ�.

		sqr++;

		result += sqrResult;
	}

	cout << result;
}