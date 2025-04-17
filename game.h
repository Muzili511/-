#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define LIN 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initBoard(char board[ROW][LIN], int row, int lin);
void display(char board[ROW][LIN], int row, int lin);
void playermove(char board[ROW][LIN], int row, int lin);
void computermove(char board[ROW][LIN], int row, int lin);
char iswin(char board[ROW][LIN], int row, int lin);