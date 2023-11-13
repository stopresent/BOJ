#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 절댓값 힙
// 음수 전용 힙
// 양수 전용 힙

int n;
vector<int> heap; // 양수 힙
vector<int> heap2; // 음수 힙
vector<int> ans; // 양수 힙 답
vector<int> ans2; // 음수 힙 답

void push_heap1(vector<int>& heap, int newValue)
{
	heap.push_back(newValue);
	int idx = heap.size() - 1;

	while (idx > 0 && heap[(idx - 1) / 2] > heap[idx])
	{
		swap(heap[idx], heap[(idx - 1) / 2]);

		idx = (idx - 1) / 2;
	}
}

void push_heap2(vector<int>& heap, int newValue)
{
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx])
	{
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void pop_heap1(vector<int>& heap)
{
	if (heap.size() == 0)
	{
		//ans.push_back(0);
		return;
	}
	//ans.push_back(heap[0]);
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (true)
	{
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size())
			break;
		int next = here;
		if (heap[next] > heap[left])
			next = left;
		if (right < heap.size() && heap[next] > heap[right])
			next = right;
		if (next == here)
			break;
		swap(heap[here], heap[next]);
		here = next;
	}
}

void pop_heap2(vector<int>& heap)
{
	if (heap.size() == 0)
	{
		//ans2.push_back(0);
		return;
	}

	//ans2.push_back(heap[0]);
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
		//heap[i] = temp;
		if (temp == 0)
		{
			if (heap.size() == 0 && heap2.size() == 0)
				ans.push_back(0);
			// ans, ans2 중 절댓값이 작은 수 pop
			else if (heap.size() == 0)
			{
				ans.push_back(heap2[0]);
				//heap2.pop_back();
				pop_heap2(heap2);
			}
			else if (heap2.size() == 0)
			{
				ans.push_back(heap[0]);
				//heap.pop_back();
				pop_heap1(heap);
			}
			else if (heap[0] > abs(heap2[0]))
			{
				ans.push_back(heap2[0]);
				//heap2.pop_back();
				pop_heap2(heap2);
			}
			else if (heap[0] < abs(heap2[0]))
			{
				ans.push_back(heap[0]);
				//heap.pop_back();
				pop_heap1(heap);
			}
			else if (heap[0] == abs(heap2[0]))
			{
				// 절댓값이 같으면 음수 힙 팝
				ans.push_back(heap2[0]);
				//heap2.pop_back();
				pop_heap2(heap2);
			}
		}
		else if (temp > 0)
			push_heap1(heap, temp);
		else
			push_heap2(heap2, temp);
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
