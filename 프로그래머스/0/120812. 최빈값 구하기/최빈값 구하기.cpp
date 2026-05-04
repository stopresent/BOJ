#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int solution(vector<int> array) {
    int answer = 0;
    vector<pair<int, int>> arr(1004);
    for (int i = 0; i < array.size(); i++)
    {    
        arr[array[i]].first++;
        arr[array[i]].second = array[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    if (arr[0].first == arr[1].first)
        return -1;
    else
        return arr[0].second;
    return answer;
}