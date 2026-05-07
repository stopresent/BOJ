#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;
bool cmp(int a, int b)
{
    if (abs(a - num) == abs(b - num))
        return a > b;
    return abs(a - num) < abs(b - num);
}

vector<int> solution(vector<int> numlist, int n) {
    num = n;
    sort(numlist.begin(), numlist.end(), cmp);
    return numlist;
}