#include <iostream>
using namespace std;
#include <string>

/*

8. �ùٸ� ��ȣ
��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� ��YES", �ùٸ��� ������ ��NO"�� ����մϴ�.
(())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�.

�� �Է¼���
ù ��° �ٿ� ��ȣ ���ڿ��� �Էµ˴ϴ�. ���ڿ��� �ִ� ���̴� 30�̴�.

�� ��¼���
ù ��° �ٿ� YES, NO�� ����Ѵ�.

�� �Է¿��� 1
(()(()))(()

�� ��¿��� 1
NO

�� �Է¿��� 2
()()(()())

�� ��¿��� 2
YES

*/

int main()
{
	string input;
	cin >> input;

	int Scount = 0, Ecount = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		if (Ecount > Scount)
		{
			cout << "NO";
			return 0;
		}

		if (input[i] == '(') Scount++;
		if (input[i] == ')') Ecount++;

	}

	if (Scount == Ecount)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}