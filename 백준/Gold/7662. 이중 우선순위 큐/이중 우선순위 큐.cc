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
#include <queue>
#include <map>

using namespace std;

int t, n;

void solve()
{
	cin >> t;
	while (t--)
	{
		cin >> n;

		priority_queue<long long> pq;
		priority_queue<long long, vector<long long>, greater<long long>> smallest_pq;
		map<int, int> m;
		int input_cnt = 0, output_cnt = 0, total_cnt = 0;;
		for (int i = 0; i < n; ++i)
		{
			char id;
			long long num;
			cin >> id >> num;

			if (id == 'I')
			{
				pq.push(num);
				smallest_pq.push(num);
				input_cnt++;
				total_cnt++;
				m[num]++;
			}
			else if (id == 'D')
			{
				if (output_cnt < input_cnt && num == 1)
				{
					// 최댓값 삭제
					m[pq.top()]--;
					pq.pop();
					output_cnt++;
					total_cnt--;
				}
				else if (output_cnt < input_cnt && num == -1)
				{
					// 최소값 삭제
					m[smallest_pq.top()]--;
					smallest_pq.pop();
					output_cnt++;
					total_cnt--;
				}
			}

			if (total_cnt == 0)
			{
				while (pq.empty() == false)
				{
					pq.pop();
				}

				while (smallest_pq.empty() == false)
				{
					smallest_pq.pop();
				}
			}

			while (pq.empty() == false && m[pq.top()] == 0)
			{
				pq.pop();
			}
			while (smallest_pq.empty() == false && m[smallest_pq.top()] == 0)
			{
				smallest_pq.pop();
			}
		}

		if (input_cnt == output_cnt)
			cout << "EMPTY" << '\n';
		else
		{
			cout << pq.top() << " " << smallest_pq.top() << '\n';
		}
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