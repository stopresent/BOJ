#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int N;
	int tempInt, maxInt = -4001, minInt = 4001, sum = 0;
	int maxFrequency = -1, maxFrequencyNum = -4001, secondMaxFrequencyNum = -4001;
	cin >> N;
	map<int, int> m;
	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		cin >> tempInt;
		v.push_back(tempInt);

		m[tempInt]++;
		
		if (m[tempInt] == maxFrequency)
		{
			if (tempInt < maxFrequencyNum)
			{
				secondMaxFrequencyNum = maxFrequencyNum;
				maxFrequencyNum = tempInt;
			}
			else if (maxFrequencyNum < tempInt && tempInt < secondMaxFrequencyNum)
			{
				secondMaxFrequencyNum = tempInt;
			}
		}
		
		if (m[tempInt] > maxFrequency)
		{
			maxFrequency = m[tempInt];
			maxFrequencyNum = tempInt;
			secondMaxFrequencyNum = -4001;
		}

		if (tempInt > maxInt) maxInt = tempInt;
		if (tempInt < minInt) minInt = tempInt;

		sum += tempInt;

	}

	std::sort(v.begin(), v.end());

	double halfNum = (double)sum / N - (int)sum / N;
	if (halfNum <= -0.5 && sum < 0) halfNum = -1;
	else if (halfNum >= 0.5 && sum > 0) halfNum = 1;
	else halfNum = 0;

	double midIndex = (double)N / 2 - 0.5;

	std::cout << (int)sum / N + halfNum << "\n";
	std::cout << v[midIndex] << "\n";
	// 최빈값
	if (secondMaxFrequencyNum != -4001)
		std::cout << secondMaxFrequencyNum << "\n";
	else
		std::cout << maxFrequencyNum << "\n";
	std::cout << maxInt - minInt << "\n";
}
