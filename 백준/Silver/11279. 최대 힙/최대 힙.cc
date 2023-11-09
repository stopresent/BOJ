#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n;
vector<int> heap;
vector<int> ans;

void push_heap(vector<int>& heap, int newValue)
{
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx])
	{
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void pop_heap(vector<int>& heap)
{
	if (heap.size() == 0)
	{
		//cout << 0 << '\n';
		ans.push_back(0);
		return;
	}

	//cout << heap[0] << '\n';
	ans.push_back(heap[0]);
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;

	while (true)
	{
		int left = here * 2 + 1, right = here * 2 + 2;

		if (left >= heap.size())
			break;
		int next = here;
		if (heap[next] < heap[left])
			next = left;
		if (right < heap.size() && heap[next] < heap[right])
			next = right;
		if (next == here)
			break;
		swap(heap[here], heap[next]);
		here = next;
	}
}

void solve()
{
	cin >> n;

	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp == 0)
			pop_heap(heap);
		else
			push_heap(heap, temp);
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}