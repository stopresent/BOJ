#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

// 주어진 벡터에서 가능한 부분 집합의 합을 모두 구하는 함수
void calculateSubsets(const vector<long long>& weights, vector<long long>& subsets) 
{
    int n = weights.size();
    for (int i = 0; i < (1 << n); ++i) 
    {
        long long sum = 0;
        for (int j = 0; j < n; ++j) 
        {
            if (i & (1 << j)) 
            {
                sum += weights[j];
            }
        }
        subsets.push_back(sum);
    }
}

void solve()
{
    int N;
    long long C;
    cin >> N >> C;

    vector<long long> weights(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> weights[i];
    }

    // 물건을 두 그룹으로 나누기
    int mid = N / 2;
    vector<long long> group1(weights.begin(), weights.begin() + mid);
    vector<long long> group2(weights.begin() + mid, weights.end());

    vector<long long> subsets1, subsets2;

    // 각 그룹에서 가능한 부분 집합의 합 계산
    calculateSubsets(group1, subsets1);
    calculateSubsets(group2, subsets2);

    // 두 번째 그룹의 부분 집합 합을 정렬
    sort(subsets2.begin(), subsets2.end());

    long long count = 0;

    // 첫 번째 그룹의 부분 집합 합을 순회하며 가능한 조합을 찾기
    for (const auto& sum1 : subsets1) 
    {
        if (sum1 <= C) 
        {
            // subsets2에서 sum1과 합쳐서 C를 넘지 않는 요소의 개수를 찾기
            count += upper_bound(subsets2.begin(), subsets2.end(), C - sum1) - subsets2.begin();
        }
    }

    cout << count << '\n';
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}