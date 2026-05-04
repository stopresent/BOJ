#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int temp = 0;
    bool isMinus = false;
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] == '-')
        {
            isMinus = true;
        }
        else if (my_string[i] == '+')
        {
            isMinus = false;
        }
        else if (my_string[i] == ' ')
        {
            if (isMinus) answer -= temp;
            else answer += temp;
            temp = 0;
        }
        else
        {
            temp *= 10;
            temp += (my_string[i] - '0');
        }
    }
    if (isMinus) answer -= temp;
    else answer += temp;
    
    return answer;
}