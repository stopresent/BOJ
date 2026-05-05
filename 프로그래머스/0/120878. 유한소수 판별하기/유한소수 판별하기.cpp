#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(int a, int b) {
    
    int g = gcd(a, b);
    b /= g;
    
    while (true)
    {
        if (b % 2 != 0) break;
        b /= 2;
    }
    
    while (true)
    {
        if (b % 5 != 0) break;
        b /= 5;
    }
    
    if (b == 1) return 1;
    else return 2;
}