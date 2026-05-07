#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer(num_list.size() / n);
    int idx = 0, count = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        answer[idx].push_back(num_list[i]);
        if (++count % n == 0) idx++;
    }
    return answer;
}