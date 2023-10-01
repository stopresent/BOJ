#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<int, int> nMaps;
int tempInt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tempInt;
		nMaps[tempInt]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> tempInt;
		cout << nMaps[tempInt] << " ";
	}
}
