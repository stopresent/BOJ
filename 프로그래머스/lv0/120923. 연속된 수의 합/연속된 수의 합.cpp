#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int sum = 0;
    for (int i = -100; i < -100 + num; i++) sum += i;
    for (int i = -100 + num; i <= 100; i++)
    {
        sum += i;
        sum -= i - num;
        if (sum == total)
        {
            for (int j = i - num + 1; j <= i; j++)
            {
                answer.push_back(j);
            }
                
            return answer;
        }
    }
    
}