#include <string>
#include <vector>

using namespace std;

vector<int> uv(26);
vector<int> lv(26);
string solution(string my_string) {
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        if (isupper(my_string[i]))
        {
            if (uv[my_string[i] - 'A'] == 0)
                answer += my_string[i];
            uv[my_string[i] - 'A']++;
        }
        else 
        {
            if (lv[my_string[i] - 'a'] == 0)
                answer += my_string[i];
            lv[my_string[i] - 'a']++;
        }
        
    }
    return answer;
}