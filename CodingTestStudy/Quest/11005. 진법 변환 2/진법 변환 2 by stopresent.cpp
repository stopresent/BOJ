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

	// �������� �־ ������������ Ȯ��
	// �ִ�ġ���� �����ϴ� ���� ��ǥ
	int i = 0;
	int sqrResult = 1;

	while (true)
	{
		if (DInt / sqrResult == 0)
			break;

		sqrResult *= BNum;
		i++;
	}

	// �� ���� ��ŭ ���������������� �ε����� �������鼭 �߰������� ������ֱ�
	// ���� �ִ� �ε����� i - 1�� �� ���̴�.
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

			result++; // �� ���ڿ� ���� ����� ��.
		}

		result >= 10 ? result = result + 55 : result = result;
		// A : 65 �ϱ� 10 = 65, 55�����ֱ�
		result >= 10 ? answer += (char)result : answer += ((char)result + 48);

	}

	cout << answer;
	return 0;
}