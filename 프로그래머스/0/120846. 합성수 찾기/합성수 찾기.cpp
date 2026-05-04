#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            v[j]++;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (v[i] >= 3) answer++;
    }
    return answer;
}