#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N;

int CenterMoveCount(int n)
{
	if (n == 1) return 3;
	return CenterMoveCount(n - 1) * 2 - 1;
}

int main()
{
	cin >> N;

	int centerMoveCont = CenterMoveCount(N);
	centerMoveCont *= centerMoveCont;

	cout << centerMoveCont;
}
