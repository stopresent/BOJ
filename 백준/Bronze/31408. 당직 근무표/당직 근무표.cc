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
#include <unordered_map>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<int> duties(N);
    unordered_map<int, int> frequency;

    for (int i = 0; i < N; ++i) 
    {
        cin >> duties[i];
        frequency[duties[i]]++;
    }

    int maxFrequency = 0;
    for (const auto& entry : frequency) 
    {
        maxFrequency = max(maxFrequency, entry.second);
    }

    if (maxFrequency <= (N + 1) / 2) 
    {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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