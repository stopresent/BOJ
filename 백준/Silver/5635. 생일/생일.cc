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

struct Student
{
	string name;
	int day;
	int month;
	int year;
};

void solve()
{
	int n;
	cin >> n;

	Student youngest = { "1", 1, 1, 1900 }, oldest = { "1", 31, 12, 2100 };
	vector<Student> students(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> students[i].name;
		cin >> students[i].day;
		cin >> students[i].month;
		cin >> students[i].year;

		if (youngest.year < students[i].year)
			youngest = students[i];
		else if (youngest.year == students[i].year && youngest.month < students[i].month)
			youngest = students[i];
		else if (youngest.year == students[i].year && youngest.month == students[i].month && youngest.day < students[i].day)
			youngest = students[i];

		if (oldest.year > students[i].year)
			oldest = students[i];
		else if (oldest.year == students[i].year && oldest.month > students[i].month)
			oldest = students[i];
		else if (oldest.year == students[i].year && oldest.month == students[i].month && oldest.day > students[i].day)
			oldest = students[i];
	}

	cout << youngest.name << '\n';
	cout << oldest.name << '\n';
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