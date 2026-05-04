#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int num = 0, prevNum = 0;
    bool isMinus = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'Z')
        {
            answer -= prevNum;
            num = 0;
            isMinus = false;
        }
        else if (s[i] == ' ')
        {
            if (isMinus) num *= -1;
            answer += num;
            prevNum = num;
            num = 0;
            isMinus = false;
        }
        else if (s[i] == '-')
        {
            isMinus = true;
        }
        else
        {
            num *= 10;
            num += (s[i] - '0');
        }
    }
    if (isMinus) num *= -1;
    answer += num;
    return answer;
}