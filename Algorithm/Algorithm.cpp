#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// 스패닝 트리
// 간선의 수를 최소화해서, 모든 정점을 연결하려면?
// N개의 정점을 N-1개의 간선으로 연결
// 사이클을 포함하면 안된다

// 프림 (PRIM) MST 알고리즘
// 특징 : 하나의 시작점으로 구성된 트리에 간선을 하나씩 수집하며 진행
// 특징 : 다익스트라와 유사하다!
// 다익스트라는 시작점을 기준 최단 cost
// 프림은 트리 (정점 집합)을 기준 최단 cost

class DisjointSet
{
public:

	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	int Find(int n)
	{
		if (n == _parent[n])
			return n;

		return _parent[n] = Find(_parent[n]);
	}

	void Union(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;

	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[3][5] = adjacent[5][3] = 10;
	adjacent[4][5] = adjacent[5][4] = 5;
}

struct CostEdge
{
	int cost;
	int u;
	int v;

	bool operator<(CostEdge& other)
	{
		return cost < other.cost;
	}
};

int Kruskal(vector<CostEdge>& selected)
{
	int ret = 0;

	selected.clear();

	vector<CostEdge> edges;

	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent[u].size(); v++)
		{
			if (u > v)
				continue;

			int cost = adjacent[u][v];
			if (cost == -1)
				continue;

			edges.push_back(CostEdge{ cost, u, v });
		}
	}

	::sort(edges.begin(), edges.end());

	DisjointSet sets(vertices.size());

	for (CostEdge& edge : edges)
	{
		// 같은 그룹이면 스킵 ( 안 그러면 사이클 발생 )
		if (sets.Find(edge.u) == sets.Find(edge.v))
			continue;

		// 두 그룹을 합친다
		sets.Union(edge.u, edge.v);
		selected.push_back(edge);
		ret += edge.cost;
	}

	return ret;
}

int main()
{
	CreateGraph();

	vector<CostEdge> selected;
	int cost = Kruskal(selected);

}