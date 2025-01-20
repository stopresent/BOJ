#include <iostream>
#include <cmath>
using namespace std;
double n, w, h, s;
int main() {
    cin >> n >> w >> h;
    while (n--)
    {
        cin >> s;
        if (s <= w || s <= h || s <= sqrt(w*w + h*h))
        {
            cout << "DA" << '\n';
        }
        else
            cout << "NE" << '\n';
    }
}