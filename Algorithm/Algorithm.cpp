#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

/*

	2738	��� ����

����
N*Mũ���� �� ��� A�� B�� �־����� ��, �� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� ũ�� N �� M�� �־�����. ��° �ٺ��� N���� �ٿ� ��� A�� ���� M���� ���ʴ�� �־�����. �̾ N���� �ٿ� ��� B�� ���� M���� ���ʴ�� �־�����. N�� M�� 100���� �۰ų� ����, ����� ���Ҵ� ������ 100���� �۰ų� ���� �����̴�.

���
ù° �ٺ��� N���� �ٿ� ��� A�� B�� ���� ����� ����Ѵ�. ����� �� ���Ҵ� �������� �����Ѵ�.

���� �Է� 1
3 3
1 1 1
2 2 2
0 1 0
3 3 3
4 4 4
5 5 100

���� ��� 1
4 4 4
6 6 6
5 6 100

*/

int n, m;

int matrix[100][100];

int main()
{
	cin >> n >> m;
	const int N = n;

	int arr[100][100];
	int arr2[100][100];

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int num;
			cin >> num;
			arr[y][x] = num;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int num;
			cin >> num;
			arr2[y][x] = num;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			matrix[y][x] = arr[y][x] + arr2[y][x];
			cout << matrix[y][x] << " ";
		}
		cout << endl;
	}
}