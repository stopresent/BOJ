#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    sort(sides.begin(), sides.end(), greater<int>());
    //sides[1] + x > sides[0]; // 0 is max
    // sides[0] + sides[1] > x; // 2 is max
    
    answer +=sides[0] - (sides[0] - sides[1]);
    answer += sides[1] - 1;
    
    return answer;
}