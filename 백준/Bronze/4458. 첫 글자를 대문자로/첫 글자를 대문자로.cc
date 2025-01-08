#include <iostream>
#include <string>
using namespace std;
int main() {
    string k;
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        getline(cin,k);
        
        if ('a' <= k[0] && k[0] <= 'z')
            k[0] -= 32;
        cout << k << '\n';
    }
}