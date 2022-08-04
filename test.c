#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("******  1. play  ******\n");
	printf("******  0. exit  ******\n");
	printf("***********************\n");
}

void game()
{
	char board[row][col];//想改变棋盘格数可以直接在头文件中修改
	clean(board, row, col);//初始化键盘函数
	printboard(board,row,col);//打印棋盘

	char ret = 0;

	while (1)
	{
		playermove(board, row, col);
		printboard(board, row, col);
		ret = WON(board, row, col);//WON函数判断输赢
		if (ret != 'c')
			break;

		computermove(board, row, col);
		printboard(board, row, col);
		ret = WON(board, row, col);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("恭喜你，你赢了！\n");
		printboard(board, row, col);
	}
	else if (ret == '#')
	{
		printf("很可惜，你输了！\n");
		printboard(board, row, col);
	}
	else
	{
		printf("平局\n");
		printboard(board, row, col);
	}
}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择>>>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确指令\n");
			break;

		}
	} while (input);

	return 0;
}
