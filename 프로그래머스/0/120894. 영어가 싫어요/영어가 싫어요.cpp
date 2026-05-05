#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        int num = 0;
        if (numbers[i] == 'z')
        {
            num = 0;
            i += 3;
        }
        else if (numbers[i] == 'o')
        {
            num = 1;
            i += 2;
        }
        else if (numbers[i] == 't')
        {
            if (numbers[i + 1] == 'w')
            {
                num = 2;
                i += 2;
            }
            else if (numbers[i + 1] == 'h')
            {
                num = 3;
                i += 4;
            }
        }
        else if (numbers[i] == 'f')
        {
            if (numbers[i + 1] == 'o')
            {
                num = 4;
                i += 3;
            }
            else if (numbers[i + 1] == 'i')
            {
                num = 5;
                i += 3;
            }
        }
        else if (numbers[i] == 's')
        {
            if (numbers[i + 1] == 'i')
            {
                num = 6;
                i += 2;
            }
            else
            {
                num = 7;
                i += 4;
            }
        }
        else if (numbers[i] == 'e')
        {
            num = 8;
            i += 4;
        }
        else if (numbers[i] == 'n')
        {
            num = 9;
            i += 3;
        }
        
        
        answer *= 10;
        answer += num;
    }
    
    return answer;
}