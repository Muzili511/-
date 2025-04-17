#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void initBoard(char board[ROW][LIN], int row, int lin)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void display(char board[ROW][LIN], int row, int lin)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			printf("%c ", board[i][j]);
			if (j < lin - 1)
			{
				printf("| ");
			}
		}
		printf("\n");
		if (i < row - 1) 
		{
			for (j = 0; j < lin; j++)
			{
				printf("---");

			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][LIN], int row, int lin)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("玩家走\n请输入下棋坐标:>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= lin)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该格已被占用，请重新输入下棋坐标\n");
			}
		}
		else
		{
			printf("坐标超出范围，请重新输入下棋坐标\n");
		}
	}
}
void computermove(char board[ROW][LIN], int row, int lin)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		x = rand() % row;
		y = rand() % lin;
		if (x >= 0 && x <= row && y >= 0 && y <= lin)
		{
			if (board[x][y] == ' ')
			{
				printf("电脑走\n");
				board[x][y] = 'o';
				break;
			}
		}
	}
}
int Iswin(char board[ROW][LIN], int row, int lin)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char iswin(char board[ROW][LIN], int row, int lin)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row - 2; i++)
	{
		for (j = 0; j < lin - 2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 1] != ' ')
			{
				return board[i][j];
			}
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 1][j] != ' ')
			{
				return board[i][j];
			}
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] != ' ')
			{
				return board[i + 1][j + 1];
			}
			if (board[i + 2][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i][j + 2] && board[i + 1][j + 1] != ' ')
			{
				return board[i + 1][j + 1];
			}
		}
	}
	int ret = Iswin(board, row, lin);
	if (ret == 1)
	{
		return 'q';
	}
}