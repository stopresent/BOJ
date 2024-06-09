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

// 점 구조체
struct Point 
{
	int x, y;
};

// 두 점을 지나는 직선의 방향을 확인하는 함수
int ccw(Point A, Point B, Point C) 
{
	int cross_product = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

	if (cross_product > 0) return 1;			// 반시계 방향
	else if (cross_product < 0) return -1;		// 시계 방향
	else return 0;  // 일직선
}

void solve()
{
	Point A, B, C;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

	cout << ccw(A, B, C);
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