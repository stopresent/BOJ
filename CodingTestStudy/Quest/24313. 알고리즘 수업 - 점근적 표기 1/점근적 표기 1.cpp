#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int a1, a0, c, n0;

int main()
{
	cin >> a1 >> a0 >> c >> n0;

	// a1 이 양수일 경우
	if (a1 > 0)
	{
		// c가 a1보다 크거나 같고, g(n)과 f(n)의 접점 이상에서 정의역이 생성될 경우 1
		if ((c >= a1) && (n0 >= (a0 / (float)(c - a1))))
		{
			cout << 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}

	// a1 이 0일 경우
	if (a1 == 0)
	{
		// 정의역이 접점 이상이여야 하므로
		// n0가 a0보다 크거나 같아야한다.
		if (n0 >= (a0 / (float)c))
		{
			cout << 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}

	// a1 이 음수일 경우
	if (a1 < 0)
	{
		// 언젠가는 무조건 g(n)이 f(n)보다 커진다.
		// 그래서 이것 역시 정의역이 접점 이상이면 된다.
		if ((n0 >= (a0 / (float)(c - a1))))
		{
			cout << 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
}
