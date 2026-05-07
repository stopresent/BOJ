#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (int i = 0; i < array.size(); i++)
    {
        int temp = array[i];
        while(temp > 0)
        {
            int a = temp % 10;
            temp /= 10;
            if (a == 7) answer++;
        }
    }
    return answer;
}