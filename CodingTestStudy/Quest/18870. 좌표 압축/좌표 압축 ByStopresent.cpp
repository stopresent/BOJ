#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int N;
int temp;
vector<int> numVec;
vector<int> checkVec;

int main()
{
	cin >> N;

	// 숫자를 모두 입력한다
	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		numVec.push_back(temp);
	}

	// 각 인덱스의 숫자보다 작은 숫자들을 모은다
	for (int i = 0; i < numVec.size(); i++)
	{
		int resultCount = 0;

		for (int checkIndex = 0; checkIndex < numVec.size(); checkIndex++)
		{
			if (numVec[i] > numVec[checkIndex])
			{
				checkVec.push_back(numVec[checkIndex]);

				bool flag = false;
				for (int checkVecIndex = 0; checkVecIndex < checkVec.size() - 1; checkVecIndex++)
				{
					// numVec[checkIndex]의 값이 이때까지의 체크리스트에 없다면
					if (checkVec[checkVecIndex] == numVec[checkIndex])
						flag = true;
				}

				if (flag == false)
					resultCount++;
			}
		}
		checkVec = { 0, };
		cout << resultCount << " ";
	}
}
