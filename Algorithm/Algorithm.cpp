#include <iostream>
#include <vector>
#include <list>
using namespace std;

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

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;

	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;

	adjacent[3][4] = 5;

	adjacent[5][4] = 5;
}

void Dijikstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discorverd;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	discorverd.push_back(VertexCost{ here, 0 });
	best[here] = here;
	parent[here] = here;

	cout << "Where : " << here << endl;
	cout << "Best Cost : " << best[here] << endl;
	cout << "Parent : " << parent[here] << endl;

	while (discorverd.empty() == false)
	{
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;

		for (auto it = discorverd.begin(); it != discorverd.end(); it++)
		{
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		int cost = bestIt->cost;
		here = bestIt->vertex;
		discorverd.erase(bestIt);

		if (best[here] < cost)
			continue;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == -1)
				continue;

			int nextCost = best[here] + adjacent[here][there];
			if (best[there] < nextCost)
				continue;

			discorverd.push_back(VertexCost{ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;

			cout << "Where : " << there << endl;
			cout << "Best Cost : " << best[there] << endl;
			cout << "Parent : " << parent[there] << endl;
		}
	}

	int a = 3;

}

int main()
{
	CreateGraph();

	Dijikstra(0);

}