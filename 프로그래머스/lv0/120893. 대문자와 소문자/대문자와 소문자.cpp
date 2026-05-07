#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    int dist = 'a' - 'A';
    for (char c : my_string)
    {
        if (c >= 'a' && c <= 'z') answer += (c - dist);
        else answer += (c + dist);
    }
    return answer;
}