#include "game.h"
#include <stdio.h>
void init_board(char board[ROWS][COLS], int row, int col)
{
	memset(board, BLANK, row*col*sizeof(char));
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	
	printf("棋盘显示如下：\n");
	for(i = 0; i < row; i++)
	{
		printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);

		if(i == row-1)
			break;

		printf("---|---|---\n");
	}
}

int judge_blank(char board[ROWS][COLS], int row, int col)
{
	int flag = 0;
	int i = 0;

	for(i = 0; i < row*col; i++)
	{
		if(*(*(board+0)+i) == BLANK)
		{	
			flag = 1;
			break;
		}
	}

	return flag;
}

int judge_row(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int flag = 0;

	for(i = 0; i < row; i++)
	{
		int same_row = board[i][0];
	
		int count_row = 0;

		for(j = 0; j < col; j++)
		{
			if(same_row != board[i][j])
				break;

			count_row++;	
		}

		if(count_row == LENGTH)
		{
			if(same_row == PLAYER)
			{
				flag = 2;
				break;
			}
			else if(same_row == COMPUTER)
			{
				flag = 3;
				break;
			}
		}
	}

	return flag;
}

int judge_col(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int flag = 0;
	for(j = 0; j < col; j++)
	{
		int same_col = board[0][j];
		int count_col = 0;

		for(i = 0; i < col; i++)
		{
			if(same_col != board[i][j])
				break;

			count_col++;	
		}

		if(count_col == LENGTH)
		{
			if(same_col == PLAYER)
			{
				flag = 2;
				break;
			}
			else if(same_col == COMPUTER)
			{
				flag = 3;
				break;
			}
		}
	}
	
	return flag;
}

int judge_diagonal(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int flag = 0;

	for(i = 0; i < row; i++)
	{
		int same_diagonal = board[i][i];
		int count_diagonal = 0;
		
		if(row <= col)
		{
			if(same_diagonal != board[i][i])
				break;
			count_diagonal++;
		}

		if(count_diagonal == LENGTH)
		{
			if(same_diagonal == PLAYER)
				flag = 2;
			else if(same_diagonal == COMPUTER)
				flag = 3;
		}
	}

	return flag;
}

int judge(char board[ROWS][COLS], int row, int col)
{
	int flag = 0;
	int tmp = 0;
	//0——没位，没人赢（平局结束）
	//1——有位置，没人赢（继续下子）
	//2——玩家赢（结束）
	//3——电脑赢（结束）

	flag = judge_blank(board, row, col);

	tmp = judge_row(board, row, col);

	if((tmp != 2) && (tmp != 3))
		tmp = judge_col(board, row, col);

	if((tmp != 2) && (tmp != 3))
		tmp = judge_diagonal(board, row, col);

	if(tmp != 0)
		flag = tmp;

	if(flag == 0)
	{
		printf("平局！\n");
		return 0;
	}
	else if(flag == 1)
	{
		return 1;
	}
	else if(flag == 2)
	{
		printf("玩家获胜！\n");
		return 0;
	}
	else if(flag == 3)
	{
		printf("电脑获胜！\n");
		return 0;
	}	
}

void player_play(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;

	do{	
		printf("玩家下子(输入行数和列数) > ");
		scanf("%d%d",&i,&j); 
		
		if(i <= 0 || i > row || j <= 0 || j > col)
		{
			printf("输入位置不再棋盘范围内，请重新输入！\n");
			continue;
		}

		if(board[i-1][j-1] == BLANK)
		{
			break;
		}
		else
		{
			printf("所选位置已被占用，请重新选择！\n");
		}
	}while(1);

	board[i-1][j-1] = 'X';
}

void computer_play(char board[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int flag = 0;
	//可以考虑八连通域填充算法

	while(1)
	{
		x = rand() % row;
		y = rand() % col;
	
		if(board[x][y] == BLANK)
		{
			break;
		}
	}

	printf("电脑自动下子\n");

	board[x][y] = 'O';
}

/*
{
	int i = 0, j = 0;
	int same_row,same_col,same_diagonal = 0;
	int count_row, count_col, count_diagonal = 0;
	
	same_diagonal = board[i][i];

	for(i = 0; i < row; i++)
	{	
		same_row = board[i][0];
	
		count_row = 0;
		count_diagonal = 0;
		for(j = 0; j < col; j++)
		{
			same == 
			if(same_row == board[i][j])
				count_row++;
			if(same_diagonal == board[i][i])
		}
	}
}
*/