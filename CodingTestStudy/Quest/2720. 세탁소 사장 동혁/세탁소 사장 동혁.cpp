#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 쿼터 : 25센트, 다임 : 10센트, 니켈 : 5센트, 페니 : 1센트

int T; // 테스트 케이스
int money;
int index = 0;

vector<int> ConvertChange(int money)
{
	vector<int> result = { 0,0,0,0 };

	int quarterChange = money / 25;
	money -= quarterChange * 25;

	int dimeChange = money / 10;
	money -= dimeChange * 10;

	int nickelChange = money / 5;
	money -= nickelChange * 5;

	int centChange = money / 1;

	result[0] = quarterChange;
	result[1] = dimeChange;
	result[2] = nickelChange;
	result[3] = centChange;

	return result;
}

int main()
{
	cin >> T;
	map<int, vector<int>> answer;

	for (int i = 0; i < T; i++)
	{
		cin >> money;

		vector<int> convertChangeResult = ConvertChange(money);
		answer[index] = convertChangeResult;
		index++;
	}

	for (int answerCount = 0; answerCount < T; answerCount++)
	{
		cout << answer[answerCount][0] << " " << answer[answerCount][1] << " " << answer[answerCount][2] << " " << answer[answerCount][3] << endl;
	}
}