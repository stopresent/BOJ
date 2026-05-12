#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long start = times[0] * (n / times.size());
    long long end = times.back() * (n / times.size());
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long cnt = 0;
        
        for (int i = 0; i < times.size(); ++i)
        {
            cnt += mid / times[i];
        }
        
        if (cnt < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return start;
}