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
#include <cmath>
#include <iomanip>

using namespace std;


// 두 직선의 방정식의 계수를 계산하는 함수
void getLineEquation(double x1, double y1, double x2, double y2, double& A, double& B, double& C) 
{
	A = y2 - y1;
	B = x1 - x2;
	C = A * x1 + B * y1;
}

// 두 선분이 교차하는지 확인하는 함수
bool onSegment(double x1, double y1, double x2, double y2, double x, double y) 
{
	return min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2);
}

// 정밀한 출력을 위해 0.00과 -0.00을 구별하는 함수
double correctZero(double val) 
{
    return val == -0.00 ? 0.00 : val;
}

void solve()
{
    int N;
    cin >> N;

    cout << fixed << setprecision(2);

    while (N--) 
    {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        double A1, B1, C1;
        getLineEquation(x1, y1, x2, y2, A1, B1, C1);
        double A2, B2, C2;
        getLineEquation(x3, y3, x4, y4, A2, B2, C2);

        double det = A1 * B2 - A2 * B1;

        if (det == 0) 
        {
            // 두 직선이 평행하거나 일치함을 확인
            if (A1 * x3 + B1 * y3 == C1) 
            {
                // 일치하는 경우
                cout << "LINE" << endl;
            }
            else 
            {
                // 평행한 경우
                cout << "NONE" << endl;
            }
        }
        else 
        {
            // 두 직선이 교차하는 경우
            double x = (B2 * C1 - B1 * C2) / det;
            double y = (A1 * C2 - A2 * C1) / det;

            x = correctZero(x);
            y = correctZero(y);

            cout << "POINT " << x << " " << y << endl;

            //if (onSegment(x1, y1, x2, y2, x, y) && onSegment(x3, y3, x4, y4, x, y)) 
            //{
            //    cout << "POINT " << x << " " << y << endl;
            //}
            //else 
            //{
            //    cout << "NONE" << endl;
            //}
        }
    }
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