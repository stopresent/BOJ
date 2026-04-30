#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int a = numer1 * denom2 + denom1 * numer2;
    int b = denom1 * denom2;
    int g = gcd(a, b);
    answer.push_back(a / g);
    answer.push_back(b / g);
    
    return answer;
}