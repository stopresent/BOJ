#include <bits/stdc++.h>
using namespace std;

// 최대 노드 수 (A-Z)
const int MAX = 26;

// 왼쪽과 오른쪽 자식을 저장할 배열
int left_child[MAX], right_child[MAX];

// 전위 순회 결과를 저장할 문자열
string preorder_result = "";
// 중위 순회 결과를 저장할 문자열
string inorder_result = "";
// 후위 순회 결과를 저장할 문자열
string postorder_result = "";

// 전위 순회: 루트 -> 왼쪽 -> 오른쪽
void preorder(int node) {
    if (node == -1) return;
    // 현재 노드 방문
    preorder_result += char('A' + node);
    // 왼쪽 자식 방문
    preorder(left_child[node]);
    // 오른쪽 자식 방문
    preorder(right_child[node]);
}

// 중위 순회: 왼쪽 -> 루트 -> 오른쪽
void inorder(int node) {
    if (node == -1) return;
    // 왼쪽 자식 방문
    inorder(left_child[node]);
    // 현재 노드 방문
    inorder_result += char('A' + node);
    // 오른쪽 자식 방문
    inorder(right_child[node]);
}

// 후위 순회: 왼쪽 -> 오른쪽 -> 루트
void postorder(int node) {
    if (node == -1) return;
    // 왼쪽 자식 방문
    postorder(left_child[node]);
    // 오른쪽 자식 방문
    postorder(right_child[node]);
    // 현재 노드 방문
    postorder_result += char('A' + node);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 모든 자식을 초기화 (-1: 자식 없음)
    for(int i=0; i<MAX; i++){
        left_child[i] = -1;
        right_child[i] = -1;
    }
    
    // 트리 구성
    for(int i=0; i<N; i++){
        char parent_char, left_char, right_char;
        cin >> parent_char >> left_char >> right_char;
        int parent = parent_char - 'A';
        
        if(left_char != '.') {
            left_child[parent] = left_char - 'A';
        }
        if(right_char != '.') {
            right_child[parent] = right_char - 'A';
        }
    }
    
    // 전위 순회
    preorder(0); // 'A'는 인덱스 0
    // 중위 순회
    inorder(0);
    // 후위 순회
    postorder(0);
    
    // 결과 출력
    cout << preorder_result << "\n";
    cout << inorder_result << "\n";
    cout << postorder_result;
    
    return 0;
}
