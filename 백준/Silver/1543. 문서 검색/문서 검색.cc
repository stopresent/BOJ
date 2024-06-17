#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <string>

using namespace std;

int countNonOverlappingOccurrences(const string& document, const string& word) 
{
    int docLength = document.size();
    int wordLength = word.size();
    int count = 0;

    for (int i = 0; i <= docLength - wordLength; ) 
    {
        // 현재 위치에서 검색 단어와 일치하는지 확인
        if (document.substr(i, wordLength) == word) 
        {
            count++;
            // 일치하면, 단어의 길이만큼 이동하여 중복되지 않게 함
            i += wordLength;
        }
        else 
        {
            // 일치하지 않으면, 한 칸 앞으로 이동
            i++;
        }
    }

    return count;
}

void solve()
{
    string document;
    string word;

    // 입력 받기
    getline(cin, document);
    getline(cin, word);

    // 중복되지 않게 최대 몇 번 등장하는지 계산
    int result = countNonOverlappingOccurrences(document, word);

    // 결과 출력
    cout << result << endl;

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