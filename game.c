#include"declaration.h"


#define OFF_ESC 0
#define ON_ESC 1

int flag_ESC=OFF_ESC;
int input;


void reAllocateMap(int x, int y) {

	int bomb_reset, bomb_map, bomb_return;
	int treasure_plus, treasure_double;




	treasure_double = treasure.doubule;
	treasure_plus = treasure.score;

	bomb_reset = bombs.reset;
	bomb_map = bombs.map;
	bomb_return = bombs.ret;

	initWall();

	//man is on current position

	board.gameBoard[man.x][man.y] = MAN;
	board.visited[man.x][man.y] = VISITED;
	board.view[man.x][man.y] = MAN;

	//reallocate bomb

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_reset > 0) {

				board.gameBoard[x][y] = BOMB_SCORE;
				bomb_reset--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
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
				board.view[x][y] = FLAG;
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
				board.view[x][y] = FLAG;
			}
		}
	}

	//reallocate treasure

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_plus > 0) {

				board.gameBoard[x][y] = TREASURE_PLUS;
				treasure_plus--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_double > 0) {

				board.gameBoard[x][y] = TREASURE_DOUBLE;
				treasure_double--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

}


void initTreasure(int trasureCount) {
	int x, y;
	int treasure_plus, treasure_double;




	treasure_double = trasureCount / 2;
	treasure_plus = trasureCount / 2;

	treasure.doubule = treasure_double;
	treasure.score = treasure_plus;

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_plus > 0) {

				board.gameBoard[x][y] = TREASURE_PLUS;
				treasure_plus--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_double > 0) {

				board.gameBoard[x][y] = TREASURE_DOUBLE;
				treasure_double--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}
}

void initBomb(int bombCount) {
	int x, y;
	int bomb_reset, bomb_map, bomb_return;

	bomb_reset = bombCount / 3;
	bomb_map = bombCount / 3;
	bomb_return = bombCount / 3;

	bombs.reset = bomb_reset;
	bombs.map = bomb_map;
	bombs.ret = bomb_return;

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_reset > 0) {

				board.gameBoard[x][y] = BOMB_SCORE;
				bomb_reset--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
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
				board.view[x][y] = FLAG;
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
				board.view[x][y] = FLAG;
			}
		}
	}
}


void initMap(int bombCount, int flagCount, int trasureCount) {


	



	//wall init

	initWall();

	//man init
	man.x = START_X;
	man.y = START_Y;
	board.gameBoard[man.x][man.y] = MAN;
	board.visited[man.x][man.y] = VISITED;
	board.view[man.x][man.y] = MAN;

	//bomb init
	initBomb( bombCount);


	//treasure init
	initTreasure(trasureCount);


	board.initFlag = ON;

}

void initWall() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (i == 0 || j == 0 || i == BOARD_WIDTH - 1 || j == BOARD_HEIGHT - 1) {
				board.gameBoard[i][j] = WALL;
				board.visited[i][j] = VISITED;
				board.view[i][j] = WALL;
			}
			else {
				board.gameBoard[i][j] = NONE;
				board.visited[i][j] = YET;
				board.view[i][j] = NONE;

			}

		}
	}
}


void backToMain(int* bombCount, int* flagCount, int* trasureCount) {
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
void initGameFormat() {
	//game init
	if (format.isNew == ON) {
		format.score = 0;
	}
	
	format.keyCount =600;
}


extern void progressGame(int* bombCount, int* flagCount, int* trasureCount) {
	
	int temp_x, temp_y;
	int canGo_flag=OFF;

	initGameFormat();

	if (board.initFlag == OFF) {
      initMap((*bombCount), (*flagCount), (*trasureCount));
	}
	
	cursorFix(D_X, D_Y, 1, FLAG_GAME);

	while (treasure.doubule+treasure.score>0) {//메뉴 반복

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
		else {
			if (input == 224 || input == 0) {
			input = _getch();
			temp_x = man.x;
			temp_y = man.y;				
			canGo_flag = OFF;
			format.keyCount--;
			switch (input) {
				
			case 72://위
				if (canGo(man.x,man.y - 1)==ON) {
					man.y = man.y -1;
					canGo_flag = ON;
				}
				

				break;

			case 75://왼
				if (canGo(man.x - 1,man.y)== ON) {
					man.x = man.x -1 ;
					canGo_flag = ON;
				}
			
				break;

			case 77://오른쪽
				if (canGo(man.x + 1,man.y)== ON) {
					man.x = man.x + 1;
					canGo_flag = ON;
				}
				
				break;

			case 80://아래
				if (canGo(man.x,man.y + 1)== ON) {
					man.y = man.y + 1;
					canGo_flag = ON;
				}
				
				break;

			default:break;
			}//switch
			if (canGo_flag == ON) {
				
				if (whatsThis(man.x, man.y)==ON) {
					findAndCollect(man.x, man.y);
				}
				board.gameBoard[man.x][man.y] = MAN;
			    board.gameBoard[temp_x][temp_y] = NONE;
				board.view[temp_x][temp_y] = NONE;
			}
			

		}

		}
		
		


	}

	calculateScore();
	board.initFlag = OFF;
	format.isNew = OFF;
	if (*(flagCount) == easyMode.flagCount) {
		progressGame(&(normalMode.bombCount), &(normalMode.flagCount), &(normalMode.treasureCount));
	}
	else if (*(flagCount) == normalMode.flagCount) {
		progressGame(&(hardMode.bombCount), &(hardMode.flagCount), &(hardMode.treasureCount));
	}
	else  {
		cursorFix(D_X, D_Y, 1, FLAG_FINAL);
		exit(0);
	}
	
}

void calculateScore() {
	
	
	format.score = format.score * 10 - format.keyCount * 2;
	
 }

void findAndCollect(int x, int y) {//기물 효과 처리, 분기별로
	/* 
#define TREASURE_PLUS 0
#define BOMB_MAP 1
#define FLAG 2
#define MAN 3
#define WALL 4
#define NONE 5
#define BOMB_SCORE 6
#define BOMB_RETURN 7
#define TREASURE_DOUBLE 8
*/
	int temp_x=x, temp_y=y;
	
	switch (board.gameBoard[x][y]) {
	case TREASURE_PLUS:
		treasure.score -= 1;
		
		format.score += 100; break;

	case BOMB_MAP:
		bombs.map -= 1;
		
		reAllocateMap(x,y);

		break;

	case BOMB_SCORE:
		bombs.reset -= 1;


		

		format.score =0;
		break;

	case BOMB_RETURN:
		bombs.ret -= 1;

		

		man.x = START_X;
		man.y = START_Y;
		board.gameBoard[temp_x][temp_y] = NONE;
		break;

	case TREASURE_DOUBLE:
		treasure.doubule -= 1;
		

		if (format.score == 0) {
			format.score = format.score + 100;
		}
		else if (format.score < 0) {
			format.score = 0;
		}
		
		format.score *= 2;
		break;

	default:break;

	}

}

int whatsThis(int x, int y) {

	if (board.gameBoard[x][y] == NONE) {
	
		return OFF;
	}
	else {
		
		return ON;
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