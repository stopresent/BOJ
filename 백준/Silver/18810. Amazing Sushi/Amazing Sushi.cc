#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // 초밥 종류의 수 입력 받기
    
    int x1, y1;
    cin >> x1 >> y1; // Mary가 먹을 수 있는 초밥 범위 입력 받기
    
    int x2, y2;
    cin >> x2 >> y2; // Marty가 먹을 수 있는 초밥 범위 입력 받기
    
    vector<int> sushi(n);
    int totalPieces = 0;
    
    // 각 종류의 초밥 조각 수 입력받기
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
        totalPieces += sushi[i]; // 전체 초밥 조각 수 계산
    }
    
    // 전체 초밥 조각 수가 Mary와 Marty의 범위 내에 있는지 확인
    if (totalPieces < x1 + x2 || totalPieces > y1 + y2) {
        cout << "No" << endl;
        return 0;
    }
    
    // Mary가 최소 및 최대 먹을 수 있는 초밥 조각 수 계산
    int maryMin = 0, maryMax = 0;
    
    for (int i = 0; i < n; ++i) {
        maryMin += sushi[i] / 2; // 각 종류의 절반
        maryMax += (sushi[i] + 1) / 2; // 홀수일 경우, 하나 더 추가
    }
    
    int martyMin = totalPieces - maryMax; // Marty가 최소 먹을 수 있는 조각 수
    int martyMax = totalPieces - maryMin; // Marty가 최대 먹을 수 있는 조각 수
    
    // Mary와 Marty가 먹을 수 있는 범위 내에 있는지 확인
    if ((maryMin <= y1 && maryMax >= x1 && martyMin <= y2 && martyMax >= x2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
