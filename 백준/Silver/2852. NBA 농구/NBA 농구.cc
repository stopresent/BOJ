#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, score1, score2, num, total1, total2, curtime;
string s;

int time_to_sec(string s)
{
	int ret = 0;
	string a = s.substr(0, 2);
	ret = ret + (a[0] - '0') * 10 * 60 + (a[1] - '0') * 60;
	a = s.substr(3, 2);
	ret = ret + (a[0] - '0') * 10 + (a[1] - '0');
	return ret;
}

string sec_to_time(int sec) {
	string ret = "";
	int a = sec / 60;
	int b = sec % 60;
	string sub1 = to_string(a);
	string sub2 = to_string(b);
	if (sub1.size() == 1) sub1 = "0" + sub1;
	if (sub2.size() == 1) sub2 = "0" + sub2;
	ret = sub1 + ":" + sub2;
	return ret;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num >> s;
		int time = time_to_sec(s);
		if (score1 > score2) total1 += (time - curtime);
		else if (score1 < score2) total2 += (time - curtime);
		if (num == 1) score1++;
		else score2++;
		curtime = time;
	}
	int time = time_to_sec("48:00");
	if (score1 > score2) total1 += (time - curtime);
	else if (score1 < score2) total2 += (time - curtime);
	cout << sec_to_time(total1) << '\n';
	cout << sec_to_time(total2) << '\n';

}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}