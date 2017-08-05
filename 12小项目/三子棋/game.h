
#define ROWS 3
#define COLS 3

#define LENGTH 3

#define BLANK ' '
#define PLAYER 'X'
#define COMPUTER 'O'

void init_board(char board[ROWS][COLS], int row, int col);

void display_board(char board[ROWS][COLS], int row, int col);

int judge_blank(char board[ROWS][COLS], int row, int col);
int judge_row(char board[ROWS][COLS], int row, int col);
int judge_col(char board[ROWS][COLS], int row, int col);
int judge_diagonal(char board[ROWS][COLS], int row, int col);
int judge(char board[ROWS][COLS], int row, int col);

void player_play(char board[ROWS][COLS], int row, int col);

void computer_play(char board[ROWS][COLS], int row, int col);
