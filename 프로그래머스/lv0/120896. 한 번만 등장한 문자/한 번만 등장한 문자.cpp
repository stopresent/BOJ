#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr(26);
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 1)
        {
            answer += ('a' + i);
        }
    }
    return answer;
}