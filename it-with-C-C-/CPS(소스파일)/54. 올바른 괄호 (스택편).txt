#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	stack<char> s;
	string str;
	cin>>str;
	for(auto x : str){
		if(x=='(') s.push(x);
		else{
			if(s.empty() || s.top()!='('){
				cout<<"NO";
				return 0;
			}
			s.pop();
		}
	}
	if(s.empty()) cout<<"YES";
	else cout<<"NO";
	return 0;
}