#pragma once

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

//初始化棋盘
void clean(char board[ROWS][COLS], int rows, int clos, char set);

//打印棋盘
void display(char board[ROWS][COLS], int row, int clo);
//注意此时传过去的棋盘依然是用的ROWS和COLS
