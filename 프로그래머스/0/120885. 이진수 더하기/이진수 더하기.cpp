#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int BinToInt(string str)
{
    int ret = 0, sh = 1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            ret += sh;
        }
        sh <<= 1;
    }
    return ret;
}

string IntToBin(int a)
{
    if (a == 0) return "0";
    string ret = "";
    while(a > 0)
    {
        if (a % 2) ret += "1";
        else ret += "0";
        a /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(string bin1, string bin2) {
    int a = BinToInt(bin1) + BinToInt(bin2);
    
    return IntToBin(a);
}