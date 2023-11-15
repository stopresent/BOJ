#include <iostream>

using namespace std;

int main()
{
	int N = 0;	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= i - 1; k++)
		{
			cout << " ";
		}
		for (int j = i; j <= N; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
