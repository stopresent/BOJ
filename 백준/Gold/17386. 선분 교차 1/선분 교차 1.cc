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

struct Point 
{
	double x, y;
	bool operator<=(Point const& p1) 
	{
		if (x == p1.x) 
			return y <= p1.y;

		return x <= p1.x;
	}

	bool operator==(Point const& other)
	{
		return x == other.x && y == other.y;
	}
};

struct Line {
	Point p1, p2;
};

vector<Line> lines;

double CCW(const Point& p1, const Point& p2, const Point& p3)
{
	double res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

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
	double std1, std2;

	std1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
	std2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);

	if (std1 <= 0 && std2 <= 0) 
	{
		if (std1 == 0 && std2 == 0) 
		{     
			//선분이 일직선인 경우
			if (l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
			if (l2.p2 <= l2.p1) swap(l2.p1, l2.p2);

			return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
		}
		else
		{
			return true;   //일직선이 아니면 교차함
		}
	}
	else return false;  //CCW가 같은 방향이 있으면 
}

void solve()
{
	// (x1y2−y1x2)(y3−y4)−(y1−y2)(x3y4−y3x4)
	// (x1−x2)(y3−y4)−(y1−y2)(x3−x4)

	Line lines[2];

	double x11, x22, x33, x44, y11, y22, y33, y44;
	cin >> x11 >> y11 >> x22 >> y22;
	lines[0].p1 = { x11, y11 };
	lines[0].p2 = { x22, y22 };
	cin >> x33 >> y33 >> x44 >> y44;
	lines[1].p1 = { x33, y33 };
	lines[1].p2 = { x44, y44 };

	if (isCross(lines[0], lines[1]))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}