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

// 이전 순열을 찾는 함수
bool PrevPermutation(vector<int>& perm) {
    int n = perm.size();
    int i = n - 1;

    // Step 1: 뒤에서부터 첫 번째 감소하는 요소를 찾음
    while (i > 0 && perm[i - 1] <= perm[i]) 
    {
        i--;
    }

    if (i == 0) 
    {
        return false; // 이전 순열이 없음 (가장 첫 번째 순열)
    }

    // Step 2: perm[i-1]보다 작은 요소를 뒤에서부터 찾음
    int j = n - 1;
    while (perm[j] >= perm[i - 1]) 
    {
        j--;
    }

    // Step 3: i-1 위치의 요소와 j 위치의 요소를 교환
    swap(perm[i - 1], perm[j]);

    // Step 4: i 위치부터 끝까지의 요소를 역순으로 바꿈
    reverse(perm.begin() + i, perm.end());

    return true;
}

void solve()
{
    int N;
    cin >> N; // 순열의 크기 입력 받기
    vector<int> perm(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> perm[i]; // 순열 입력 받기
    }

    // 이전 순열이 존재하면 출력
    if (PrevPermutation(perm)) 
    {
        for (int i = 0; i < N; ++i) 
        {
            cout << perm[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << -1 << endl; // 이전 순열이 없으면 -1 출력
    }

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