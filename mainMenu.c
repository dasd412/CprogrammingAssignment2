

#include"declaration.h"



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
				progressGame(easyMode.bombCount,easyMode.flagCount,easyMode.treasureCount);
			}
			else if (initCount == 2) {//normal mode
				progressGame(normalMode.bombCount,normalMode.flagCount,normalMode.treasureCount);
			}
			else if (initCount == 3) {//hard mode
				progressGame(hardMode.bombCount,hardMode.flagCount,hardMode.treasureCount);
			}
			else { //exit

				exit(0);
			}

		}


	}
}

int main(void) {
	
	initMode();

	progressMenu();
	
	return 0;
}

void initMode() {
    easyMode.bombCount = 3; 
	easyMode.flagCount = 4;
	easyMode.treasureCount = 1;

	normalMode.bombCount = 6;
	normalMode.flagCount = 9;
	normalMode.treasureCount = 3;

	hardMode.bombCount = 9;
	hardMode.flagCount = 12;
	hardMode.treasureCount = 3;

}