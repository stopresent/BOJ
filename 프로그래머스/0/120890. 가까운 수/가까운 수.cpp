#include <string>
#include <vector>

using namespace std;

int Dist(int a, int b)
{
    int dist = a - b;
    if (dist < 0) dist *= -1;
    return dist;
}

int solution(vector<int> array, int n) {
    int answer = 0, minDist = 200;
    for (int i = 0; i < array.size(); i++)
    {
        int dist = Dist(n, array[i]);
        if (dist == minDist)
        {
            answer = min(answer, array[i]);
        }
        else if (dist < minDist)
        {
            minDist = dist;
            answer = array[i];
        }
    }
    return answer;
}