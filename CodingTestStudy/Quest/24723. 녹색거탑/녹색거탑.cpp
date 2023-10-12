#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N; 

	cin >> N;

	int ret = 1;
	for (int i = 0; i < N; i++)
	{
		ret = ret * 2;
	}

	cout << ret << endl;
}
