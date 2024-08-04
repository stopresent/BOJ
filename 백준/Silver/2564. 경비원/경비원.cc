#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

// 1북 2남 3서 4동

int n, m, shopCount;
// 가로 n, 세로 m

void solve()
{
	cin >> n >> m >> shopCount;
	
	vector<pair<int, int>> shopes(shopCount);
	vector<int> dires(shopCount);
	for (int i = 0; i < shopCount; ++i)
	{
		int dir, dist;
		cin >> dir >> dist;

		switch (dir)
		{
		case 1:
			shopes[i] = { 0, dist};
			break;
		case 2:
			shopes[i] = { m, dist };
			break;
		case 3:
			shopes[i] = { dist, 0 };
			break;
		case 4:
			shopes[i] = { dist, n };
			break;
		default:
			break;
		}

		dires[i] = dir;
	}

	int cDir, cDist;
	cin >> cDir >> cDist;
	pair<int, int> curPos;
	switch (cDir)
	{
	case 1:
		curPos = { 0, cDist };
		break;
	case 2:
		curPos = { m, cDist };
		break;
	case 3:
		curPos = { cDist, 0 };
		break;
	case 4:
		curPos = { cDist, n };
		break;
	default:
		break;
	}

	int ret = 0;

	for (int i = 0; i < shopes.size(); ++i)
	{
		if (cDir == dires[i])
		{
			ret += abs(shopes[i].first - curPos.first) + abs(shopes[i].second - curPos.second);
			continue;
		}

		if (cDir == 1 || cDir == 2)
		{
			if (dires[i] == 1 || dires[i] == 2)
			{
				// 대척점에 있는 경우
				int garo = shopes[i].second;

				int minDist = INT_MAX;
				minDist = min(garo + cDist, minDist);
				minDist = min(n - garo + n - cDist, minDist);

				ret += minDist + m;
			}
			else
			{
				ret += abs(shopes[i].first - curPos.first) + abs(shopes[i].second - curPos.second);
			}
		}
		else if (cDir == 3 || cDir == 4)
		{
			if (dires[i] == 3 || dires[i] == 4)
			{
				// 대척점에 있는 경우

				// 대척점에 있는 경우
				int sero = shopes[i].first;

				int minDist = INT_MAX;
				minDist = min(sero + cDist, minDist);
				minDist = min(m - sero + m - cDist, minDist);

				ret += minDist + n;
			}
			else
			{
				ret += abs(shopes[i].first - curPos.first) + abs(shopes[i].second - curPos.second);

			}
		}
	}

	cout << ret;
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}