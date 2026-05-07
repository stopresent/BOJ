#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int ten = hp / 10;
    answer += ten * 10 / 5;
    int one = hp % 10;
    int three = one / 3;
    answer += three;
    answer += (one - (three * 3));
    return answer;
}