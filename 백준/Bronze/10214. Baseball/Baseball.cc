#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int y, k; cin >> y >> k;
		for (int i = 0; i < 9; i++) {
			int a, b; cin >> a >> b;
			y += a, k += b;
		}
		if (y > k) cout << "Yonsei\n";
		else if (k > y) cout << "Korea\n";
		else cout << "Draw\n";
	}
}