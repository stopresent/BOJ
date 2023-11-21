#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> board;
int n;
int countMinus = 0, countZero = 0, countOne = 0;

void CreateBoard()
{
	cin >> n;

	board = vector<vector<int>>(n, vector<int>(n));

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			cin >> board[y][x];
}

void checkBoard(int y, int x, int size)
{
	int num = board[y][x];
	for (int i = y; i < y + size; ++i)
		for (int j = x; j < x + size; ++j)
			if (num != board[i][j])
			{
				checkBoard(y, x, size / 3);
				checkBoard(y, x + size / 3, size / 3);
				checkBoard(y, x + size / 3 * 2, size / 3);
				checkBoard(y + size / 3, x, size / 3);
				checkBoard(y + size / 3, x + size / 3, size / 3);
				checkBoard(y + size / 3, x + size / 3 * 2, size / 3);
				checkBoard(y + size / 3 * 2, x, size / 3);
				checkBoard(y + size / 3 * 2, x + size / 3, size / 3);
				checkBoard(y + size / 3 * 2, x + size / 3 * 2, size / 3);
				return;
			}
	
	if (num == -1)
		countMinus++;
	else if (num == 0)
		countZero++;
	else
		countOne++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	CreateBoard();

	checkBoard(0, 0, n);

	cout << countMinus << '\n';
	cout << countZero << '\n';
	cout << countOne << '\n';
}
