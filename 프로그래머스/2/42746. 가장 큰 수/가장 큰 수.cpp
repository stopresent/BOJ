#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    string stra = to_string(a);
    string strb = to_string(b);
	return stra + strb > strb + stra;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    if (numbers[0] == 0) return "0";
    
    for (int i = 0; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }

    return answer;
}
