#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> command = commands[i];
        vector<int> temp(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[command[2] - 1]);
    }
    return answer;
}