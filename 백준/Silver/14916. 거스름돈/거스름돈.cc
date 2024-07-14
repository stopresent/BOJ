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
    int n;
    cin >> n;
    int start = n / 5; 
    int remain = (n - start * 5) % 2;
    while (remain != 0) 
    {
        if (start == 0) 
        {
            cout << -1;
            return;
        }
        start -= 1;
        remain = (n - start * 5) % 2;
    }
    cout << start + (n - start * 5) / 2;
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