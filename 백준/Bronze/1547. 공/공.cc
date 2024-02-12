#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

void solve();

void solve()
{
    int A, B, M;
    int arr[3]={1, 2, 3};
    
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        swap(arr[A-1], arr[B-1]);
    }

    for(int i=0; i<3; i++){
        if(arr[i]==1) cout<<i+1;
    }
}
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}