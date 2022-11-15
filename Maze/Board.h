#pragma once

<<<<<<< HEAD
enum
{
	BOARD_MAX_SIZE = 100,
=======
#include "ConsoleHelper.h"

class Player;

enum
{
	BOARD_MAX_SIZE = 100
>>>>>>> cef97a745b85b88d9f4a1f9f89697b7ad563615a
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL,
};

class Board
{
public:
	Board();
	~Board();

<<<<<<< HEAD
	void Init(int size);
	void Render();

	void GenerateMap();

private:
	TileType _tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE] = {};
	int32 _size = 0;
=======
	void			Init(int32 size, Player* player);
	void			Render();

	void			GenerateMap();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);

	Pos GetEnterPos() { return Pos{ 1, 1 }; }
	Pos GetExitPos() { return Pos{ _size - 2, _size - 2 }; }

private:
	TileType		_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE] = {};
	int32			_size = 0;
	Player*			_player = nullptr;
>>>>>>> cef97a745b85b88d9f4a1f9f89697b7ad563615a
};

