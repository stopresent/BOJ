#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Point {
	long long x, y;
	bool operator<=(Point const& p1) {
		if (x == p1.x) {
			return y <= p1.y;
		}
		return x <= p1.x;
	}
};

struct Line {
	Point p1, p2;
};

const int INF = 1234567890;
const int MAX = 10000;
// disjoint set 기본 개념
int unf[MAX];
int ch[MAX];

int n;
vector<Line> lines;

int Find(int u)
{
	if (u == unf[u])
		return u;

	return unf[u] = Find(unf[u]);
}

void Merge(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v)
		return;
	unf[v] = u;
}

long long CCW(const Point& p1, const Point& p2, const Point& p3)
{
	long long res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

	// 행렬식을 통해서 구하기
	// int determinant = (p2.x*p3.y - p2.y*p3.x) - \
    //                   (p1.x*p3.y - p1.y*p3.x) + \
    //                   (p1.x*p2.y - p1.y*p2.x);

	if (res > 0)
		return 1;   //반시계
	else if (res < 0)
		return -1;     //시계
	else return 0;
}

bool isCross(Line& l1, Line& l2)
{
	long long std1, std2;

	std1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
	std2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);

	if (std1 <= 0 && std2 <= 0) {
		if (std1 == 0 && std2 == 0) {     //선분이 일직선인 경우
			if (l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
			if (l2.p2 <= l2.p1) swap(l2.p1, l2.p2);

			return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
		}
		else return true;   //일직선이 아니면 교차함
	}
	else return false;  //CCW가 같은 방향이 있으면 
}

void solve()
{
	cin >> n;
	lines = vector<Line>(n + 1);

	long long x1, x2, y1, y2;
	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		lines[i].p1 = { x1, y1 };
		lines[i].p2 = { x2, y2 };
		// 처음은 자기 자신이 그룹의 대장.
		unf[i] = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;

			if (isCross(lines[i], lines[j]))
			{
				// 교차할 경우 그룹에 추가
				Merge(i, j);
			}
		}
	}

	int cnt = 0, maxCnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		ch[Find(i)]++;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (ch[i] == 0)
			continue;

		cnt++;
		maxCnt = max(maxCnt, ch[i]);
	}

	//for (int i = 1; i <= n; ++i)
	//{
	//	cout << unf[i] << " ";
	//}
	//cout << endl;
	//for (int i = 1; i <= n; ++i)
	//{
	//	cout << ch[i] << " ";
	//}
	//cout << endl;

	cout << cnt << '\n';
	cout << maxCnt << '\n';
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}