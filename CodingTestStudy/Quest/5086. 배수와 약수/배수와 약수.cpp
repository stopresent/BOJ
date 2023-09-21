#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int firstNum;
int secondNum;
map<int, string> answer;

int main()
{
	int index = 0;

	while (true)
	{
		cin >> firstNum >> secondNum;

		if (firstNum == 0 && secondNum == 0)
			break;

		if (secondNum % firstNum == 0)
			answer[index] = "factor";
		else if (firstNum % secondNum == 0)
			answer[index] = "multiple";
		else
			answer[index] = "neither";

		index++;
	}

	for (int i = 0; i < index; i++)
	{
		cout << answer[i] << endl;
	}
}
