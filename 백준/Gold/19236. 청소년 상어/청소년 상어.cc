#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void print_board();

struct Shark
{
	int y, x, dir;
};

struct Fish
{
	int y, x;
	int idx;
	int dir;
	bool alive = true;

	bool operator<(const Fish& other)
	{
		return idx < other.idx;
	}
};

int ret = 0;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
//vector<vector<Fish>> fishes;
vector<Fish> fishes;
vector<vector<int>> board;
Shark shark;

void swap_fish(int idx1, int idx2, int y, int x)
{
	if (idx2 == -1)
	{
		int curY = fishes[idx1].y;
		int curX = fishes[idx1].x;
		board[y][x] = idx1;
		board[curY][curX] = 0;

		fishes[idx1].y = y;
		fishes[idx1].x = x;
	}
	else
	{
		swap(fishes[idx1].y, fishes[idx2].y);
		swap(fishes[idx1].x, fishes[idx2].x);
		//swap(fishes[idx1].dir, fishes[idx2].dir);
		//swap(fishes[idx1].idx, fishes[idx2].idx);
	}

}

void move()
{
	sort(fishes.begin(), fishes.end());
	// 인덱스가 낮은 물고기부터 움직이기 시작

	for (int i = 0; i < fishes.size(); ++i)
	{
		if (fishes[i].alive == false)
			continue;

		if (i == 1)
		{
			int a = 1;
			a++;
		}

		int dir = fishes[i].dir - 1;
		for (int j = 0; j < 8; ++j)
		{
			int ny = fishes[i].y + dy[(dir + j) % 8];
			int nx = fishes[i].x + dx[(dir + j) % 8];

			if (ny == shark.y && nx == shark.x)
				continue;
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
				continue;
			fishes[i].dir = (dir + j) % 8 + 1;

			int y = fishes[i].y;
			int x = fishes[i].x;
			int index = board[ny][nx];
			swap_fish(i, index - 1, ny, nx);
			//swap(fishes[i], fishes[index - 1]);

			board[ny][nx] = i + 1;
			board[y][x] = index;

			//cout << i + 1 << "물고기 이동" << endl;
			//print_board();

			break;
		}
	}

	//cout << "이동 끝" << endl;
}

void dead(int idx)
{
	//fishes[idx].y = -1;
	//fishes[idx].x = -1;
	//fishes[idx].idx = -1;
	//fishes[idx].dir = -1;
	fishes[idx].alive = false;
	//board[fishes[idx].y][fishes[idx].x] = 0;
}

void print_board()
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;

	//cout << "########################" << endl;
	//for (int i = 0; i < 16; ++i)
	//{
	//	cout << fishes[i].idx << " " ;
	//	cout << fishes[i].y << " ";
	//	cout << fishes[i].x << " ";
	//	cout << fishes[i].dir << endl;
	//}
	//cout << "########################" << endl;
}

int fishD, fishS;
void DFS(int x, int y, int d, int total) {
	shark.x = x, shark.y = y;

	if (ret < total)
		ret = total;

	int cMap[4][4];
	Fish cFish[16];

	// 기존 맵 복사
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cMap[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		cFish[i] = fishes[i];
	}

	// 상어의 위치
	//cout << "상어의 위치" << endl;
	//cout << shark.y << ", " << shark.x << endl;
	// 물고기 이동
	move();

	for (int i = 1; i <= 3; i++) {
		int ny = y + dy[d] * i;
		int nx = x + dx[d] * i;

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			break;
		else {
			if (fishes[board[ny][nx] - 1].alive == false)
				continue; // 물고기 없으면 못 감

			fishD = fishes[board[ny][nx] - 1].dir;
			fishS = board[ny][nx];

			fishes[board[ny][nx] - 1].alive = false;
			//board[ny][nx] = 0;

			//cout << "현재 Total : " << total << " 현재 ret : " << ret << endl;

			DFS(nx, ny, fishD - 1, total + fishS);

			//board[ny][nx] = fishS;
			fishes[board[ny][nx] - 1].alive = true;
		}
	}


	// 기존 맵 원래대로
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = cMap[i][j];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		fishes[i] = cFish[i];
	}
}

void solve()
{
	//fishes = vector<vector<Fish>>(4, vector<Fish>(4));
	board = vector<vector<int>>(4, vector<int>(4));
	int idx, dir;
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			//cin >> fishes[y][x].idx;
			//cin >> fishes[y][x].dir;
			//fishes[y][x].y = y;
			//fishes[y][x].x = x;
			cin >> idx >> dir;
			fishes.push_back({ y, x, idx, dir });
			board[y][x] = idx;
		}
	}

	//print_board();

	ret += fishes[0].idx;
	shark.y = 0;
	shark.x = 0;
	shark.dir = fishes[0].dir;
	dead(0);

	DFS(0, 0, shark.dir - 1, ret);

	//move();

	//print_board();

	cout << ret;
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}