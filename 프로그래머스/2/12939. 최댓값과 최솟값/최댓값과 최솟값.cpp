#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int minNum = 10000000, maxNum = -10000000, num = 0;
    bool isMinus = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (isMinus) num *= -1;
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
            num = 0;
            isMinus = false;
        }
        else if (s[i] == '-') isMinus = true;
        else
        {
            num *= 10;
            num += s[i] - '0';
        }
    }
    if (isMinus) num *= -1;
    minNum = min(minNum, num);
    maxNum = max(maxNum, num);
    answer = to_string(minNum) + " " + to_string(maxNum);
    return answer;
}