#include <string>
#include <vector>

using namespace std;

int board[14];
int N, answer = 0;
bool check(int row)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == board[row]) return false;
        if (abs(i - row) == abs(board[i] - board[row])) return false;
    }
    return true;
}

void backtracking(int row)
{
    if (row == N)
    {
        answer++;
        return;
    }
    
    for (int i = 0; i < N; i++)
    {
        board[row] = i;
        if (check(row))
        {
            backtracking(row + 1);
        }
    }
}

int solution(int n) {
    N = n;
    backtracking(0);
    
    return answer;
}