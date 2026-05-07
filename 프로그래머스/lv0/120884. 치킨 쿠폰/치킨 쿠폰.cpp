#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int cupon = 0;
    while(chicken > 0)
    {
        int temp = chicken % 10;
        chicken /= 10;
        cupon += temp;
        if (cupon >= 10)
        {
            cupon %= 10;
            chicken++;
        }
        answer += chicken;
    }
    return answer;
}