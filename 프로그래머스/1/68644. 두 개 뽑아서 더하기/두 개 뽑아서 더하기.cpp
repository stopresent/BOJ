#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int n, r;
vector<int> v;
set<int> s;

void combi(const vector<int> vec, int start, int depth)
{
    if (depth == r)
    {
        int sum = 0;
        for (int a : v)
        {
            sum += vec[a];
        }
        s.insert(sum);
        return;
    }
    
    for (int i = start; i < n; i++)
    {
        v.push_back(i);
        
        combi(vec, i + 1, depth + 1);
        
        v.pop_back();
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    n = numbers.size();
    r = 2;
    combi(numbers, 0, 0);
    
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        answer.push_back(*it);
    }
    sort(answer.begin(), answer.end());

    return answer;
}