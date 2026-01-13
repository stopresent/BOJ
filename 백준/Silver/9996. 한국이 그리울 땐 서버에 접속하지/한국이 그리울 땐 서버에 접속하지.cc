#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string str;

void solve()
{
	cin >> n >> str;
	int idx = str.find('*');
	string sub1 = str.substr(0, idx);
	string sub2 = str.substr(idx + 1);
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp.size() < (sub1.size() + sub2.size()))
		{
			cout << "NE" << '\n';
			continue;
		}
		string tempSub1 = temp.substr(0, sub1.size());
		string tempSub2 = temp.substr(temp.size() - sub2.size());
		if (sub1 == tempSub1 && sub2 == tempSub2)
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
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