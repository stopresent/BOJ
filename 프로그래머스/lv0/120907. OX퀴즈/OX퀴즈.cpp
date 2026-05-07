#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (int i = 0; i < quiz.size(); i++)
    {
        string str = quiz[i];
        int cnt = 0;
        string A = "", B = "", C = "";
        char oper;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ' ') cnt++;
            if (cnt == 0) A += str[j];
            else if (cnt == 1) oper = str[j];
            else if (cnt == 2) B += str[j];
            else if (cnt == 4) C += str[j];
        }
        
        int a = stoi(A);
        int b = stoi(B);
        int c = stoi(C);
        if (oper == '+' && a + b == c) answer.push_back("O");
        else if (oper == '-' && a - b == c) answer.push_back("O");
        else answer.push_back("X");
    }
    return answer;
}