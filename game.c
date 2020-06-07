#include"declaration.h"

int score = 0;

#define OFF_ESC 0
#define ON_ESC 1

int flag_ESC=OFF_ESC;
int input;






void initMap(int bombCount, int flagCount, int trasureCount) {

	int x, y;

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
	board.gameBoard[START_X][START_Y] = MAN;
	board.visited[START_X][START_Y] = VISITED;

	//bomb init

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bombCount > 0) {

				board.gameBoard[x][y] = BOMB;
				bombCount--;
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
			case 72://위
				
				if (cursorCount_back != 1) {
					--cursorCount_back;
				}
				break;

			case 80://아래
				
				if (cursorCount_back != 2) {
					++cursorCount_back;
				}
				break;

			default:break;
			}

		}

		if (input == 13) {//엔터 키를 누른 경우
			flag_ESC = OFF_ESC;//ESC키를 껏다고 알림
			if (cursorCount_back == 1) {//예를 누른 경우

				board.initFlag = OFF;//게임 보드 다시 초기화


				progressMenu();

			}
			else {
				progressGame(bombCount, flagCount, trasureCount);//게임 다시 진행
				
			}
		}
		



	}
}


extern void progressGame(int bombCount, int flagCount, int trasureCount) {
	if (board.initFlag == OFF) {
      initMap(bombCount, flagCount, trasureCount);
	}
	

	while (1) {//메뉴 반복

		if (flag_ESC == ON_ESC) {//백투 메인이 켜져있는 경우
		
			backToMain(bombCount, flagCount, trasureCount);
		}
		else {
			cursorFix(D_X, D_Y, 1, FLAG_GAME);
		}

		input = _getch();
		if (flag_ESC==OFF_ESC&& input == 27) {//처음 ESC키 눌렀을 경우
			
			flag_ESC = ON_ESC;
		}
		else if (flag_ESC == ON_ESC && input == 27) {//ESC를 누른 상태일 경우 플래그 오프
			flag_ESC = OFF_ESC;
		}

		


	}
	
}