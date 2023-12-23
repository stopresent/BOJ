#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*


1234

234

342

42

24

4


*/


int n;
queue<int> q;

void solve()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
		q.push(i);

	while (q.size() != 1)
	{
		cout << q.front() << " ";
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front();
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}