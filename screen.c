#include "declaration.h"

char* menus[MENU_MAX] = { "EASY","NORMAL","HARD","EXIT" };
char* backToMenus[BACK_TO_MENU_MAX] = { "��","�ƴϿ�" };




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
	printf("��");

	for (i = 0; i < WIDTH_MAX; i++)
		printf("-");

	printf("��");

	for (i = 1; i < HEIGHT_MAX; i++) {
		y++;
		gotoxy(x, y);
		printf("��");


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
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");

	for (i = 0; i < WIDTH_MAX; i++) {
		printf("-");
	}
	printf("��");

}

void printMenu(int index, int i) {


	for (int j = 0; j < MENU_MAX; j++) {
		gotoxy(STANDARD_CONSOLE, i + j);
		if (j == index - 1) {
			printf("%s", "��");
		}
		printf("%s", menus[j]);

	}


}

void printBackToMenu(int index, int i) {
	gotoxy(STANDARD_CONSOLE, i - 1);
	printf("���� �޴��� ���ư��ðڽ��ϱ�?");

	for (int j = 0; j < BACK_TO_MENU_MAX; j++) {
		gotoxy(STANDARD_CONSOLE, i + j);
		if (j == index - 1) {
			printf("%s", "��");
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
	printf("����:%d", format.score);
	gotoxy(HELP_X, HELP_Y+3);
	printf("�̵� Ƚ��:%d", format.keyCount);
	gotoxy(HELP_X, HELP_Y + 5);
	printf("����Ű�� ������ �� �ְ�, esc �� pause�Դϴ�.");
	gotoxy(HELP_X , HELP_Y+6);
	printf("�־��� �̵� Ƚ�� ���� ��� ������ ȹ���ϼ���!");
	gotoxy(HELP_X, HELP_Y + 7);
	printf("��, ��ֹ��鵵 �����ֽ��ϴ�!");
	gotoxy(HELP_X, HELP_Y + 8);
	printf("���� ������ �̵�Ƚ���� �̿��Ͽ� ���˴ϴ�.");
}

