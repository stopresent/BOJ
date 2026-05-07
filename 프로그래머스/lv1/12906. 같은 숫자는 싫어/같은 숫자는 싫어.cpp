#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (!s.empty() && s.top() != arr[i])
            s.push(arr[i]);
    }
    
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        answer.push_back(t);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}