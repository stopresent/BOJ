#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int num = 0, totalNum = 0, totalX = 0;
string solution(string polynomial) {
    string answer = "";
    
    for(int i = 0; i < polynomial.size(); i++)
    {
        if (polynomial[i] == ' ')
        {
            totalNum += num;
            num = 0;
        }
        else if (polynomial[i] >= '0' && polynomial[i] <= '9')
        {
            num *= 10;
            num += polynomial[i] - '0';
        }
        else if (polynomial[i] == 'x')
        {
            if (num == 0) totalX++;
            totalX += num;
            num = 0;
        }
        else if (polynomial[i] == '+')
        {
            
        }
    }
    
    totalNum += num;
    
    string xStr = to_string(totalX);
    if (xStr == "1") xStr = "";
    if (totalNum != 0 && totalX != 0)
    {
        answer = xStr + "x + " +to_string(totalNum);
        cout << totalX << "x + " << totalNum;
    }
    else if (totalNum == 0 && totalX != 0)
    {
        answer = xStr + "x";
        cout << totalX << "x";
    }
    else if (totalNum != 0 && totalX == 0)
    {
        answer = to_string(totalNum);
        cout << totalNum;
    }
    else if (totalNum == 0 && totalX == 0)
    {
        return "";
    }
    
    
    return answer;
}