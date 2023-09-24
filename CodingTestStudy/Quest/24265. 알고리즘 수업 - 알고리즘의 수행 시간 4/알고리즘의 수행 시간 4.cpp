#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

//MenOfPassion(A[], n) {
//    sum < -0;
//    for i < -1 to n - 1
//        for j < -i + 1 to n
//            sum < -sum + A[i] × A[j]; # 코드1
//            return sum;
//} 7 -> 21
// 6 + 5 + 4 + 3 + 2 + 1
long long n;

int main()
{
	cin >> n;

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += i;
	}

	cout << sum << endl;
	cout << 2;
}
