#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n + 1);
    for (int i = 2; i <= n; i++)
        v[i] = i;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i] == 0) continue;
        for (int j = i + i; j <= n; j += i)
        {
            v[j] = 0;
        }
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (v[i] != 0) answer++;
    }
    return answer;
}