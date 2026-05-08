#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    int point = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') point++;
        else point--;
        if (point < 0) return false;
    }
    if (point) return false;
    return true;
}