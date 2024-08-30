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

// 일곱 난쟁이
// 순열 방법

void solve()
{
	int arr[9];
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	do
	{
		int sum = 0;
		for (int i = 0; i < 7; ++i)
			sum += arr[i];
		if (sum == 100)
			break;
	} while (next_permutation(arr, arr + 9));

	for (int i = 0; i < 7; ++i)
		cout << arr[i] << '\n';

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