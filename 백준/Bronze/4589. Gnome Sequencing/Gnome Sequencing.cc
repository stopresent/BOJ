#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << "Gnomes:" << endl;

    for (int i = 0; i < n; i++)
    {
        vector<int> v(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> v[j];
        }

        if ((v[0] <= v[1] && v[1] <= v[2]) || (v[0] >= v[1] && v[1] >= v[2]))
        {
            cout << "Ordered" << endl;
        }
        else
        {
            cout << "Unordered" << endl;
        }
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