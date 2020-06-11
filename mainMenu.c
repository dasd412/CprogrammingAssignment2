

#include"declaration.h"



extern void progressMenu() {	//메인 메뉴를 진행시키는 함수
	//메뉴 구성에 필요한 변수 선언
	int initCount = 1;//메인 메뉴의 커서가 맨 위인지 맨 아래인지 구분 하기 위한 변수

	int direction;//입력받는 키

	
	
	//screen.c의 메뉴 프린트 함수 호출
	cursorFix(D_X, D_Y, 1, FLAG_MENU);

	while (1) {//메뉴 반복

		direction = _getch();//키를 입력받는다.
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
			//커서가 맨 위인 경우
			cursorFix(D_X, D_Y, 1, FLAG_MENU);//easy mode를 가리키도록 화면을 표시한다.

		}
		else if (initCount == 2) {

			cursorFix(D_X, D_Y, 2, FLAG_MENU);//normal mode를 가리키도록 화면을 표시한다.

		}
		else if (initCount == 3) {


			cursorFix(D_X, D_Y, 3, FLAG_MENU);//hard mode를 가리키도록 화면을 표시한다.

		}
		else {

			cursorFix(D_X, D_Y, 4, FLAG_MENU);//exit mode를 가리키도록 화면을 표시한다.

		}

		if (direction == 13) {//엔터키를 누름.
			format.isNew = ON;//포맷 새로 시작한다고 셋팅

			if (initCount == 1) {//easy mode
				//이지 모드 진입
				progressGame(&(easyMode.bombCount),&(easyMode.flagCount),&(easyMode.treasureCount));
				
			}
			else if (initCount == 2) {//normal mode
				//노멀 모드 진입
				progressGame(&(normalMode.bombCount),&(normalMode.flagCount),&(normalMode.treasureCount));
				
			}
			else if (initCount == 3) {//hard mode
				//하드 모드 진입
				progressGame(&(hardMode.bombCount),&(hardMode.flagCount),&(hardMode.treasureCount));
				
			}
			else { //exit
				//프로세스 종료
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

	//모드에 쓰이는 구조체 초기화
	initMode();

	//메인 메뉴를 진행시키는 함수
	progressMenu();
	
	return 0;
}

void initMode() {//모드에 쓰이는 구조체를 초기화하는 함수

	// 각 모드에 필요한 폭탄 개수, 깃발 개수, 보물 개수. 깃발 개수=폭탄 개수 +보물 개수  
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