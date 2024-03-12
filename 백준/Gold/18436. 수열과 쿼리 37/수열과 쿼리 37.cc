#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 세그먼트 트리를 구성하는 함수
void init(vector<int>& tree, vector<int>& arr, int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start] % 2 == 0 ? 1 : 0;
		return;
	}

	int mid = (start + end) / 2;
	init(tree, arr, node * 2, start, mid);
	init(tree, arr, node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 구간 합을 구하는 함수
int query(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(tree, node * 2, start, mid, left, right) +
		query(tree, node * 2 + 1, mid + 1, end, left, right);
}

// 특정 인덱스의 값을 변경하는 함수
void update(vector<int>& tree, int node, int start, int end, int index, int value) {
	if (index < start || index > end)
		return;

	if (start == end) {
		tree[node] = value % 2 == 0 ? 1 : 0;
		return;
	}

	int mid = (start + end) / 2;
	update(tree, node * 2, start, mid, index, value);
	update(tree, node * 2 + 1, mid + 1, end, index, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void solve()
{
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 세그먼트 트리의 크기를 저장하는 변수
	int treeSize = 1;
	while (treeSize < N)
		treeSize *= 2;

	// 세그먼트 트리를 저장하는 배열
	vector<int> tree(treeSize * 2);

	// 세그먼트 트리 초기화
	init(tree, arr, 1, 0, N - 1);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int queryType;
		cin >> queryType;

		if (queryType == 1) {
			int index, value;
			cin >> index >> value;
			update(tree, 1, 0, N - 1, index - 1, value);
		}
		else if (queryType == 2) {
			int left, right;
			cin >> left >> right;
			cout << query(tree, 1, 0, N - 1, left - 1, right - 1) << '\n';
		}
		else if (queryType == 3) {
			int left, right;
			cin >> left >> right;
			cout << (right - left + 1) - query(tree, 1, 0, N - 1, left - 1, right - 1) << '\n';
		}
	}
}

int main() 
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}