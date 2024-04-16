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

struct Person
{
	string name;
	int age;
	float weight;
};

void solve()
{
	while (true)
	{
		Person person;
		cin >> person.name >> person.age >> person.weight;

		if (person.name == "#" && person.age == 0 && person.weight == 0)
			break;

		if (person.age > 17 || person.weight >= 80)
		{
			cout << person.name << " Senior" << '\n';
		}
		else
		{
			cout << person.name << " Junior" << '\n';
		}
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