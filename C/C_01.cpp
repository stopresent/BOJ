#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	short x = -7;

	unsigned short y = 65529;

	printf("x = %5d, %08x\n", x, x);
	printf("y = %5d, %08x\n", y, y);

	// char형은 정수형으로도 가능.
	char n = 97;
	printf("n = %d\n", n);
	printf("n + 1 = %d\n", n + 1);

	// unsigned char형은 1바이트 크기의 2진 데이터를 저장할 때 주로 사용.
	unsigned char flags = 0x81;

	char n2 = 128;
	unsigned char red = 300;

	printf("n2 = %d\n", n2);
	printf("red = %d\n", red);

	float n3 = 1.1f;
	printf("%08x %0X %d %0b \n",n3 , n3, n3, n3);

	int weight = 50.5;
	printf("%f", weight);
	//%#02x -> 16진수 출력


	int price = 10;
}
