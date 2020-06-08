#include"declaration.h"

int score = 0;

#define OFF_ESC 0
#define ON_ESC 1

int flag_ESC=OFF_ESC;
int input;






void initMap(int bombCount, int flagCount, int trasureCount) {

	int x, y;
	int bomb_reset, bomb_map, bomb_return;

	bomb_reset = bombCount / 3;
	bomb_map = bombCount / 3;
	bomb_return = bombCount / 3;


	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (i == 0 || j == 0 || i == BOARD_WIDTH - 1||j==BOARD_HEIGHT-1) {
				board.gameBoard[i][j] = WALL;
			    board.visited[i][j] = VISITED;
			    board.realMap[i][j] = WALL;
			}
			else {
				board.gameBoard[i][j] = NONE;
			    board.visited[i][j] = YET;
			    board.realMap[i][j] = NONE;

			}
			
		}
	}
	

	//man init
	man.x = START_X;
	man.y = START_Y;
	board.gameBoard[man.x][man.y] = MAN;
	board.visited[man.x][man.y] = VISITED;
	

	//bomb init

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_reset > 0) {

				board.gameBoard[x][y] = BOMB_SCORE;
				bomb_reset--;
				board.visited[x][y] = VISITED;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_map > 0) {

				board.gameBoard[x][y] = BOMB_MAP;
				bomb_map--;
				board.visited[x][y] = VISITED;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_return > 0) {

				board.gameBoard[x][y] = BOMB_RETURN;
				bomb_return--;
				board.visited[x][y] = VISITED;
			}
		}
	}


	board.initFlag = ON;

}


void backToMain(int bombCount, int flagCount, int trasureCount) {
	int cursorCount_back = 1;
	while (1) {

		cursorFix(D_X, D_Y, cursorCount_back, FLAG_BACK_TO_MENU);

		input = _getch();
		if (input == 224 || input == 0) {
			input = _getch();

			switch (input) {
			case 72://��
				
				if (cursorCount_back != 1) {
					--cursorCount_back;
				}
				break;

			case 80://�Ʒ�
				
				if (cursorCount_back != 2) {
					++cursorCount_back;
				}
				break;

			default:break;
			}

		}

		if (input == 13) {//���� Ű�� ���� ���
			flag_ESC = OFF_ESC;//ESCŰ�� ���ٰ� �˸�
			if (cursorCount_back == 1) {//���� ���� ���

				board.initFlag = OFF;//���� ���� �ٽ� �ʱ�ȭ


				progressMenu();

			}
			else {
				progressGame(bombCount, flagCount, trasureCount);//���� �ٽ� ����
				
			}
		}
		



	}
}


extern void progressGame(int bombCount, int flagCount, int trasureCount) {
	
	int temp_x, temp_y;
	int canGo_flag=OFF;

	if (board.initFlag == OFF) {
      initMap(bombCount, flagCount, trasureCount);
	}
	
	cursorFix(D_X, D_Y, 1, FLAG_GAME);

	while (1) {//�޴� �ݺ�

		if (flag_ESC == ON_ESC) {//���� ������ �����ִ� ���
		
			backToMain(bombCount, flagCount, trasureCount);
		}
		else {
			
			cursorFix(D_X, D_Y, 1, FLAG_GAME);
		}

		input = _getch();
		if (flag_ESC==OFF_ESC&& input == 27) {//ó�� ESCŰ ������ ���
			
			flag_ESC = ON_ESC;
		}
		else if (flag_ESC == ON_ESC && input == 27) {//ESC�� ���� ������ ��� �÷��� ����
			flag_ESC = OFF_ESC;
		}
		else {
			if (input == 224 || input == 0) {
			input = _getch();
			temp_x = man.x;
			temp_y = man.y;				
			canGo_flag = OFF;
			switch (input) {
				
			case 72://��
				if (canGo(man.x,man.y - 1)==ON) {
					man.y = man.y -1;
					canGo_flag = ON;
				}
				

				break;

			case 75://��
				if (canGo(man.x - 1,man.y)== ON) {
					man.x = man.x -1 ;
					canGo_flag = ON;
				}
			
				break;

			case 77://������
				if (canGo(man.x + 1,man.y)== ON) {
					man.x = man.x + 1;
					canGo_flag = ON;
				}
				
				break;

			case 80://�Ʒ�
				if (canGo(man.x,man.y + 1)== ON) {
					man.y = man.y + 1;
					canGo_flag = ON;
				}
				
				break;

			default:break;
			}//switch
			if (canGo_flag == ON) {
				board.gameBoard[man.x][man.y] = MAN;
				if (whatsThis(temp_x, temp_y)==ON) {
					findAndCollect(temp_x, temp_y);
				}
			    board.gameBoard[temp_x][temp_y] = NONE;
			}
			

		}

		}
		
		


	}
	
}
void findAndCollect(int x, int y) {

}

int whatsThis(int x, int y) {
	if (board.gameBoard[x][y] != NONE) {
		return ON;
	}
	else {
		return OFF;
	}
}

int canGo(int man_x,int man_y) {

	if (board.gameBoard[man_x][man_y] == WALL) {
		return OFF;
	}
	else {
		return ON;
	}
}