#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string str;
long long res = 0;

void solve()
{
    string str;
    cin >> str;

    if (str == "0") {
        cout << "0";
        return;
    }

    string ret = "";
    int temp = str.length() % 3;
    if (temp == 0)
        temp = 3;

    // 첫 번째 그룹 처리
    int val = 0;
    for (int i = 0; i < temp; i++)
    {
        val = val * 2 + (str[i] - '0');
    }
    ret += to_string(val);

    // 나머지 그룹 처리
    for (int i = temp; i < str.length(); i += 3)
    {
        val = 0;
        for (int j = 0; j < 3; j++)
        {
            val = val * 2 + (str[i + j] - '0');
        }
        ret += to_string(val);
    }

    cout << ret;
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