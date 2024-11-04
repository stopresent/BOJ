#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string JH_basis, JH_key, Ian_basis, Ian_measure;
    cin >> JH_basis >> JH_key >> Ian_basis >> Ian_measure;

    string new_key = "";

    for (int i = 0; i < n; ++i) {
        if (JH_basis[i] == Ian_basis[i]) {
            if (JH_key[i] != Ian_measure[i]) {
                cout << "htg!";
                return;
            }
            new_key += JH_key[i];
        }
    }

    cout << new_key;
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