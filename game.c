#include"declaration.h"

int score = 0;

#define OFF_ESC 0
#define ON_ESC 1

int flag_ESC=OFF_ESC;
int input;


void backToMain() {
	int cursorCount_back = 1;
	while (1) {

		cursorFix(D_X, D_Y, cursorCount_back, FLAG_BACK_TO_MENU);

		input = _getch();
		if (input == 224 || input == 0) {
			input = _getch();

			switch (input) {
			case 72://��
				
				if (cursorCount_back != 1) {
					--cursorCount_back;
				}
				break;

			case 80://�Ʒ�
				
				if (cursorCount_back != 2) {
					++cursorCount_back;
				}
				break;

			default:break;
			}

		}

		if (input == 13) {//���� Ű�� ���� ���
			flag_ESC = OFF_ESC;//ESCŰ�� ���ٰ� �˸�
			if (cursorCount_back == 1) {//���� ���� ���
				progressMenu();
			}
			else {
				progressGame();//���� �ٽ� ����
				
			}
		}
		



	}
}


extern void progressGame() {
	

	while (1) {//�޴� �ݺ�

		if (flag_ESC == ON_ESC) {//���� ������ �����ִ� ���
		
			backToMain();
		}
		else {
			cursorFix(D_X, D_Y, 1, FLAG_GAME);
		}

		input = _getch();
		if (flag_ESC==OFF_ESC&& input == 27) {//ó�� ESCŰ ������ ���
			
			flag_ESC = ON_ESC;
		}
		else if (flag_ESC == ON_ESC && input == 27) {//ESC�� ���� ������ ��� �÷��� ����
			flag_ESC = OFF_ESC;
		}

		


	}
	
}