#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, tempInt;
vector<int> inputTrees;
vector<int> gaps;
vector<int> gapDivisors;
int result = 0;

int Divide(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return Divide(y, x % y);
}

int main()
{
	cin >> N;

	int maxDivisor = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> tempInt;
		inputTrees.push_back(tempInt);
	}

	reverse(inputTrees.begin(), inputTrees.end());

	for (int i = 0; i < N - 1; i++)
	{
		gaps.push_back(inputTrees[i] - inputTrees[i + 1]);
	}
	maxDivisor = gaps[0];

	for (int i = 0; i < N - 2; i++)
	{
		maxDivisor = Divide(maxDivisor, gaps[i + 1] );
	}


	for (int i = 0; i < N - 1; i++)
	{
		result += (gaps[i] / maxDivisor) - 1;
	}

	cout << result;
}
