#include <iostream>
#include <algorithm>

using namespace std;

int Divide(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return Divide(y, x % y);
}

int ax, ay, bx, by;

int main()
{
	cin >> ax >> ay >> bx >> by;

	//int denominator = ay * by / Divide(max(ay, by), min(ay, by));
	//int numerator = denominator / ay * ax + denominator / by * bx;

	int denominator = ay * by;
	int numerator = ax * by + bx * ay;
	int divisor = Divide(denominator, numerator);
	denominator /= divisor;
	numerator /= divisor;

	cout << numerator << ' ' << denominator;
}
