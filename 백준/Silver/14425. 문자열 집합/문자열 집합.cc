#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, M;
map<string, bool> input;
int sameCount = 0;

int main()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		input.insert(pair<string, bool>(str, true));
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;

		if (input[str] == true)
			sameCount++;
	}

	cout << sameCount;
}
