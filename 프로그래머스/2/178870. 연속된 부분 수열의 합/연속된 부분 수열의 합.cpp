#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = { 0, (int)sequence.size() - 1 };
    int l = 0, r = 0, sum = sequence[0];
    
    while (l < sequence.size() && r < sequence.size())
    {
        if (sum == k)
        {
            if (r - l < answer[1] - answer[0])
            {
                answer[1] = r;
                answer[0] = l;
            }
             sum -= sequence[l++];
        }
        else if (sum < k)
        {
            sum += sequence[++r];
        }
        else if (sum > k)
        {
            sum -= sequence[l++];
        }
    }
    return answer;
}