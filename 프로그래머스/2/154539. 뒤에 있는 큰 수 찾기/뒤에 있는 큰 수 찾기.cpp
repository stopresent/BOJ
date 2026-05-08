#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size() , 0);
    stack<int> st;
    st.push(0);
    
    for (int i = 1; i < numbers.size(); i++)
    {
        while(!st.empty() && numbers[st.top()] < numbers[i])
        {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        answer[st.top()] = -1;
        st.pop();
    }
    
    return answer;
}