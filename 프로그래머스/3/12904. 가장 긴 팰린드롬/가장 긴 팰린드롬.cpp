#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 1;

	for (int i = 0; i < s.size(); i++)
	{
		int l = i, r = i;
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			answer = max(answer, r - l + 1);
			l--;
			r++;
		}
		// i가 팰린드롬의 가운데라고 가정.

		l = i, r = i + 1;
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			answer = max(answer, r - l + 1);
			l--;
			r++;
		}
	}

	return answer;
}