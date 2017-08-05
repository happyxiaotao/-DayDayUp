#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void menu()
{
	printf("\n按下对应的数字键来选择下一步\n");
	printf("********** 1 —— start **********\n");
	printf("********** 0 —— exit  **********\n");
	printf("input > ");
}

void game()
{
	char board[ROWS][COLS] = {0};

	int flag = rand()&1;

	 srand( (unsigned)time( NULL ) );

	init_board(board, ROWS, COLS);

	while(judge(board, ROWS, COLS))
	{	
		if((flag++)&1)
			player_play(board, ROWS, COLS);
		else
			computer_play(board, ROWS, COLS);
		
		display_board(board, ROWS, COLS);		
	}	
}

int main()
{
	int input = 0;

	do
	{
		menu();

		scanf("%d",&input);
	
		switch(input)
		{
		case 0:
			exit(0);
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误！");
			break;
		}

	}while(input);

	return 0;
}