#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<string, int> poketmons;
map<int, string> poketmonsByInt;
vector<string> inputStrings;
string tempString;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tempString;
		poketmons[tempString] = i + 1;
		poketmonsByInt[i] = tempString;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> tempString;
		inputStrings.push_back(tempString);
	}

	for (int i = 0; i < M; i++)
	{
		if (inputStrings[i][0] >= 'A' && inputStrings[i][0] <= 'Z') // 문자열로 입력 받을 때
		{
			cout << poketmons[inputStrings[i]] << '\n';
		}
		else // 숫자로 입력 받을 때
		{
			cout << poketmonsByInt[stoi(inputStrings[i]) - 1] << '\n';
		}
	}
}
