#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int maxNum = 0, idx = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (maxNum < array[i])
        {
            maxNum = array[i];
            idx = i;
        }
    }
    answer = { maxNum, idx };
    return answer;
}