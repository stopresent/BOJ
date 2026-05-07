#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long ret = 1;
    for (int i = 1; i <= share; i++)
    {
        ret *= balls--;
        ret /= i;    
    }
    
    return ret;
}