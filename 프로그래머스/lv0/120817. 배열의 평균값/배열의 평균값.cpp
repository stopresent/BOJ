#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int i = 0;
    for (i =0; i < numbers.size(); ++i)
    {
        answer += numbers[i];
    }
    
    answer /= i;
    
    return answer;
}