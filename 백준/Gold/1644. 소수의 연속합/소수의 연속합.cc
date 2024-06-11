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

// 에라토스테네스의 체를 이용해 소수를 구하는 함수
vector<int> sieve(int n) 
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) 
    {
        if (is_prime[i]) 
        {
            for (int j = i * i; j <= n; j += i) 
            {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) 
    {
        if (is_prime[i]) 
        {
            primes.push_back(i);
        }
    }
    return primes;
}

// 주어진 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 함수
int countConsecutivePrimeSums(int n) 
{
    vector<int> primes = sieve(n);
    int count = 0;
    int start = 0, end = 0, sum = 0;

    while (end < primes.size()) 
    {
        if (sum < n) 
        {
            sum += primes[end++];
        }
        else if (sum > n) 
        {
            sum -= primes[start++];
        }
        else 
        {
            count++;
            sum += primes[end++];
        }
    }

    while (sum >= n && start < primes.size()) 
    {
        if (sum == n) 
        {
            count++;
        }
        sum -= primes[start++];
    }

    return count;
}

void solve()
{
    int N;
    cin >> N;
    cout << countConsecutivePrimeSums(N) << endl;
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