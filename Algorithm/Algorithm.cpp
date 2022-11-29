#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// ���� ��ȹ�� (DP)
// LIS : Longest Increasing Sequence

// Seq : 1 9 2 5 7
// �κ� ���� : �Ϻ� (0�� �̻�) ���ڸ� ����� ���� ����
// ex ) 1 2 5
// ex ) 1 9 5 7
// �� ���� �κ� ����
// ex ) 1 2 5

// LIS : ���� �� [�� ���� �κ� ����]�� ����
// 1 2 5 7 = ���� 4

vector<int> seq;
int cache[100];

int LIS(int idx)
{
	// ���� ���
	if (idx >= seq.size() - 1)
		return 1;

	// �޸������̼�
	if (cache[idx] != -1)
		return cache[idx];

	// ���� �ذ�
	cache[idx] = 1;

	for (int nextPos = idx + 1; nextPos < seq.size(); nextPos++)
		if (seq[idx] < seq[nextPos])
			cache[idx] = max(cache[idx], LIS(nextPos) + 1);

	return cache[idx];
}

int LIS_Rookiss(int pos)
{
	// ���� ����
	//if (pos == seq.size() - 1)
	//	return 1;

	// ĳ�� Ȯ��
	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	// ���ϱ�

	// �ּ� seq[pos]�� ������ 1���� ����
	ret = 1;

	// ���ϱ�
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS_Rookiss(next));

	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache));

	seq = vector<int>{ 1, 9, 2, 5, 7 };

	int ret = 0;

	for (int i = 0; i < seq.size() - 1; i++)
		ret = max(ret, LIS(i));

	cout << ret << endl;

}