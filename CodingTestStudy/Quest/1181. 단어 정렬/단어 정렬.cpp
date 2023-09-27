#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N;
string temp;
map<int, vector<string>> stringMap;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		int stringSize = temp.size();

		stringMap[stringSize].push_back(temp);
	}

	for (int index = 0; index < 51; index++)
	{
		sort(stringMap[index].begin(), stringMap[index].end());
	}

	string beforeString;
	for (int index = 0; index < 51; index++)
	{
		for (int stringCount = 0; stringCount < stringMap[index].size(); stringCount++)
		{
			if (beforeString != stringMap[index][stringCount])
			{
				cout << stringMap[index][stringCount] << endl;
				beforeString = stringMap[index][stringCount];
			}
		}
	}
}
