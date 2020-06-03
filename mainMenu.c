

#include"declaration.h"

char* menus[MENU_MAX] = { "EASY","NORMAL","HARD","EXIT" };
char* backToMenus[BACK_TO_MENU_MAX] = { "예","아니오" };



extern void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

extern void cursorFix(int x, int y,int index, int gameFlag) {
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


		if (i== START_CURSOR){

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

void printMenu(int index,int i) {

	
		for (int j = 0; j < MENU_MAX; j++) {
			gotoxy(STANDARD_CONSOLE, i + j);
			if (j == index-1) {
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
	gotoxy(STANDARD_HELP_X, STANDARD_HELP_Y);
	printf("esc 는 pause입니다.");

}

extern void progressMenu() {
	//메뉴 구성에 필요한 변수 선언
	int initCount = 1;

	int direction;




	cursorFix(D_X, D_Y, 1, FLAG_MENU);

	while (1) {//메뉴 반복

		direction = _getch();
		if (direction == 224 || direction == 0) {//방향키인가?
			direction = _getch();

			switch (direction) {//방향키에서

			case 72://위라면
				if (initCount != 1) {//맨 위가 아니면
					--initCount;
				}
				break;

			case 80://아래라면
				if (initCount != 4) {//맨 아래가 아니라면
					++initCount;
				}
				break;

			default:break;

			}//switch
		}

		if (initCount == 1) {

			cursorFix(D_X, D_Y, 1, FLAG_MENU);

		}
		else if (initCount == 2) {

			cursorFix(D_X, D_Y, 2, FLAG_MENU);

		}
		else if (initCount == 3) {


			cursorFix(D_X, D_Y, 3, FLAG_MENU);

		}
		else {

			cursorFix(D_X, D_Y, 4, FLAG_MENU);

		}

		if (direction == 13) {//엔터키를 누름.
			if (initCount == 1) {//easy mode
				progressGame();
			}
			else if (initCount == 2) {//normal mode

			}
			else if (initCount == 3) {//hard mode

			}
			else { //exit

				return;
			}

		}


	}
}

int main(void) {

	progressMenu();
	
	return 0;
}