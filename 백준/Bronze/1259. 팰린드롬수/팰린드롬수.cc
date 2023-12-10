#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() 
{
	string N;
	
    //0이 아니면 무한 반복
    while (N!="0") 
    {
        cin >> N;
        string buf =N;
        reverse(N.begin(), N.end()); // 앞 뒤 바꿈
        if (N=="0") 
        { 
            // 즉시 탈출 (왜냐하면 0도 reverse하면 0으로 같다.)
            break;
        }
        else if(N == buf) 
        { // 비교
            cout <<"yes\n";
        }
        else 
        {
            cout <<"no\n";
        }
    } 
}