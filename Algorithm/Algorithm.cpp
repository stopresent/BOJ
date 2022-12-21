#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

/*

2721�� �ﰢ���� ��

����
n��° �ﰢ��, T(n)�� 1���� n������ ���̴�. 
T(n) = 1 + ... + n. �̰��� �ﰢ�� ������� ǥ���� �� �ִ�. 
�Ʒ� �׸��� T(4)�� ��Ÿ�� ���̴�.

������ ���� ���� ���� ����ġ�� �ο��� �ﰢ���� ���� ���� �� �ִ�.

W(n) = Sum[k=1..n; k*T(k+1)]

n�� �־����� ��, W(n)�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ���� n �ϳ��� �̷���� �ִ�. (1<=n<=300)

���
�� �׽�Ʈ ���̽��� ���� W(n)�� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
4
3
4
5
10

���� ��� 1
45
105
210
2145

*/

int T;

int SumTriangleNum(int n)
{
	int ret = 0;

	for (int i = 1; i <= n; i++)
	{
		ret += i;
	}

	return ret;
}

int SumWeightTriangleNum(int n)
{
	int ret = 0;

	for (int i = 0; i <= n; i++)
	{
		ret += i * SumTriangleNum(i + 1);
	}

	return ret;
}

int main() 
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		int ret = SumWeightTriangleNum(num);
		cout << ret << endl;
	}
}
