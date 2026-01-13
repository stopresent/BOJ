#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

string s;


int main()
{
	cin >> s;

	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - i - 1]) {
			cout << "0" << endl;
			return 0;
		}
	}

	cout << "1" << endl;
	return 0;

}
