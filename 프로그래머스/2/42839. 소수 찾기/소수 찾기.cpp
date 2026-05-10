#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

set<int> s;
vector<bool> visited;

bool isPrime(int num)
{
	if (num < 2) return false;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(string &numbers, int idx, string str)
{
	if (visited[idx])
		return;
	visited[idx] = true;

	str += numbers[idx];

	// num이 소수면 
	if (str != "" && isPrime(stoi(str)))
		s.insert(stoi(str));

	for (int i = 0; i < numbers.size(); i++)
	{
		if (visited[i] == false)
		{
			DFS(numbers, i, str);
		}
	}
    
    visited[idx] = false;
}

int solution(string numbers) {
    int answer = 0;
	visited = vector<bool>(numbers.size(), false);

	for (int i = 0; i < numbers.size(); i++)
	{
		visited = vector<bool>(numbers.size(), false);
		DFS(numbers, i, "");
	}

	answer = s.size();

    return answer;
}