#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    if (str1.size() < str2.size()) return 2;
    
    for (int i = 0; i <= str1.size() - str2.size(); i++)
    {
        string sub = str1.substr(i, str2.size());
        if (sub == str2) 
            return 1;
    }   
    
    return 2;
}