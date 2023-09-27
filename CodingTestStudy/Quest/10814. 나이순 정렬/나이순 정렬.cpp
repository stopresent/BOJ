#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N, age;
string name;
map<int, vector<string>> _ageAndName;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age;
		cin >> name;
		_ageAndName[age].push_back(name);
	}

	for (int ageIndex = 1; ageIndex <= 200; ageIndex++)
	{
		for (int nameIndex = 0; nameIndex < _ageAndName[ageIndex].size(); nameIndex++)
		{
			if (_ageAndName[ageIndex][nameIndex] == "")
				continue;

			cout << ageIndex << " " << _ageAndName[ageIndex][nameIndex] << '\n';
		}
		
	}
}
