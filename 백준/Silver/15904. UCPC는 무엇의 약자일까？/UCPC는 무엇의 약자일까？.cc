#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    getline(cin, s); // 입력을 한 줄로 받기

    string target = "UCPC";
    int index = 0;

    for (char ch : s) 
    {
        if (ch == target[index]) 
        {
            index++;
        }
        if (index == target.size()) 
        {
            cout << "I love UCPC" << '\n';
            return;
        }
    }

    cout << "I hate UCPC" << '\n';
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