#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

float sum = 0;
int subjectCount = 0;
vector<string> inputText;

int main()
{
	for (int i = 0; i < 20; i++)
	{
		string input;
		getline(cin, input);
		inputText.push_back(input);
		
	}

	for (int i = 0; i < inputText.size(); i++)
	{
		if (inputText[i].back() == '+')
		{
			switch (inputText[i][inputText[i].length()-2])
			{
			case 'A':
				sum += 4.5 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			case 'B':
				sum += 3.5 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			case 'C':
				sum += 2.5 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			case 'D':
				sum += 1.5 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			default:
				break;
			}
		}
		else if (inputText[i].back() == '0')
		{
			switch (inputText[i][inputText[i].length() - 2])
			{
			case 'A':
				sum += 4.0 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			case 'B':
				sum += 3.0 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			case 'C':
				sum += 2.0 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			case 'D':
				sum += 1.0 * ((inputText[i][inputText[i].length() - 6]) - 48);
				subjectCount += inputText[i][inputText[i].length() - 6] - 48;
				break;
			default:
				break;
			}
		}
		else if (inputText[i].back() == 'F')
		{
			sum += 0;
			subjectCount += inputText[i][inputText[i].length() - 5] - 48;
		}
	}

	float result = (sum / subjectCount);

	cout << result << endl;

}