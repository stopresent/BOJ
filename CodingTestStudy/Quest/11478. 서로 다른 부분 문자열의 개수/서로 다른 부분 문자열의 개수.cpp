#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string S;
map<string, int> sMap;
string tempString;

int main()
{
	cin >> S;

	int sLength = S.length();

	for (int i = 0; i < sLength; i++)
	{
		for (int firstIndex = 0; firstIndex < sLength - i; firstIndex++)
		{
			tempString = S.substr(i, firstIndex + 1);
			if (sMap[tempString] != 1)
			{
				sMap[tempString] = 1;
			}
		}
	}

	cout << sMap.size() << '\n';
}
