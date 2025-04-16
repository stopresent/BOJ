#include "pch.h"
#include "ConsoleHelper.h"
#include "Board.h"
#include "Player.h"
// �̷� �ø��� ȯ�� ���� �Ϸ�!

Board board;
Player player;

enum
{
	BOARD_SIZE = 25,
};

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	board.Init(BOARD_SIZE, &player);
	player.Init(&board);

	uint64 lastTick = 0;


	while (true)
	{
#pragma region ������ ����
		// deltaTick�� ��� ��Գ�
		uint64 currentTick = ::GetTickCount64();
		uint64 deltaTick = lastTick - currentTick;
		lastTick = currentTick;
#pragma endregion

		// �Է�

		// ����
		player.Update(deltaTick);

		// ������
		board.Render();
	}
}
