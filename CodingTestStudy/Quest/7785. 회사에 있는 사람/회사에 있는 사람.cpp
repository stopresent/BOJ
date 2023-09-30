#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;
map <string, string> member;
map <string, string, greater<string>> enter_log;

int main() {

    int N;
    string name, state;
    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        cin >> name >> state;
        member.insert({ name, state });

        if (member.find(name) != member.end()) 
        { //member에 있다
            if (state == "enter") 
            {
                enter_log.insert({ name, name });
            }
            else if (state == "leave") 
            {
                enter_log.erase(name);
            }
        }
        else { //member에 없다
            if (state == "enter") 
            {
                enter_log.insert({ name, name });
            }
        }
    }

    for (auto k : enter_log) 
    {
        cout << k.first << '\n';
    }

    return 0;
}