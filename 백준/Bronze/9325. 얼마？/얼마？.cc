#include <iostream>
using namespace std;

int main() {
	int c, //테스트케이스 개수
    s, //가격
    n, //추가할 옵션개수
    q, //특정 옵션의 개수
    p, //그 옵션의 가격
    price = 0; //가격의 합 (0으로 초기화 해줘야함)
    
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> s;
		price += s;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> q >> p;
			price += q * p;
		}
		cout << price << '\n';
		price = 0;
	}

	return 0;
}