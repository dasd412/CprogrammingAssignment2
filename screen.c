#include "declaration.h"

char* menus[MENU_MAX] = { "EASY","NORMAL","HARD","EXIT" };
char* backToMenus[BACK_TO_MENU_MAX] = { "예","아니오" };




extern void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

extern void cursorFix(int x, int y, int index, int gameFlag) {
	int i;
	int j = 0;


	system("cls");

	gotoxy(x, y);
	printf("┌");

	for (i = 0; i < WIDTH_MAX; i++)
		printf("-");

	printf("┐");

	for (i = 1; i < HEIGHT_MAX; i++) {
		y++;
		gotoxy(x, y);
		printf("│");


		if (i == START_CURSOR) {

			if (gameFlag == FLAG_MENU) {
				printMenu(index, i);
			}
			else if (gameFlag == FLAG_BACK_TO_MENU) {
				printBackToMenu(index, i);
			}
			else if (gameFlag == FLAG_GAME) {
				printGame(index, i);
			}




		}



		x += 60;
		gotoxy(x, y);
		printf("│");
		x = 9;
	}
	gotoxy(x, y);
	printf("└");

	for (i = 0; i < WIDTH_MAX; i++) {
		printf("-");
	}
	printf("┘");

}

void printMenu(int index, int i) {


	for (int j = 0; j < MENU_MAX; j++) {
		gotoxy(STANDARD_CONSOLE, i + j);
		if (j == index - 1) {
			printf("%s", "▶");
		}
		printf("%s", menus[j]);

	}


}

void printBackToMenu(int index, int i) {
	gotoxy(STANDARD_CONSOLE, i - 1);
	printf("메인 메뉴로 돌아가시겠습니까?");

	for (int j = 0; j < BACK_TO_MENU_MAX; j++) {
		gotoxy(STANDARD_CONSOLE, i + j);
		if (j == index - 1) {
			printf("%s", "▶");
		}
		printf("%s", backToMenus[j]);

	}
}

void printGame(int index, int i) {
	
	printGameHelp();


	
	for (int a = 0; a < BOARD_WIDTH; a++) {//11~68
		
		for (int b = 0; b < BOARD_HEIGHT; b++) {//3~23
			
				gotoxy(a + 11, b + 3);
				if (board.gameBoard[a][b] == WALL) {
					printf("@");
				}
				else if (board.gameBoard[a][b] == MAN) {
					printf("Y");
				}
				else if (board.gameBoard[a][b] == BOMB_SCORE) {
					printf("*");
				}
				else if (board.gameBoard[a][b] == BOMB_MAP) {
					printf("&");
				}
				else if (board.gameBoard[a][b] == BOMB_RETURN) {
					printf("#");
				}
				else if (board.gameBoard[a][b] == TREASURE_PLUS) {
					printf("$");
				}
				else if (board.gameBoard[a][b] == TREASURE_DOUBLE) {
					printf("!");
				}
				

			}
		
		
	}
	

}

void printGameHelp() {
	gotoxy(HELP_X, HELP_Y);
	printf("점수:%d", format.score);
	gotoxy(HELP_X, HELP_Y+3);
	printf("이동 횟수:%d", format.keyCount);
	gotoxy(HELP_X, HELP_Y + 5);
	printf("방향키로 움직일 수 있고, esc 는 pause입니다.");
	gotoxy(HELP_X , HELP_Y+6);
	printf("주어진 이동 횟수 내에 모든 보물을 획득하세요!");
	gotoxy(HELP_X, HELP_Y + 7);
	printf("단, 장애물들도 숨어있습니다!");
	gotoxy(HELP_X, HELP_Y + 8);
	printf("최종 점수는 이동횟수를 이용하여 계산됩니다.");
}

