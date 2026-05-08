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
        // 스택이 비지않고, 스택의 탑 위치의 값보다 현재 수열 값이 클 때까지
        while(!st.empty() && numbers[st.top()] < numbers[i])
        {
            // 정답 수열에 스택의 탑 위치에 오큰수 넣기
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i); // 마지막은 어차피 -1이 들어감.
    }
    
    // 스택에는 오큰수가 없는 위치값만 있음.
    while (!st.empty())
    {
        // 오큰수가 없으니까 -1로 세팅
        answer[st.top()] = -1; 
        st.pop();
    }
    
    return answer;
}