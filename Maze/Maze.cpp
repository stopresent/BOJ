#include "pch.h"
#include "ConsoleHelper.h"
#include "Board.h"
#include "Player.h"
// 미로 시리즈 환경 설정 완료!

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
#pragma region 프레임 관리
		// deltaTick은 어따 써먹냐
		uint64 currentTick = ::GetTickCount64();
		uint64 deltaTick = lastTick - currentTick;
		lastTick = currentTick;
#pragma endregion

		// 입력

		// 로직
		player.Update(deltaTick);

		// 랜더링
		board.Render();
	}
}
