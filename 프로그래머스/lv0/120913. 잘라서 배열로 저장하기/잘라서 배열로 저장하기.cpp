#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp = "";
    int cnt = 0;
    for (int i = 0; i < my_str.size(); i++)
    {
        temp += my_str[i];
        cnt++;
        cnt %= n;
        if (cnt == 0)
        {
            answer.push_back(temp);
            temp = "";
        }
    }
    if (temp != "")
        answer.push_back(temp);
    return answer;
}