#include "declaration.h"

char* menus[MENU_MAX] = { "EASY","NORMAL","HARD","EXIT" };//�޴� Ŀ���� ��Ÿ���� ���ڿ���
char* backToMenus[BACK_TO_MENU_MAX] = { "��","�ƴϿ�" };//�� �� ���� �޴� Ŀ���� ��Ÿ���� ���ڿ���



extern void gotoxy(int x, int y) {//�Է¹��� x,y��ǥ�� �ܼ� ��ǥ�� �����δ�.
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

extern void cursorFix(int x, int y, int index, int gameFlag) {
	int i;
	int j = 0;


	system("cls");//�� �� �ܼ��� �����. <-���� ���۸����� ������ �� �ִ�.

	//ȭ���� ����Ѵ�.
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

			if (gameFlag == FLAG_MENU) {//�޴��� ���޶�� ��û�̸�
				printMenu(index, i);//�޴��� ����Ѵ�.
			}
			else if (gameFlag == FLAG_BACK_TO_MENU) {//�� �� ���� �޴� ��� ��û�̶��
				printBackToMenu(index, i);
			}
			else if (gameFlag == FLAG_GAME) {//���� ��� ��û�̶��
				printGame(index, i);
			}
			else if (gameFlag == FLAG_FINAL) {//���� ���� ��� ��û�̶��
				gotoxy(11, 3);
				printf("���� ������ %d�Դϴ�!!", format.score);
				gotoxy(11, 4);
				printf("���� ����:");
				
				for (int a = 0; a < 5; a++) {
					gotoxy(11, a + 5);
					printf("%d�� : %d", (a+1),format.scoresSaved[a]);
				}
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

void printMenu(int index, int i) {//�޴��� Ŀ���� ����Ѵ�.


	for (int j = 0; j < MENU_MAX; j++) {
		gotoxy(STANDARD_CONSOLE, i + j);
		if (j == index - 1) {
			printf("%s", "��");
		}
		printf("%s", menus[j]);

	}


}

void printBackToMenu(int index, int i) {//�Ͻ� ����ȭ��� Ŀ���� ����Ѵ�.
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

void printGame(int index, int i) {//������ ����Ѵ�.
	
	printGameHelp();//���� ������ ����Ѵ�.


	
	for (int a = 0; a < BOARD_WIDTH; a++) {//11~68
		
		for (int b = 0; b < BOARD_HEIGHT; b++) {//3~23
			
				gotoxy(a + 11, b + 3);
				if (board.gameBoard[a][b] == WALL) {
					printf("@");
				}
				else if (board.gameBoard[a][b] == MAN) {
					printf("Y");
				}
				/*
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
				*/
				else if (board.view[a][b] == FLAG) {
					printf("?");
				}
				

			}
		
		
	}
	

}

void printGameHelp() {//���� ���� ����Լ�
	gotoxy(HELP_X, HELP_Y);
	printf("����:%d", format.score);
	gotoxy(HELP_X, HELP_Y+3);
	printf("�̵� Ƚ��:%d", format.keyCount);


	gotoxy(HELP_X, HELP_Y + 7);
	printf("����Ű�� ������ �� �ְ�, esc �� pause�Դϴ�.");
	gotoxy(HELP_X , HELP_Y+8);
	printf("�־��� �̵� Ƚ�� ���� ��� ������ ȹ���ϼ���!");
	gotoxy(HELP_X, HELP_Y + 9);
	printf("��, ��ֹ��鵵 �����ֽ��ϴ�!");
	gotoxy(HELP_X, HELP_Y + 10);
	printf("���� ������ �̵�Ƚ���� �̿��Ͽ� ���˴ϴ�.");
	gotoxy(HELP_X, HELP_Y + 13);
	printf("���� ����:");

	for (int a = 0; a < 5; a++) {
		gotoxy(HELP_X, HELP_Y +14+a);

		printf("%d�� : %d", (a + 1), format.scoresSaved[a]);
	}
}

