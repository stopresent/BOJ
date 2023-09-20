#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int DInt = 0; // 385
int BNum = 0; // 5
string answer;

int SquareForN(int num, int exponent)
{
	int result = 1;

	for (int i = 0; i < exponent; i++)
	{
		result *= num;
	}

	return result;
}

int main()
{
	cin >> DInt >> BNum;

	// 제곱수를 넣어서 나누어지는지 확인
	// 최대치까지 도달하는 것이 목표
	int i = 0;
	int sqrResult = 1;

	while (true)
	{
		if (DInt / sqrResult == 0)
			break;

		sqrResult *= BNum;
		i++;
	}

	// 그 다음 얼만큼 나누어지는지보고 인덱스를 내려가면서 추가적으로 계산해주기
	// 지금 최대 인덱스는 i - 1이 될 것이다.
	int copyDInt = DInt;

	for (int exponent = i - 1; exponent >= 0; exponent--)
	{
		int result = 0;
		int exponentNum = SquareForN(BNum, exponent);
		while (true)
		{
			copyDInt -= exponentNum;

			if (copyDInt < 0)
			{
				copyDInt += exponentNum;
				break;
			}

			result++; // 이 숫자에 따라서 출력할 것.
		}

		result >= 10 ? result = result + 55 : result = result;
		// A : 65 니까 10 = 65, 55더해주기
		result >= 10 ? answer += (char)result : answer += ((char)result + 48);

	}

	cout << answer;
	return 0;
}