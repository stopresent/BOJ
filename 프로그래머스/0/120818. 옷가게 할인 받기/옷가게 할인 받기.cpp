#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    if (price >= 100000 && price < 300000)
    {
        return price * 95 / 100;
    }
    else if (price >= 300000 && price < 500000)
    {
        return price * 90 / 100;
    }
    else if (price >= 500000)
    {
        return price * 80 / 100;
    }
    
    return price;
}