#include "gameHeader.h"

int score = 0;
char map[WIDTH_MAX - 1][HEIGHT_MAX - 1];


void cursorFixInGameMenu(int x, int y, int mode) {
	int i;
	int j = 0;


	system("cls");

	gotoxy(x, y);
	printf("¦£");

	for (i = 0; i < WIDTH_MAX; i++)
		printf("-");

	printf("¦¤");

	for (i = 1; i < HEIGHT_MAX; i++) {
		y++;
		gotoxy(x, y);
		printf("¦¢");

		
		



		x += 60;
		gotoxy(x, y);
		printf("¦¢");
		x = 9;
	}
	gotoxy(x, y);
	printf("¦¦");

	for (i = 0; i < WIDTH_MAX; i++) {
		printf("-");
	}
	printf("¦¥");

	printf("SCORES : %d", score);

}
void setUpEasyMode() {
	map[1][4] = '¢º';

	map[2][9] = '¢º';
}

extern void gameEasy() {

	setUpEasyMode();

	while (1) {

		cursorFixInGameMenu(D_X,D_Y,EASYMODE);
	}
}

