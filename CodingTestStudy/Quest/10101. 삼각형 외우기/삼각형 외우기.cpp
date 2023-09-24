#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

string _equilateral = "Equilateral";
string _isosceles = "Isosceles";
string _scalene = "Scalene";
string _error = "Error";

int a, b, c;

int main()
{
	cin >> a >> b >> c;

	if (a + b + c != 180)
	{
		cout << _error;
		return 0;
	}

	if (a == b && b == c)
	{
		cout << _equilateral;
		return 0;
	}

	if (a != b && b != c && a != c)
	{
		cout << _scalene;
		return 0;
	}
	else
	{
		cout << _isosceles;
		return 0;
	}
}
