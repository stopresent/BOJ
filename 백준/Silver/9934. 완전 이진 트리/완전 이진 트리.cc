#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<int> inorder;
int k;

void dfs(int L, int start, int end)
{
	if (start > end)
		return;

	int mid = (start + end) / 2;
	board[L].push_back(inorder[mid]);

	dfs(L + 1, start, mid - 1);
	dfs(L + 1, mid + 1, end);
}

void solve()
{
	cin >> k;

	int num = pow(2, k) - 1;
	inorder.resize(num);
	board.resize(k);

	for (int i = 0; i < num; ++i)
	{
		cin >> inorder[i];
	}

	dfs(0, 0, num - 1);

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}