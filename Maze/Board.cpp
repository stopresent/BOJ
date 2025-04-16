#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "DisjointSet.h"

const char* TILE = "  ";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player)
{
	_size = size;
	_player = player;

	GenerateMapByPrim();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);
	ConsoleHelper::SetCursorColor(ConsoleColor::RED);

	for (int y = 0; y < 25; ++y)
	{
		for (int x = 0; x < 25; ++x)
		{
			ConsoleColor color = GetTileColor(Pos{ y, x });
			ConsoleHelper::SetCursorColor(color);

			cout << TILE;
		}
		cout << endl;
	}
}

// Binary Tree  ̷        ˰    
// - Mazes For Programmers
void Board::GenerateMapByBinaryTree()
{
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}

	//               Ȥ    Ʒ          մ   ۾ 
	for (int32 y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (y == _size - 2 && x == _size - 2)
				continue;

			if (y == _size - 2)
			{
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}

			if (x == _size - 2)
			{
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			const int32 randValue = ::rand() % 2;
			if (randValue == 0)
			{
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[y + 1][x] = TileType::EMPTY;
			}
		}
	}
}

void Board::GenerateMapByKruskal()
{
	struct CostEdge
	{
		int cost;
		Pos u;
		Pos v;

		bool operator<(CostEdge& other)
		{
			return cost < other.cost;
		}
	};

	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}

	vector<CostEdge> edges;

	// edges  ĺ         cost       Ѵ 
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			//           ϴ        ĺ 
			if (x < _size - 2)
			{
				const int32 randValue = ::rand() % 100;
				edges.push_back(CostEdge{ randValue, Pos{y, x}, Pos{y, x + 2} });
			}

			//  Ʒ       ϴ        ĺ 
			if (y < _size - 2)
			{
				const int32 randValue = ::rand() % 100;
				edges.push_back(CostEdge{ randValue, Pos{y, x}, Pos{y + 2, x} });
			}
		}
	}

	::sort(edges.begin(), edges.end());

	DisjointSet sets(_size * _size);

	for (CostEdge& edge : edges)
	{
		int u = edge.u.y * _size + edge.u.x;
		int v = edge.v.y * _size + edge.v.x;
		//       ׷  ̸    ŵ (     ׷        Ŭ  ߻  )
		if (sets.Find(u) == sets.Find(v))
			continue;

		//     ׷      ģ  
		sets.Union(u, v);

		//  ʿ      
		int y = (edge.u.y + edge.v.y) / 2;
		int x = (edge.u.x + edge.v.x) / 2;
		_tile[y][x] = TileType::EMPTY;
	}

}

void Board::GenerateMapByPrim()
{
	struct CostEdge
	{
		int cost;
		Pos vtx;

		bool operator<(const CostEdge& other) const
		{
			return cost < other.cost;
		}
	};

	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}

	// edges[u] : u                      
	map<Pos, vector<CostEdge>> edges;

	// edges  ĺ                 Ѵ 
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			//           ϴ        ĺ 
			if (x < _size - 2)
			{
				const int32 randValue = ::rand() % 100;
				Pos u = Pos{ y, x };
				Pos v = Pos{ y, x + 2 };
				edges[u].push_back(CostEdge{ randValue, v });
				edges[v].push_back(CostEdge{ randValue, u });
			}

			//  Ʒ       ϴ        ĺ 
			if (y < _size - 2)
			{
				const int32 randValue = ::rand() % 100;
				Pos u = Pos{ y, x };
				Pos v = Pos{ y + 2, x };
				edges[u].push_back(CostEdge{ randValue, v });
				edges[v].push_back(CostEdge{ randValue, u });
			}
		}
	}

	//  ش         Ʈ        ԵǾ   ֳ ?
	map<Pos, bool> added;
	//                            Ǿ     
	map<Pos, Pos> parent;
	//        ִ  Ʈ                   ,  ش              ּ             
	map<Pos, int32> best;

	//    ͽ Ʈ     ſ      !   !
	// -    ͽ Ʈ    best   [      ]               cost
	// -            best   [Ʈ  ]               cost

	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			best[Pos{ y, x }] = INT32_MAX;
			added[Pos{ y, x }] = false;
		}
	}

	priority_queue<CostEdge> pq;
	const Pos startPos = Pos{ 1, 1 };
	pq.push(CostEdge{ 0, startPos });
	best[startPos] = 0;
	parent[startPos] = startPos;

	while (pq.empty() == false)
	{
		CostEdge bestEdge = pq.top();
		pq.pop();

		//                
		Pos v = bestEdge.vtx;
		//  ̹      Ǿ  ٸ    ŵ
		if (added[v])
			continue;

		//              湮
		added[v] = true;

		//  ʿ      
		{
			int y = (parent[v].y + v.y) / 2;
			int x = (parent[v].x + v.x) / 2;
			_tile[y][x] = TileType::EMPTY;
		}

		//      ߰                            ˻  Ѵ 
		for (CostEdge& edge : edges[v])
		{
			//  ̹   ߰   Ǿ        ŵ
			if (added[edge.vtx])
				continue;

			//  ٸ    η           ĺ     ߰   Ǿ        ŵ
			if (edge.cost > best[edge.vtx])
				continue;

			best[edge.vtx] = edge.cost;
			parent[edge.vtx] = v;
			pq.push(edge);
		}
	}

}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size)
		return TileType::NONE;

	if (pos.y < 0 || pos.y >= _size)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	if (_player && _player->GetPos() == pos)
		return ConsoleColor::YELLOW;

	if (GetExitPos() == pos)
		return ConsoleColor::BLUE;

	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case TileType::EMPTY:
		return ConsoleColor::GREEN;
	case TileType::WALL:
		return ConsoleColor::RED;
	}

	return ConsoleColor::WHITE;
}
