#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 150001
#define LL long long
#define INF 1e9

using namespace std;
int A, B, C, N;
unordered_map<string, LL> UM[3];
LL ACost = 0, BCost = 0;
int Special = 0;
bool Answer = true;

void Input() {
	cin >> A >> B >> C;
	for (int i = 0; i < A; i++) {
		string S;
		LL D;
		cin >> S >> D;
		UM[0].insert(make_pair(S, D));
	}
	for (int i = 0; i < B; i++) {
		string S;
		LL D;
		cin >> S >> D;
		UM[1].insert(make_pair(S, D));
	}
	for (int i = 0; i < C; i++) {
		string S;
		cin >> S;
		UM[2].insert(make_pair(S, 0));
	}
}

void Settings() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		if (UM[0].find(S) != UM[0].end()) { // 일반 메뉴면 조건 없이 주문 가능
			ACost += UM[0][S];
		}
		else if (UM[1].find(S) != UM[1].end()) { // 특별 메뉴면 20,000원 이상 주문해야 주문 가능
			BCost += UM[1][S];
		}
		else if (UM[2].find(S) != UM[2].end()) { // 서비스 메뉴면 50,000원 이상 주문해야 하고 하나만 주문 가능
			Special++;
		}
	}
}

void Find_Answer() {
	if (ACost >= 20000) {
		if (ACost + BCost >= 50000) {
			if (Special <= 1) {
				cout << "Okay\n";
			}
			else {
				cout << "No\n";
			}
		}
		else {
			if (Special >= 1) {
				cout << "No\n";
			}
			else {
				cout << "Okay\n";
			}
		}
	}
	else {
		if ((BCost > 0) || (Special >= 1)) {
			cout << "No\n";
		}
		else {
			cout << "Okay\n";
		}
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}