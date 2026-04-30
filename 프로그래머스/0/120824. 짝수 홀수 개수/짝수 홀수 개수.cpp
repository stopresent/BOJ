#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer.resize(2);
    for (int i = 0; i < num_list.size(); i++)
    {
        (num_list[i] & 1) ? answer[1]++ : answer[0]++; 
    }
    return answer;
}