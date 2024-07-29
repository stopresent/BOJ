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

struct Student
{
	int index;
	int vote;

	bool operator<(Student& other)
	{
		return vote < other.vote;
	}
	bool operator>(Student& other)
	{
		return vote > other.vote;
	}
};

bool cmp(Student& oner, Student& other)
{
	return oner.index < other.index;
}

int n, recommend;

void solve()
{
	cin >> n >> recommend;
	vector<Student> students;

	int index, total = 0;
	for (int i = 0; i < recommend; ++i)
	{
		cin >> index;

		if (students.size() < n)
		{
			bool flag = false;
			for (int j = 0; j < students.size(); ++j)
			{
				if (students[j].index == index)
				{
					flag = true;
					students[j].vote++;
					break;
				}
			}

			if (flag == false)
			{
				students.push_back({ index, 1 });
			}
		}
		else
		{
			bool flag = false;
			for (int j = 0; j < students.size(); ++j)
			{
				if (students[j].index == index)
				{
					flag = true;
					students[j].vote++;
					break;
				}
			}

			if (flag == false)
			{
				int min_vote = INT_MAX;
				int min_index = 0;
				int deleteIndex = 0;
				for (int j = 0; j < students.size(); ++j)
				{
					int voteCount = students[j].vote;
					if (voteCount < min_vote)
					{
						min_vote = voteCount;
						min_index = students[j].index;
						deleteIndex = j;
					}
				}

				students.erase(students.begin() + deleteIndex);
				students.push_back({ index, 1 });
			}
		}
	}

	sort(students.begin(), students.end(), cmp);

	for (int i = 0; i < students.size(); ++i)
	{
		cout << students[i].index << " ";
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