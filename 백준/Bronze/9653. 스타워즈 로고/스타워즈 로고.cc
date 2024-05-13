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
	cout << "    8888888888  888    88888" << endl;
	cout << "   88     88   88 88   88  88" << endl;
	cout << "    8888  88  88   88  88888" << endl;
	cout << "       88 88 888888888 88   88" << endl;
	cout << "88888888  88 88     88 88    888888" << endl;
	cout << endl;
	cout << "88  88  88   888    88888    888888" << endl;
	cout << "88  88  88  88 88   88  88  88" << endl;
	cout << "88 8888 88 88   88  88888    8888" << endl;
	cout << " 888  888 888888888 88  88      88" << endl;
	cout << "  88  88  88     88 88   88888888" << endl;
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