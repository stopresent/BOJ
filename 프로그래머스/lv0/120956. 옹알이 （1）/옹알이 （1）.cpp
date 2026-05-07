#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];
        if (str == "") continue;
        for (int j = 0; j < str.size();)
        {
            if (str[j] == 'a')
            {
                if (j + 2 >= str.size()) break;
                if (str[j + 1] == 'y' && str[j + 2] == 'a')
                {
                    j += 3;
                }
                else break;
            }
            else if (str[j] == 'y')
            {
                if (j + 1 >= str.size()) break;
                if (str[j + 1] == 'e')
                {
                    j += 2;
                }
                else break;
            }
            else if (str[j] == 'w')
            {
                if (j + 2 >= str.size()) break;
                if (str[j + 1] == 'o' && str[j + 2] == 'o')
                {
                    j += 3;
                }
                else break;
            }
            else if (str[j] == 'm')
            {
                if (j + 1 >= str.size()) break;
                if (str[j + 1] == 'a')
                {
                    j += 2;
                }
                else break;
            }
            else break;
            
            if (j == str.size()) answer++;
        }
    }
    
    return answer;
}