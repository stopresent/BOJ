#include <iostream>
#include <algorithm>

using namespace std;

int nArr[500001];
int mArr[500001];
int ans[500001] = {0,};
int N, M;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nArr[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> mArr[i];
	}

	sort(nArr, nArr + N);

	for (int i = 0; i < M; i++)
	{
		int right = N - 1;
		int left = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nArr[mid] == mArr[i])
			{
				ans[i] = 1;
				break;
			}
			else if (nArr[mid] > mArr[i])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cout << ans[i] << ' ';
	}
}
