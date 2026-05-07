#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct st
{
    int num;
    int index;
    int order;
};

bool cmp1(st a, st b)
{
    return a.num > b.num;
}

bool cmp2(st a, st b)
{
    return a.index < b.index;
}
vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    int size = emergency.size();
    vector<st> sts(size);
    for (int i = 0; i < emergency.size(); i++)
    {
        sts[i].num = emergency[i];
        sts[i].index = i;
    }
    sort(sts.begin(), sts.end(), cmp1);
    for (int i = 0; i < sts.size(); i++)
    {
        sts[i].order = i + 1;
    }
    sort(sts.begin(), sts.end(), cmp2);
    for (int i = 0; i < sts.size(); i++)
    {
        answer.push_back(sts[i].order);
    }
    return answer;
}