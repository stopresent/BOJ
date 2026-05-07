#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> arr(10004);
    for (int i = 2; i <= n;)
    {
        if (n % i != 0) i++;
        else
        {
            n /= i;
            arr[i]++;
        }
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]) answer.push_back(i);
    }
    return answer;
}