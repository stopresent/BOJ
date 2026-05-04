#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int num = 0;
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
        {
            num *= 10;
            num += (my_string[i] - '0');
        }
        else
        {
            answer += num;
            num = 0;
        }
    }
    if (num)
        answer += num;
    return answer;
}