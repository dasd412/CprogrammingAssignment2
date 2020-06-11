

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
			format.isNew = ON;

			if (initCount == 1) {//easy mode
				
				progressGame(&(easyMode.bombCount),&(easyMode.flagCount),&(easyMode.treasureCount));
				
			}
			else if (initCount == 2) {//normal mode
				progressGame(&(normalMode.bombCount),&(normalMode.flagCount),&(normalMode.treasureCount));
				
			}
			else if (initCount == 3) {//hard mode
				progressGame(&(hardMode.bombCount),&(hardMode.flagCount),&(hardMode.treasureCount));
				
			}
			else { //exit

				exit(0);
			}

		}


	}
}

int main(void) {
	PlaySound(TEXT("C:\\testMusic\\media.io_bgm.wav" ),NULL, SND_ASYNC | SND_LOOP);//function for playing music

	/*

	첨부한 음악 파일을 위 경로에 넣으면 음악이 재생됩니다.
	예를 들어 로컬 디스크 c의 test 폴더에 음악을 넣는다고 하면 코드는 다음과 같습니다.
	PlaySound(TEXT("C:\\test\\media.io_bgm.wav" ),NULL, SND_ASYNC | SND_LOOP);

	*/

	initMode();

	progressMenu();
	
	return 0;
}

void initMode() {
    easyMode.bombCount = 3; 
	easyMode.flagCount = 5;
	easyMode.treasureCount = 2;

	normalMode.bombCount = 6;
	normalMode.flagCount = 10;
	normalMode.treasureCount = 4;

	hardMode.bombCount = 9;
	hardMode.flagCount = 13;
	hardMode.treasureCount = 4;

}