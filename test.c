#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("*********   1.play   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");
}
void game()
{
	char board[ROW][LIN];
	initBoard(board, ROW, LIN);
	display(board, ROW, LIN);
	while (1)
	{
		playermove(board, ROW, LIN);
		display(board, ROW, LIN);
		char win = iswin(board, ROW, LIN);
		if (win == '*')
		{
			printf("���Ӯ��\n");
			break;
		}
		else if (win == 'q')
		{
			printf("ƽ��\n");
			break;
		}
		computermove(board, ROW, LIN);
		display(board, ROW, LIN);
		win = iswin(board, ROW, LIN);
		if (win == 'o')
		{
			printf("����Ӯ��\n");
			break;
		}
		else if (win == 'q')
		{
			printf("ƽ��\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	do
	{
		srand(time(NULL));
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case(1):
			game();
			break;
		case(0):
			printf("������Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}