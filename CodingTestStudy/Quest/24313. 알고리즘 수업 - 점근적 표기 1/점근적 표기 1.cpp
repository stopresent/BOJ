#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int a1, a0, c, n0;

int main()
{
	cin >> a1 >> a0 >> c >> n0;

	// a1 �� ����� ���
	if (a1 > 0)
	{
		// c�� a1���� ũ�ų� ����, g(n)�� f(n)�� ���� �̻󿡼� ���ǿ��� ������ ��� 1
		if ((c >= a1) && (n0 >= (a0 / (float)(c - a1))))
		{
			cout << 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}

	// a1 �� 0�� ���
	if (a1 == 0)
	{
		// ���ǿ��� ���� �̻��̿��� �ϹǷ�
		// n0�� a0���� ũ�ų� ���ƾ��Ѵ�.
		if (n0 >= (a0 / (float)c))
		{
			cout << 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}

	// a1 �� ������ ���
	if (a1 < 0)
	{
		// �������� ������ g(n)�� f(n)���� Ŀ����.
		// �׷��� �̰� ���� ���ǿ��� ���� �̻��̸� �ȴ�.
		if ((n0 >= (a0 / (float)(c - a1))))
		{
			cout << 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
}
