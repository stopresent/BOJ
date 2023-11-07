#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n, m, r, c, d;
int totalCount = 0;

struct Pos
{
public:
	bool operator==(Pos& other)
	{
		return y == other.y && x == other.x;
	}

	bool operator!=(Pos& other)
	{
		return !(*this == other);
	}

	bool operator<(const Pos& other) const
	{
		if (y != other.y)
			return y < other.y;
		return x < other.x;
	}

	bool operator>(const Pos& other) const
	{
		if (y != other.y)
			return y > other.y;
		return x > other.x;
	}

	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}

	Pos& operator+=(Pos& other)
	{
		y += other.y;
		x += other.x;
		return *this;
	}

	int y;
	int x;
};

vector<vector<int>> room;

void makeRoom()
{
	cin >> n >> m;
	cin >> r >> c >> d;
	room = vector<vector<int>>(n, vector<int>(m));

	int v;
	for (int ry = 0; ry < n; ++ry)
	{
		for (int rx = 0; rx < m; ++rx)
		{
			cin >> v;
			room[ry][rx] = v;
		}
	}
}

bool canGo(Pos pos)
{
	return room[pos.y][pos.x] != 1;
}

// 현재 위치에서 주변에 청소할 곳이 있는지 확인한다.
// true면 청소할 곳이 존재한다.
bool checkArea(Pos pos)
{
	if (pos.y - 1 >= 0 && room[pos.y - 1][pos.x] == 0)
		return true;
	if (pos.x + 1 < m && room[pos.y][pos.x + 1] == 0)
		return true;
	if (pos.y + 1 < n && room[pos.y + 1][pos.x] == 0)
		return true;
	if (pos.x - 1 >= 0 && room[pos.y][pos.x - 1] == 0)
		return true;

	return false;
}

void cleaning()
{
	Pos pos = {r, c};

	Pos front[4] =
	{
		Pos {-1, 0}, // UP
		Pos { 0, 1}, // RIGHT
		Pos { 1, 0}, // DOWN
		Pos { 0,-1}, // LEFT
	};

	Pos back[4] =
	{
		Pos { 1, 0}, // DOWN
		Pos { 0,-1}, // LEFT
		Pos {-1, 0}, // UP
		Pos { 0, 1}, // RIGHT
	};

	while (true)
	{
		// 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (room[pos.y][pos.x] == 0)
		{
			totalCount++;
			room[pos.y][pos.x] = 2; // 청소한 칸은 2
		}
		// 4칸 중 청소되지 않은 빈 칸이 없는 경우
		else if (!checkArea(pos))
		{
			// 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
			if (canGo(pos + back[d]))
			{
				pos = pos + back[d];
			}
			// 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
			else
			{
				cout << totalCount;
				break;
			}
		}
		// 반 시계 방향으로 90도 회전한다.
		else
		{
			d = (d - 1 + 4) % 4;
			// 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
			if (canGo(pos + front[d]) && room[(pos + front[d]).y][(pos + front[d]).x] == 0)
			{
				pos = pos + front[d];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	makeRoom();
	cleaning();
}
