#include <string>
#include <vector>

using namespace std;
char c[] = { 'a', 'e', 'i', 'o', 'u' };
string solution(string my_string) {
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (c[j] == my_string[i])
            {
                flag = false;
                break;
            }
        }
        
        if (flag) answer += my_string[i];
    }
    return answer;
}