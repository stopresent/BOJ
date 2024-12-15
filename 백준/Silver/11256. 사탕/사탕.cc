#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;

    while (t--) {
        int j, n;
        cin >> j >> n;

        vector <int> box;
        for (int i = 0; i < n; i++) {
            int r, c;
            cin >> r >> c;
            box.push_back(r * c);
        }

        sort(box.begin(), box.end());

        int cnt = 0;
        for (int i = n - 1; i > 0; i--) {
            j -= box[i];
            cnt++;

            if (j <= 0) break;
        }

        cout << cnt << "\n";
    }
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}