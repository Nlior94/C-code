#pragma once

#include <stdlib.h>
#include <time.h>

#define row 3
#define col 3

void clean(char board[row][col], int r, int c);//清空棋盘

void printboard(char board[row][col], int r, int c);//打印棋盘

void playermove(char board[row][col], int r, int c);//玩家下棋

void computermove(char board[row][col], int r, int c);//电脑下棋

char WON(char board[row][col], int r, int c);//判断输赢
