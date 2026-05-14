#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
	sort(people.begin(), people.end());

	int l = 0, r = people.size() - 1, result = 0;

	while (l <= r)
	{
		if (people[l] + people[r] <= limit)
			l++;

		result++;
		r--;
	}

	return result;
}