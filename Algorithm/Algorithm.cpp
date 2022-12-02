#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

/*

2750�� �� �����ϱ�

	����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1 
5
5
2
3
4
1

���� ��� 1 
1
2
3
4
5

*/

int n;
vector<int> nums;

void MySort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i] < v[j])
			{
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		nums.push_back(number);
	}

	MySort(nums);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
}