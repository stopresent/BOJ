#include <iostream>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	
	int A[]={1,2,3,4,5,6};
	int A_reward[]={500,300,200,50,30,10};
	int B[]={1,2,4,8,16};
	int B_reward[]={512,256,128,64,32};	
	
	cin >> N;
	for(int i=0; i<N; i++){
		int a,b;
		cin >> a >> b;
		int res=0;
		int rA=0,rB=0;
		
		
		for(int j=0; j<sizeof(A)/sizeof(A[0]); j++){
			rA+=A[j];
			if(a<=rA && a!=0){
				res+=A_reward[j];
				break;
			}
		}
		
		for(int j=0; j<sizeof(B)/sizeof(B[0]); j++){
			rB+=B[j];
			if(b<=rB && b!=0){
				res+=B_reward[j];
				break;	
			}			
		}
		
		cout << res*10000 <<"\n";
	}
	return 0; 
}