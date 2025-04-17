#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<string> canvas;

// (r, c)를 중심으로 높이 n인 별 패턴을 그리는 함수
void Recursive(int r, int c, int n)
{
    if (n == 3)
    {
        // 기본 패턴
        canvas[r][c] = '*';
        canvas[r + 1][c - 1] = '*';
        canvas[r + 1][c + 1] = '*';
        for (int i = -2; i <= 2; ++i)
        {
            canvas[r + 2][c + i] = '*';
        }
        return;
    }

    int half = n / 2;

    // 위쪽 작은 패턴
    Recursive(r, c, half);
    // 왼쪽 아래 작은 패턴
    Recursive(r + half, c - half, half);
    // 오른쪽 아래 작은 패턴
    Recursive(r + half, c + half, half);
}

void solve()
{
    int N;
    cin >> N;
    int width = 2 * N - 1;
    // 캔버스를 공백으로 초기화
    canvas.assign(N, string(width, ' '));

    // (0, N-1)을 중심으로 높이 N짜리 패턴 그리기
    Recursive(0, N - 1, N);

    // 결과 출력
    for (int i = 0; i < N; ++i)
    {
        cout << canvas[i] << '\n';
    }
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
