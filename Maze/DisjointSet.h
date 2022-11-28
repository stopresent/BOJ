#pragma once

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

