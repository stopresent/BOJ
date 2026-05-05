#include <string>
#include <vector>

using namespace std;

bool check(int x)
{
    while(x > 0)
    {
        int temp = x % 10;
        if (temp == 3) return true;
        x /= 10;
    }
    return false;
}

int solution(int n) {
    vector<bool> ch(1000, true);
    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || check(i))
        {
            ch[i] = false;
        }
    }
    
    int cnt = 0, answer = 0;
    while(cnt != n)
    {
        if (ch[answer])
        {
            cnt++;
        }
        
        answer++;
    }
    return --answer;
}