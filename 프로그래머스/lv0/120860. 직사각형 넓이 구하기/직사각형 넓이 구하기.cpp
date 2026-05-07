#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int maxX = -300, minX = 300, maxY = -300, minY = 300;
    for (int i = 0; i < dots.size(); i++)
    {
        maxX = max(maxX, dots[i][0]);
        minX = min(minX, dots[i][0]);
        maxY = max(maxY, dots[i][1]);
        minY = min(minY, dots[i][1]);
    }
    return (maxX - minX) * (maxY - minY);
}