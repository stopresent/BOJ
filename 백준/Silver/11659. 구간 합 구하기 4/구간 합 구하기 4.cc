#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n + 1);

	int temp, partialSum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		partialSum += temp;
		v[i] = partialSum;
	}

	int fInput, sInput;
	for (int i = 0; i < m; i++)
	{
		cin >> fInput;
		cin >> sInput;
		cout << v[sInput] - v[fInput - 1] << '\n';
	}
}
