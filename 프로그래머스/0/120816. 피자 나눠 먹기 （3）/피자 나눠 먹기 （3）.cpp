#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    
    answer += (n / slice) + ((n % slice) ? 1 : 0);
    
    return answer;
}