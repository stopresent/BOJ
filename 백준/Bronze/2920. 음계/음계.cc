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

// c d e f g a b C
// ascending
// descending
// mixed

void solve()
{
	vector<int> v(8);
	bool ascending = false;
	bool descending = false;
	bool mixed = false;
	for (int i = 0; i < 8; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < 7; ++i)
	{
		if (v[i] + 1 == v[i + 1])
			ascending = true;
		else
		{
			ascending = false;
			break;
		}
	}

	if (ascending == true)
	{
		cout << "ascending" << endl;
		return;
	}

	for (int i = 0; i < 7; ++i)
	{
		if (v[i] - 1 == v[i + 1])
			descending = true;
		else
		{
			descending = false;
			break;
		}
	}

	if (descending == true)
	{
		cout << "descending" << endl;
		return;
	}

	cout << "mixed" << endl;
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