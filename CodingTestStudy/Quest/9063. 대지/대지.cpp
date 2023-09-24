#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int minX = 10001;
int maxX = -10001;
int minY = 10001;
int maxY = -10001;

int N;
// 넓이 : (maxY - minY) * (maxX - minX)

map<int, vector<int>> _coordinate;
int x;
int y;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		x > maxX ? maxX = x : x;
		x < minX ? minX = x : x;
		y > maxY ? maxY = y : y;
		y < minY ? minY = y : y;
	}

	if (N <= 1)
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << (maxY - minY) * (maxX - minX) << endl;
	}

}
