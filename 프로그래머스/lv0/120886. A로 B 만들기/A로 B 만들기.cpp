#include <string>
#include <vector>

using namespace std;
vector<int> v1(26);
vector<int> v2(26);
int solution(string before, string after) {
    for (int i = 0; i < before.size(); i++)
    {
        v1[before[i] - 'a']++;
        v2[after[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] != v2[i])
            return 0;
    }
    return 1;
}