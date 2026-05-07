#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    string id = id_pw[0];
    string pw = id_pw[1];
    for (int i = 0; i < db.size(); i++)
    {
        if (db[i][0] == id && db[i][1] == pw)
        {
            return "login";
        }
        else if (db[i][0] == id && db[i][1] != pw)
        {
            return "wrong pw";
        }
    }
    return "fail";
}