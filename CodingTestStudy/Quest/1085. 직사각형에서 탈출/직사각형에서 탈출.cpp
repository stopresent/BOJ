#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int minDistance = 1000;

	if (x < minDistance) minDistance = x;
	if ((w - x) < minDistance) minDistance = w - x;
	if (y < minDistance) minDistance = y;
	if ((h - y) < minDistance) minDistance = h - y;

	cout << minDistance;
}
