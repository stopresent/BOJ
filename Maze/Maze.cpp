#include "pch.h"
#include "ConsoleHelper.h"

int main()
{
	uint64 lastTick = 0;

	const char* TILE = "��";

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
