#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n, m, k;
vector<vector<int>> ma; // 매트릭스 a
vector<vector<int>> mb; // 매트릭스 b
vector<vector<int>> retMat; // 행렬 곱 결과

void CreateMatrix()
{
	cin >> n >> m;
	ma = vector<vector<int>>(n, vector<int>(m));
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cin >> ma[y][x];

	cin >> m >> k;
	mb = vector<vector<int>>(m, vector<int>(k));	
	for (int y = 0; y < m; ++y)
		for (int x = 0; x < k; ++x)
			cin >> mb[y][x];

	retMat = vector<vector<int>>(n, vector<int>(k));
}

void multiply()
{
	for (int y = 0; y < n; y++) 
	{
		for (int x = 0; x < k; x++) 
		{
			for (int i = 0; i < m; i++) 
			{
				retMat[y][x] += ma[y][i] * mb[i][x];
			}
			cout << retMat[y][x] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	CreateMatrix();
	multiply();
}
