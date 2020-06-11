

#include"declaration.h"



extern void progressMenu() {	//���� �޴��� �����Ű�� �Լ�
	//�޴� ������ �ʿ��� ���� ����
	int initCount = 1;//���� �޴��� Ŀ���� �� ������ �� �Ʒ����� ���� �ϱ� ���� ����

	int direction;//�Է¹޴� Ű

	
	
	//screen.c�� �޴� ����Ʈ �Լ� ȣ��
	cursorFix(D_X, D_Y, 1, FLAG_MENU);

	while (1) {//�޴� �ݺ�

		direction = _getch();//Ű�� �Է¹޴´�.
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
			//Ŀ���� �� ���� ���
			cursorFix(D_X, D_Y, 1, FLAG_MENU);//easy mode�� ����Ű���� ȭ���� ǥ���Ѵ�.

		}
		else if (initCount == 2) {

			cursorFix(D_X, D_Y, 2, FLAG_MENU);//normal mode�� ����Ű���� ȭ���� ǥ���Ѵ�.

		}
		else if (initCount == 3) {


			cursorFix(D_X, D_Y, 3, FLAG_MENU);//hard mode�� ����Ű���� ȭ���� ǥ���Ѵ�.

		}
		else {

			cursorFix(D_X, D_Y, 4, FLAG_MENU);//exit mode�� ����Ű���� ȭ���� ǥ���Ѵ�.

		}

		if (direction == 13) {//����Ű�� ����.
			format.isNew = ON;//���� ���� �����Ѵٰ� ����

			if (initCount == 1) {//easy mode
				//���� ��� ����
				progressGame(&(easyMode.bombCount),&(easyMode.flagCount),&(easyMode.treasureCount));
				
			}
			else if (initCount == 2) {//normal mode
				//��� ��� ����
				progressGame(&(normalMode.bombCount),&(normalMode.flagCount),&(normalMode.treasureCount));
				
			}
			else if (initCount == 3) {//hard mode
				//�ϵ� ��� ����
				progressGame(&(hardMode.bombCount),&(hardMode.flagCount),&(hardMode.treasureCount));
				
			}
			else { //exit
				//���μ��� ����
				exit(0);
			}

		}


	}
}

int main(void) {
	PlaySound(TEXT("C:\\testMusic\\media.io_bgm.wav" ),NULL, SND_ASYNC | SND_LOOP);//function for playing music

	/*
	÷���� ���� ������ �� ��ο� ������ ������ ����˴ϴ�.
	���� ��� ���� ��ũ c�� test ������ ������ �ִ´ٰ� �ϸ� �ڵ�� ������ �����ϴ�.
	PlaySound(TEXT("C:\\test\\media.io_bgm.wav" ),NULL, SND_ASYNC | SND_LOOP);
	*/

	//��忡 ���̴� ����ü �ʱ�ȭ
	initMode();

	//���� �޴��� �����Ű�� �Լ�
	progressMenu();
	
	return 0;
}

void initMode() {//��忡 ���̴� ����ü�� �ʱ�ȭ�ϴ� �Լ�

	// �� ��忡 �ʿ��� ��ź ����, ��� ����, ���� ����. ��� ����=��ź ���� +���� ����  
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