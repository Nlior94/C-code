#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "game.h"

void menu()
{
	printf("************************\n");
	printf("******** 1.play ********\n");
	printf("******** 0.exit ********\n");
	printf("************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//布置雷
	char show[ROWS][COLS] = { 0 };//排查雷
	clean(mine, ROWS, COLS, '0');//初始化为0
	clean(show, ROWS, COLS, '*');//初始化为*

	display(mine, ROW, COL);
	display(show, ROW, COL);

}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择>>>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误值，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
