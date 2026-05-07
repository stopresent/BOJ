#include <string>
#include <vector>
#include <map>
using namespace std;

string str[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
map<string, char> mp;

string solution(string letter) {
    string answer = "";
    
    for (int i = 0; i < 26; i++)
    {
        mp[str[i]] = 'a' + i;
    }
    
    string input = "";
    for (int i = 0; i < letter.size(); i++)
    {
        if (letter[i] != ' ')
            input += letter[i];
        else
        {
            answer += mp[input];
            input = "";
        }
    }
    answer += mp[input];
    return answer;
}