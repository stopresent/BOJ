#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int n, answer = 0;
vector<bool> visited;
vector<bool> ch;
void DFS(vector<int> &numbers, int target, int num)
{
    if (visited[num]) return;
    
    if (num == n)
    {
        int sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            //cout << visited[i] << " ";
            int temp;
            if (visited[i]) temp = -1;
            else temp = 1;
            sum += numbers[i] * temp;
        }
        //cout << endl;
        
        if (sum == target) answer++;
        
        return;
    }
    
    visited[num] = true;
    DFS(numbers, target, num + 1);
    
    visited[num] = false;
    DFS(numbers, target, num + 1);
    
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    visited = vector<bool>(numbers.size(), false);
    DFS(numbers, target, 0);
    return answer;
}