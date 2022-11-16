#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Pos dest = board->GetExitPos();

	Pos front[4] =
	{
		Pos { -1, 0 },
		Pos { 0, -1 },
		Pos { 1, 0 },
		Pos { 0, 1 },
	};

	while (pos != dest)
	{
		// 1. 현재 바라보는 방향 기준으로 오른쪽으로 갈 수 있는지 확인
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 우측 90도 회전
			_dir = newDir;

			// 1보 전진
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향 기준으로 전진 가능한지 확인
		else if (CanGo(pos + front[_dir]))
		{
			// 1보 전진
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			// 방향 전환
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

	stack<Pos> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	// 목적지 도착
	if (_path.empty() == false)
		s.push(_path.back());

	vector<Pos> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	::reverse(path.begin(), path.end());

	_path = path;
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tile = _board->GetTileType(pos);
	return tile == TileType::EMPTY;
}
