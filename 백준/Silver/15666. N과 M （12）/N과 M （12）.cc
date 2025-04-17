#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
set<int> s;
vector<int> v;
vector<int> indexes;

void SetOrim(vector<int>& index)
{
	int size = index.size();
	for (int i = size - 1; i > 0; --i)
	{
		if (index[i] > index[i - 1])
			index[i - 1] = index[i];
	}
}

void solve()
{
	cin >> N >> M;
	int num;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		s.insert(num);
	}

	for (auto i = s.begin(); i != s.end(); i++)
	{
		v.push_back(*i);
	}

	// indexes[0]이 1의 자리 수.
	sort(v.begin(), v.end());
	indexes.assign(M, 0);
	int size = v.size();
	bool flag = false;
	while (indexes[M - 1] <= size - 1)
	{
		for (int i = 0; i < M; ++i)
		{
			if (i + 1 == M) continue;
			if (indexes[M - 1] == size)
			{
				flag = true;
				break;
			}

			for (int j = 0; j < M; ++j)
			{
				if (indexes[M - 1] == size)
				{
					flag = true;
					break;
				}

				if (j + 1 == M)
				{
					break;
				}

				// 자리 수 올리기
				if (indexes[j] >= size)
				{
					indexes[j] = 0;
					indexes[j + 1]++;
				}
			}

			SetOrim(indexes);

		}

		if (flag) break;

		for (int i = M - 1; i >= 0; --i)
		{
			int index = indexes[i];
			cout << v[index] << " ";
		}
		cout << '\n';
		indexes[0]++;
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