#include <iostream>
using namespace std;

/*
6. 숫자만 추출

문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만듭니다.
만들어진 자연수와 그 자연수의 약수 개수를 출력합니다.
만약 “t0e0a1c2her”에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수를 만들면 12가 됩니다.
즉 첫 자리 0은 자연수화 할 때 무시합니다.
출력은 12를 출력하고, 다음 줄에 12의 약수의 개수를 출력하면 됩니다.
추출하여 만들어지는 자연수는 100,000,000을 넘지 않습니다.

▣ 입력설명
첫 줄에 숫자가 썩인 문자열이 주어집니다. 문자열의 길이는 50을 넘지 않습니다.

▣ 출력설명
첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다.

▣ 입력예제 1
g0en2Ts8eSoft

▣ 출력예제 1
28
6

*/



int main()
{
	string input;
	cin >> input;

	int num = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] >= 48 && input[i] <= 57)
		{
			int a = input[i] - '0';
			if (num == 0 && a == 0) continue;
			cout << a;

			num *= 10;
			num += a;
		}
	}

	cout << endl;

	int count = 0;
	// num 약수 구하기
	for (int i = 1; i <= num; ++i)
		if (num % i == 0) count++;
	cout << count;
}