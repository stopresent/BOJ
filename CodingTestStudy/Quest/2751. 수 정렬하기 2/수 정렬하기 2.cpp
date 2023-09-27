#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, temp;
	cin >> N;

	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i] << '\n';
	}
}
