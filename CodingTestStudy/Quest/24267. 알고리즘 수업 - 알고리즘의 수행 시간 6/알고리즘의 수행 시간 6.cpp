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

long long n;

int main()
{
	cin >> n;

	cout << (n - 2) * (n - 1) * (n) / 6 << endl;
	cout << 3;
}
