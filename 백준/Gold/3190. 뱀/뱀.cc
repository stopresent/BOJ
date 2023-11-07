#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

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
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Pos& operator+=(Pos& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	int y;
	int x;
};

enum Type
{
	NONE,
	BODY,
	APPLE,
	WALL,
	EMPTY,
};

enum Dir
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

// n : 보드의 크기
// k : 사과의 개수
// l : 방향 전환의 수
int n, k, l;
vector<vector<int>> board;
int dir = 1, timeCount = 0;
vector<pair<int, char>> lCache;

void printBoard()
{
	for (int y = 0; y < n + 2; ++y)
	{
		for (int x = 0; x < n + 2; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
}

void gameSetting()
{
	cin >> n >> k;

	board = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

	for (int i = 0; i < n + 2; ++i)
	{
		board[i][0] = Type::WALL;
		board[0][i] = Type::WALL;
		board[i][n + 1] = Type::WALL;
		board[n + 1][i] = Type::WALL;
	}

	int u, v;
	for (int i = 0; i < k; ++i)
	{
		cin >> u >> v;
		board[u][v] = Type::APPLE;
	}

	//printBoard();
}

void dummy()
{
	queue<Pos> body;
	Pos pos = { 1, 1 };

	cin >> l;
	lCache = vector<pair<int, char>>(l);

	int u;
	char v;
	for (int i = 0; i < l; ++i)
	{
		cin >> u >> v;
		lCache[i].first = u;
		lCache[i].second = v;
	}

	Pos front[4] =
	{
		Pos { -1,  0 }, // UP
		Pos {  0,  1 }, // RIGHT
		Pos {  1,  0 }, // DOWN
		Pos {  0, -1 }, // LEFT
	};

	while (true)
	{
		// 방향을 틀어야 되나?
		for (int i = 0; i < lCache.size(); ++i)
		{
			if (lCache[i].first == timeCount)
			{
				if (lCache[i].second == 'L')
				{
					dir = (dir - 1 + 4) % 4;
				}
				else
				{
					dir = (dir + 1) % 4;
				}
			}
		}

		body.push(pos);
		board[pos.y][pos.x] = Type::BODY;

		// 바라보는 방향으로 한칸 이동.
		pos = pos + front[dir];
		timeCount++;
		//cout << pos.y << " " << pos.x << endl;
		//printBoard();

		if (board[pos.y][pos.x] == Type::WALL || board[pos.y][pos.x] == Type::BODY)
		{
			cout << timeCount;
			break;
		}

		// 사과가 있다면 꼬리가 사라지지 않는다.
		if (board[pos.y][pos.x] == Type::APPLE)
		{
			// 큐에 바디 정보 넣기
			//board[pos.y][pos.x] = Type::BODY;
		}
		// 사과가 없다면 꼬리가 사라진다.
		else
		{
			Pos lostBody = body.front();
			board[lostBody.y][lostBody.x] = Type::NONE;
			body.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	gameSetting();
	dummy();
}
