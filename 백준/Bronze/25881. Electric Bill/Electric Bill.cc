#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r1, r2;
    cin >> r1 >> r2;
    
    int n;
    cin >> n;
    
    while(n--){
        int u;
        cin >> u;
        long long charge;
        if(u <= 1000){
            charge = (long long)u * r1;
        }
        else{
            charge = 1000LL * r1 + (long long)(u - 1000) * r2;
        }
        cout << u << " " << charge << "\n";
    }
}