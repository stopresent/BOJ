#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    sort(array.begin(), array.end());
    return array[array.size() / 2];
    return answer;
}