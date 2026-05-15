#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int solution(vector<int> arr) {
    int lcm = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); ++i)
    {
        int temp = arr[i];
        lcm = temp * lcm / gcd(temp, lcm);
    }
    return lcm;
}