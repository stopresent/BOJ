#include <iostream>
using namespace std;
#include <iomanip>

/*

7. ������ ����

������� �Է� : 1 ~ 100 ������ ����

�Է� ����
5

��� ����
01 02 03 04 05
16 17 18 19 06
15 24 25 20 07
14 23 22 21 08
13 12 11 10 09

*/

const int MAX = 100;
int board[MAX][MAX] = {};
int N;


void PrintBoard()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		cout << endl;
	}
}

void SetBoard()
{

}

int main()
{
	cin >> N;

	PrintBoard();

	SetBoard();

	return 0;
}