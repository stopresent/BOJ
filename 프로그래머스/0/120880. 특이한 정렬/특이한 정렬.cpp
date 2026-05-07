#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    bool flagA = false, flagB = false;
    if (a < 0) { a *= -1; flagA = true; }
    if (b < 0) { b *= -1; flagB = true; }
    if (a == b) return !flagA;
    return a < b;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    for (int i = 0; i < numlist.size(); i++)
    {
        answer.push_back(numlist[i] - n);
    }
    sort(answer.begin(), answer.end(), cmp);
    for (int i = 0; i < answer.size(); i++)
    {
        answer[i] += n;
    }
    return answer;
}