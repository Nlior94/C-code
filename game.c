#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
#include <stdio.h>

void clean(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----*扫雷游戏*----\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----********-----\n");
}

void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = MINENUM;
	while (count)
	{
		//使x,y范围定义在1-9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int getmine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

    while(win < row * col - MINENUM)
	{
		printf("请输入要排查的坐标>>>");
	    scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，您被炸死了\n");
				display(mine, row, col);
				break;
			}
			else
			{
				int count = getmine(mine, x, y);
				show[x][y] = count + '0';
				display(show, row, col);
				win++;

			}
		}
		else
		{
			printf("请输入正确的坐标\n");
		}
	}
	if (win == row * col - MINENUM)
	{
		printf("恭喜你扫雷成功！\n");
		display(mine, row, col);
	}
}
