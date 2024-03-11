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

const int MOD = 1234567891;
int n;

void solve()
{
    int n;
    long long hash = 0, R = 1;
    string str;

    cin >> n >> str;

    for (int i = 0; i < str.length(); i++) 
    {
        hash += ((str[i] - 'a' + 1) * R) % MOD; 
        hash %= MOD;

        R = (R * 31) % MOD;
    }
    cout << hash;
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