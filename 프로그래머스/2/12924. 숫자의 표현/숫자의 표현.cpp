#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int l = 1, r = 1, sum = 1;
    while (r != n)
    {
        if (sum == n)
        {
            answer++;
            r++;
            sum += r;
        }
        else if (sum < n)
        {
            r++;
            sum += r;
        }
        else if (sum > n)
        {
            sum -= l;
            l++;
        }
    }
    
    return answer;
}