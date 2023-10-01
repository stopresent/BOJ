#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<string, int> inputStrings;
string tempString;
int ansCount = 0;
vector<string> ansVec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tempString;
		inputStrings[tempString] = 1;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> tempString;
		if (inputStrings[tempString] == 1)
		{
			ansVec.push_back(tempString);
			ansCount++;
		}
	}

	cout << ansCount << '\n';
	sort(ansVec.begin(), ansVec.end());

	for (int i = 0; i < ansCount; i++)
	{
		cout << ansVec[i] << '\n';
	}
}
