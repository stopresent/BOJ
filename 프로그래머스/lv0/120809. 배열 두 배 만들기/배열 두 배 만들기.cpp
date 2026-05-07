#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for (auto& v : numbers)
    {
        v <<= 1;
    }
    return numbers;
}