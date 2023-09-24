#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

//MenOfPassion(A[], n) {
//    sum < -0;
//    for i < -1 to n - 2
//        for j < -i + 1 to n - 1
//            for k < -j + 1 to n
//                sum < -sum + A[i] ¡¿ A[j] ¡¿ A[k]; # ÄÚµå1
//                return sum;
//}

int test(int n)
{
	int result = 0;
	for (int i = 1; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			for (int k = j + 1; k <= n; k++)
				result++;
	return result;
}

long long n;

int main()
{
	cin >> n;

	int result = 0;
	for (int i = 1; i <= n - 2; i++)
		result += i;

	result *= n - 2;

	int removal = 0;
	for (int i = n - 2; i >= 2; i--)
	{
		removal += i * (i - 1);
	}
	result -= removal;

	cout << result << endl;
	cout << 3;
}
