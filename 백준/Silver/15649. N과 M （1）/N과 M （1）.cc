#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main() {

	// 5P2 출력 하는 코드

	cin >> N >> M;

	vector<int> v;

	for (int i = 0; i < N; i++)
		v.push_back(i + 1);

	int n = v.size();  // 5
	int r = M;

	do
	{
		for (int i = 0; i < r; i++)
			cout << v[i] << " ";
		cout << '\n';

		reverse(v.begin() + r, v.end()); // ✨✨✨

	} while (next_permutation(v.begin(), v.end()));

}