#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    num1 *= 1000;
    num1 /= num2;
    
    return num1;
}