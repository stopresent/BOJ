#include "pch.h"
#include "ConsoleHelper.h"
#include "Board.h"

// �̷� �ø��� ȯ�� ���� �Ϸ�!

Board board;

enum
{
	BOARD_SIZE = 25,
};

int main()
{
	board.Init(BOARD_SIZE);

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

		// ������
		board.Render();
	}
}
