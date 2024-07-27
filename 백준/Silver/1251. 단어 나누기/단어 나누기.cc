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
    string word;
    cin >> word;
    string best = "z";

    int length = word.length();

    for (int i = 1; i < length - 1; ++i) 
    {
        for (int j = i + 1; j < length; ++j) 
        {
            string part1 = word.substr(0, i);
            string part2 = word.substr(i, j - i);
            string part3 = word.substr(j);

            reverse(part1.begin(), part1.end());
            reverse(part2.begin(), part2.end());
            reverse(part3.begin(), part3.end());

            string candidate = part1 + part2 + part3;

            if (candidate < best) 
            {
                best = candidate;
            }
        }
    }

    cout << best << '\n';
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