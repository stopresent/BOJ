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

void solve()
{
	int a, b;
	cin >> a >> b;
	int dist = b - a;
	if (dist < 1) {
		cout << "Congratulations, you are within the speed limit!";
	}
	else if (dist <= 20) {
		cout << "You are speeding and your fine is $100.";
	}
	else if (dist <= 30) {
		cout << "You are speeding and your fine is $270.";
	}
	else {
		cout << "You are speeding and your fine is $500.";
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