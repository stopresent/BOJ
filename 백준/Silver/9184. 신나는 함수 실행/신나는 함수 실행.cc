#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int a, b, c;

int cache[101][101][101] = { 0, };

int w(int a, int b, int c)
{
    int& ret = cache[a][b][c];

    if (a >= 0 && b >= 0 && c >= 0 && ret != 0)
        return ret;

    if (a <= 0 || b <= 0 || c <= 0)
    {
        //w(a, b, c);
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        //w(a, b, c);
        return ret = w(20, 20, 20);
    }
    if (a < b && b < c)
    {
        //w(a, b, c);
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    
    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

void solve()
{
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}

/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    solve();
    //cin >> a >> b >> c;
    //cout << "w(" << a << ", " << b << ", " << c << ") = ";
    //cout << w(a, b, c) << '\n';

}
