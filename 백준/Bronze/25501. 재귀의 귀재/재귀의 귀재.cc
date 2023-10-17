#include <iostream>
#include <algorithm>

using namespace std;

int recursionCount = 1;

int recursion(const string& s, int l, int r)
{
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else
    {
        ++recursionCount;
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const string& s)
{
    return recursion(s, 0, s.size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string inputString;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> inputString;
        int palindrome = isPalindrome(inputString);
        cout << palindrome << " " << recursionCount << "\n";
        recursionCount = 1;
    }
}
