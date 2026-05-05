#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = { 0, 0 };
    int maxX = board[0] / 2;
    int minX = -board[0] / 2;
    int maxY = board[1] / 2;
    int minY = -board[1] / 2;
    
    for (int i = 0; i < keyinput.size(); i++)
    {
        if (keyinput[i] == "left")
            answer[0] = max(--answer[0], minX);
        else if (keyinput[i] == "right")
            answer[0] = min(++answer[0], maxX);
        else if (keyinput[i] == "up")
            answer[1] = min(++answer[1], maxY);
        else if (keyinput[i] == "down")
            answer[1] = max(--answer[1], minY);
    }
    
    return answer;
}