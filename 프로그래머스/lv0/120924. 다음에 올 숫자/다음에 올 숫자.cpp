#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    bool flag = false; // 등차면 false, 등비면 true
    int temp = 0;
    if (common[2] - common[1] == common[1] - common[0]) { flag = false; temp = common[1] - common[0]; }
    else { flag = true; temp = common[2] / common[1]; }
    
    if (flag)
    {
        answer = common[common.size() - 1] * temp;
    }
    else
    {
        answer = common[common.size() - 1] + temp;
    }
    
    return answer;
}