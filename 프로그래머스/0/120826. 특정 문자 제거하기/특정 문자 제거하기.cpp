#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    const char c = letter[0];
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] == c) continue;
        answer += my_string[i];
    }
    return answer;
}