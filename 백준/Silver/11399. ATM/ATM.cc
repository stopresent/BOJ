#include <iostream>
#include <vector>

using namespace std;

int n, s, temp;
vector<int> v;

int main()
{
	cin >> n; // 데이터의 크기

	v.resize(n);

	for (int i = 0; i < n; i++) // 정렬되지 않은 상태로 삽입
	{
		cin >> temp;
		v[i] = temp;
	}

	// 삽입 정렬로 정렬
	int pos, posValue;
	for (int i = 1; i < n; i++)
	{
		posValue = v[i];
		for (pos = i - 1; pos >= 0; pos--)
		{
			if (v[pos] > posValue) v[pos + 1] = v[pos];
			else break;
		}
		v[pos + 1] = posValue;
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += v[j];
		}
	}

	cout << sum;
}
