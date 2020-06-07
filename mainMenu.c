

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
				progressGame(3,4,1);
			}
			else if (initCount == 2) {//normal mode
				progressGame(5,7,3);
			}
			else if (initCount == 3) {//hard mode
				progressGame(9,11,3);
			}
			else { //exit

				exit(0);
			}

		}


	}
}

int main(void) {

	progressMenu();
	
	return 0;
}