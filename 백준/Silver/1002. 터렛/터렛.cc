#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

struct circle
{
	int x, y, r;
};

using namespace std;
int t;
circle cir1, cir2;

void solve()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> cir1.x >> cir1.y >> cir1.r >> cir2.x >> cir2.y >> cir2.r;
		if (cir1.x == cir2.x && cir1.y == cir2.y && cir1.r == cir2.r)
		{
			cout << -1 << '\n';
			continue;
		}

		float dist = sqrt((cir2.x - cir1.x)* (cir2.x - cir1.x) + (cir2.y - cir1.y) * (cir2.y - cir1.y));
		int dist2 = cir1.r + cir2.r;

		if (dist == dist2)
		{
			cout << 1 << '\n';
		}
		else if (max(cir1.r, cir2.r) == min(cir1.r, cir2.r) + dist)
		{
			cout << 1 << '\n';
		}
		else if (max(cir1.r, cir2.r) > min(cir1.r, cir2.r) + dist)
		{
			cout << 0 << '\n';
		}
		else if (dist < dist2)
		{
			cout << 2 << '\n';
		}
		else if (dist > dist2)
		{
			cout << 0 << '\n';
		}
		
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}