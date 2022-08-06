#pragma once
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define MINENUM 10

#define ROWS ROW + 2
#define COLS COL + 2

//初始化棋盘
void clean(char board[ROWS][COLS], int rows, int clos, char set);

//打印棋盘
void display(char board[ROWS][COLS], int row, int clo);
//注意此时传过去的棋盘依然是用的ROWS和COLS

//布置雷
void setmine(char mine[ROWS][COLS], int row, int col);

//排查雷
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
