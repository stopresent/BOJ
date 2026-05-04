#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for (int x = i; x <= j; x++)
    {
        int temp = x;
        while(temp > 0)
        {
            int a = temp % 10;
            temp /= 10;
            if (k == a) answer++;
        }
    }
    return answer;
}