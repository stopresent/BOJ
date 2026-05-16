#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<string> gems) {
    set<string> s(gems.begin(), gems.end());
    int size = s.size();
    unordered_map<string, int> um;
    int left = 0, bestL = 0, bestR = gems.size() - 1;
    for (int right = 0; right < gems.size(); right++)
    {
        um[gems[right]]++;
        
        while (um.size() == size)
        {
            if (right - left < bestR - bestL)
            {
                bestL = left;
                bestR = right;
            }
            
            um[gems[left]]--;
            if (um[gems[left]] == 0)
                um.erase(gems[left]);
            left++;
        }
    }
    return { bestL + 1, bestR + 1 };
}