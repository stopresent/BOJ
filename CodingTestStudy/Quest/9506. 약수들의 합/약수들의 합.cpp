#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n;
string isNotPerfect = " is NOT perfect.";
int keyIndex = 0;
map<int, int> nSave;
map<int, int> divisorSum;
map<int, vector<int>> saveDivisor;

int main()
{
	while (true)
	{
		cin >> n;
		if (n == -1)
			break;

		int index = 0;
		nSave[keyIndex] = n;

		// 약수들을 구한다
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				saveDivisor[keyIndex].push_back(i);
				divisorSum[keyIndex] += i;
				index++;
			}
		}

		// 합이 일치하지 않을 떄 예외처리
		if (n != divisorSum[keyIndex])
		{
			saveDivisor[keyIndex].push_back(-1);
		}

		keyIndex++;
	}

	// n과 약수들의 합을 비교한다
	// 결과에 맞게 출력한다.
	for (int i = 0; i < keyIndex; i++)
	{
		if (saveDivisor[i].back() == -1)
		{
			cout << nSave[i] << isNotPerfect << endl;
			continue;
		}

		cout << nSave[i] << " = 1";

		for (int j = 1; j < saveDivisor[i].size(); j++)
		{
			cout << " + " << saveDivisor[i][j];
		}
		cout << endl;
	}

}
