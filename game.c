#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void clean(char board[row][col], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void printboard(char board[row][col], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < c - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < c; j++)
			{
				printf("---");
				if (j < c - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void playermove(char board[row][col], int r, int c)
{
	int x = 0;
	int y = 0;

	printf("玩家走>>>\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("此格已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("超出棋盘范围，请重新输入\n");
		}
	}
}

void computermove(char board[row][col], int r, int c)
{
	printf("电脑走>>>\n");

	while (1)
	{
		int x = rand() % row;//保证电脑输入值在棋格范围内
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int FON(char board[row][col], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘未满
			}
		}
	}
	return 1;//棋盘满了
}

char WON(char board[row][col], int r, int c)
{
	int i = 0;

	for (i = 0; i < r; i++)//成行的判断
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	for (i = 0; i < c; i++)//成列的判断
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//对角线的判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][2] && board[2][0] != ' ')
		return board[1][1];

	//判断平局
	int ret = FON(board, r, c);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'c';
}
