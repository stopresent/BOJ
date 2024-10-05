#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--){
        int a, b, c;
        cin >> a >> b >> c;
        
        int count = 0;
        
        for(int x = 1; x <= a; x++){
            for(int y = 1; y <= b; y++){
                // 미리 x mod y 계산
                int xy = x % y;
                for(int z = 1; z <= c; z++){
                    // y mod z 및 z mod x 계산
                    int yz = y % z;
                    int zx = z % x;
                    
                    if(xy == yz && yz == zx){
                        count++;
                    }
                }
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
