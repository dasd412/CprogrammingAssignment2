

#include"declaration.h"



extern void progressMenu() {
	//�޴� ������ �ʿ��� ���� ����
	int initCount = 1;

	int direction;

	


	cursorFix(D_X, D_Y, 1, FLAG_MENU);

	while (1) {//�޴� �ݺ�

		direction = _getch();
		if (direction == 224 || direction == 0) {//����Ű�ΰ�?
			direction = _getch();

			switch (direction) {//����Ű����

			case 72://�����
				if (initCount != 1) {//�� ���� �ƴϸ�
					--initCount;
				}
				break;

			case 80://�Ʒ����
				if (initCount != 4) {//�� �Ʒ��� �ƴ϶��
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

		if (direction == 13) {//����Ű�� ����.
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