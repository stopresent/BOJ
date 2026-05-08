#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string solution(string a, string b) {
    string result = "";
    int minSize = min(a.size(), b.size());
    int maxSize = max(a.size(), b.size());
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool flag = false; // 더할때 10넘는지
    for (int i = 0; i < maxSize; i++)
    {
        int num = 0;
        if (flag) num++;
        if (i < a.size())
        {
            num += a[i] - '0';
        }
        if (i < b.size())
        {
            num += b[i] - '0';
        }
        
        if (num >= 10)
        {
            result += to_string(num % 10);
            flag = true;
        }
        else
        {
            result += to_string(num % 10);
            flag = false;
        }
    }
    if (flag) result += "1";
    
    reverse(result.begin(), result.end());
    return result;
}