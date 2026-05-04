#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(int n) {
    int g;
    if (n > 6) g = gcd(n, 6);
    else g = gcd(6, n);
    return 6 * n / g / 6;
}