#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int a, b, c, d, e, f;

int main()
{
	cin >> a >> b >> c >> d >> e >> f;

	//float x = (c - (f * b / (float)e)) / (a - (d * b / (float)e));
	//float x = (c * e - f * b) / (float)(a * e - d * b);
	//float y = (c * d - f * a) / (float)(b * d - e * a);

	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if (((a * x + b * y) == c) && ((d * x + e * y) == f))
				cout << x << ' ' << y;
		}
	}

	//cout << x << ' ' << y;
}
