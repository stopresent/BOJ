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
	int kor;
	int eng;
	int math;

	bool operator<(Student& other)
	{
		if (kor == other.kor && eng == other.eng && math == other.math)
		{
			return name < other.name;
		}
		else if (kor == other.kor && eng == other.eng)
		{
			return math > other.math;
		}
		else if (kor == other.kor)
		{
			return eng < other.eng;
		}
		else
		{
			return kor > other.kor;
		}
	}
};

int n;

void solve()
{
	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> students[i].name;
		cin >> students[i].kor;
		cin >> students[i].eng;
		cin >> students[i].math;
	}

	sort(students.begin(), students.end());

	for (int i = 0; i < students.size(); ++i)
	{
		cout << students[i].name << '\n';
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