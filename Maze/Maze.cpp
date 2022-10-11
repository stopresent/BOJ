#include "pch.h"
#include "ConsoleHelper.h"

int main()
{
	uint64 lastTick = 0;

	const char* TILE = "■";

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

		// 랜더링
		ConsoleHelper::SetCursorPosition(0, 0);
		ConsoleHelper::ShowConsoleCursor(false);
		ConsoleHelper::SetCursorColor(ConsoleColor::RED);

		for (int y = 0; y < 25; ++y)
		{
			for (int x = 0; x < 25; ++x)
			{
				cout << TILE;
			}
			cout << endl;
		}
	}
}
