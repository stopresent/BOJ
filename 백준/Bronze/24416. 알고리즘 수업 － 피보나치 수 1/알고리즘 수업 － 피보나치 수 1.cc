#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <math.h>

using namespace std;

int cache[50] = { 0, };

int recurCount = 0;
int dpCount = 0;

int fib(int n) {
	if (n == 1 || n == 2)
	{
		recurCount++;
		return 1;  //# 코드1
	}
	else return (fib(n - 1) + fib(n - 2));
}


int fibonacci(int n) {
	//f[1] < -f[2] < -1;
	cache[1] = cache[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
		dpCount++;
	}
	return cache[n];
	//for i < -3 to n
		//f[i] < -f[i - 1] + f[i - 2];  # 코드2
		//return f[n];
}

int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	fib(n);
	fibonacci(n);
	cout << recurCount << " " << dpCount;
}
