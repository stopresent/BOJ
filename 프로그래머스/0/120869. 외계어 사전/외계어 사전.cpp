#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    
    vector<bool> ch;
    
    for (int i = 0; i < dic.size(); i++)
    {
        ch = vector<bool>(spell.size(), false);
        string str = dic[i];
        
        for (int j = 0; j < str.size(); j++)
        {
            char c = str[j];
            for (int k = 0; k < spell.size(); k++)
            {
                if (*spell[k].c_str() == c)
                {
                    ch[k] = true;
                    break;
                }
            }
        }
        
        bool flag = true;
        for (int k = 0; k < ch.size(); k++)
        {
            if (ch[k] == false)
            {
                flag = false;
                break;
            }
        }
        
        if (flag) return 1;
    }
    return 2;
}