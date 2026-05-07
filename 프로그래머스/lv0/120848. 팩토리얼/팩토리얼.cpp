#include <string>
#include <vector>

using namespace std;

int facto(int n)
{
    if (n == 1) return 1;
    return n * facto(n - 1);
}
int arr[11] = { 0, };
int solution(int n) {
    for (int i = 1; i <= 10; i++)
    {
        arr[i] = facto(i);
    }
    for (int i = 10; i >= 1; i--)
    {
        if (n >= arr[i])
            return i;
    }
}