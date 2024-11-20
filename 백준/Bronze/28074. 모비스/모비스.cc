#include <bits/stdc++.h>
using namespace std;

int main(){
    // 빠른 입출력을 위해 설정
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    // 알파벳 대문자 빈도수 저장 (A-Z)
    int freq[26] = {0};
    for(char c : s){
        if(c >= 'A' && c <= 'Z'){
            freq[c - 'A']++;
        }
    }
    
    // 필요한 문자 리스트
    string required = "MOBIS";
    bool canMake = true;
    
    for(char c : required){
        if(freq[c - 'A'] < 1){
            canMake = false;
            break;
        }
    }
    
    if(canMake){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
