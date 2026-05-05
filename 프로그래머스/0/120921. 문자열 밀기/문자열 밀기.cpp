#include <string>
#include <vector>

using namespace std;

string Push(string str)
{
    string result = "";
    
    result += str[str.size() - 1];
    string sub = str.substr(0, str.size() - 1);
    result += sub;
    return result;
}

int solution(string A, string B) {
    int answer = 0;
    
    for (int i = 0; i < A.size(); i++)
    {
        if (A == B) return i;
        A = Push(A);
    }
    return -1;
}