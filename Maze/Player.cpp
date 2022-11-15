#include "pch.h"
#include "Player.h"
#include "Board.h"

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
		// 1. ���� �ٶ󺸴� ���� �������� ���������� �� �� �ִ��� Ȯ��
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// ���� 90�� ȸ��
			_dir = newDir;

			// 1�� ����
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 2. ���� �ٶ󺸴� ���� �������� ���� �������� Ȯ��
		else if (CanGo(pos + front[_dir]))
		{
			// 1�� ����
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			// ���� ��ȯ
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

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
