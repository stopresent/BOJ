#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> path;
void hanoi(int n, int from, int via, int to)
{
    if (n == 0)
        return;

    hanoi(n - 1, from, to, via);
    path.push_back({from, to});
    hanoi(n - 1, via, from, to);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return path;
}