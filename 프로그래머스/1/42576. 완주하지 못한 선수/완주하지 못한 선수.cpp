#include <string>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> m;
    for (const auto& name : participant)
    {
        m[name]++;
    }
    for (const auto& name : completion)
    {
        m[name]--;
    }

    for (const auto& it : m)
    {
        if (it.second != 0)
            return it.first;
    }

}