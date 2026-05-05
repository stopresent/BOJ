#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<double> avg;
    for (int i = 0; i < score.size(); i++)
    {
        avg.push_back((score[i][0] + score[i][1]) / 2.0);
    }
    
    for (int i = 0; i < avg.size(); i++)
    {
        int rank = 1;
        double cur = avg[i];
        for (int j = 0; j < avg.size(); j++)
        {
            if (avg[j] > cur) rank++;
        }
        answer.push_back(rank);
    }
    
    return answer;
}