#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 카드 게임

//
// 10 7 5
// 2 5 3 7 8 4 9
// 4 1 1 3 8
// 
// 5 2 3 4 9
//

const int MAX = 5000000;
int n, m, k;
vector<int> cards, enemy;
bool ch[MAX];

void solve()
{
	cin >> n >> m >> k;
	cards = vector<int>(m + 1);
	enemy = vector<int>(k + 1);
	for (int i = 1; i <= m; ++i)
		cin >> cards[i];
	for (int i = 1; i <= k; ++i)
		cin >> enemy[i];

	sort(cards.begin(), cards.end());

	for (int i = 1; i <= k; ++i)
	{
		int left = 1, right = cards.size() - 1, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;

			int value = cards[mid];
			if (enemy[i] < value)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		if (ch[right + 1] == false)
		{
			cout << cards[right + 1] << " ";
			ch[right + 1] = true;
		}
		else
		{
			for (int j = right + 2; j < cards.size(); ++j)
			{
				if (ch[j] == true)
					continue;
				cout << cards[j] << " ";
				ch[j] = true;
				break;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}