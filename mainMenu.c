

#include "menuHeader.h"




extern void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursorFix(int x, int y,int index) {
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

			printMenu(index, i);

			
			
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

int main(void) {

	//메뉴 구성에 필요한 변수 선언
	int initCount = 1;
	
	int direction;
	

	
	
	cursorFix(D_X,D_Y, 1);

	while (1) {//메뉴 반복

		direction = _getch();
		if (direction == 224 || direction == 0) {
			direction = _getch();
			
			switch (direction) {

			case 72:
				if (initCount != 1) {
				--initCount;
			    }
				break;

			case 80:
				if (initCount !=4) {
					++initCount;
				}
				break;

			default:break;

			}//switch
		}
	
		if (initCount == 1) {
		
			cursorFix(D_X,D_Y, 1);
			
		}
		else if (initCount == 2) {

			cursorFix(D_X,D_Y, 2);
			
		}
		else if(initCount==3){
		

			cursorFix(D_X,D_Y, 3);
			
		}
		else {
	
			cursorFix(D_X,D_Y,4);
			
		}

		if (direction == 13) {//엔터키를 누름.
			if (initCount == 1) {//easy mode
				gameEasy();
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
	
	return 0;
}