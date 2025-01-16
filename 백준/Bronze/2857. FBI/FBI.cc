#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	int i = 1;
	bool isFind = false;
	while (i < 6) {
		getline(cin, str);

		if (str.find("FBI") != string::npos) {
			cout << i << ' '; 
			isFind = true;
		}
		i++;
	}

	if (!isFind) cout << "HE GOT AWAY!";
}