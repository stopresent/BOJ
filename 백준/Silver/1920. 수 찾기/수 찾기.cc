#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, M;

vector<int> nV;

bool findNum(int key)
{
	int left = 0, right = N - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (nV[mid] == key)
			return true;
		else if (nV[mid] > key) right = mid - 1;
		else left = mid + 1;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int tempInt;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tempInt;
		nV.push_back(tempInt);
	}

	sort(nV.begin(), nV.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> tempInt;
		cout << findNum(tempInt) << "\n";
	}
}
