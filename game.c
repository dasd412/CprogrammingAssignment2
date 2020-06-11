#include"declaration.h"

//ESC �¿��� �÷���
#define OFF_ESC 0
#define ON_ESC 1

int flag_ESC=OFF_ESC;
int input;//�Է� Ű

void initTreasure(int trasureCount) {//���� ��ġ �Լ�
	int x, y;
	int treasure_plus, treasure_double;


	//�Է� ���� ���ڿ� ���� /2�� ���־� ���� �����Ѵ�.

	treasure_double = trasureCount / 2;
	treasure_plus = trasureCount / 2;

	treasure.doubule = treasure_double;
	treasure.score = treasure_plus;

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y�� �����ϰ� �����Ѵ�.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_plus > 0) {//���� x,y��ǥ�� ��ġ�� �湮�� ���� ���� ���� ���� 100�� ������ ���� �ִٸ�

				board.gameBoard[x][y] = TREASURE_PLUS;//�����Ϳ� ���� ��ġ
				treasure_plus--;
				board.visited[x][y] = VISITED;//�湮�ߴٰ� üũ
				board.view[x][y] = FLAG;//ȭ�鿡�� ��߷� ��ġ
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y�� �����ϰ� �����Ѵ�.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_double > 0) {//���� x,y��ǥ�� ��ġ�� �湮�� ���� ���� ���� �ι� ���� ������ ���� �ִٸ�

				board.gameBoard[x][y] = TREASURE_DOUBLE;//�����Ϳ� ���� ��ġ
				treasure_double--;
				board.visited[x][y] = VISITED;//�湮�ߴٰ� üũ
				board.view[x][y] = FLAG;//ȭ�鿡�� ��߷� ��ġ
			}
		}
	}
}

void initBomb(int bombCount) {//��ź�� ��ġ�ϴ� �Լ�
	int x, y;
	int bomb_reset, bomb_map, bomb_return;

	//�Է� ���� ���ڿ� ���� /3�� ���־� ���� �����Ѵ�.
	bomb_reset = bombCount / 3;
	bomb_map = bombCount / 3;
	bomb_return = bombCount / 3;

	bombs.reset = bomb_reset;
	bombs.map = bomb_map;
	bombs.ret = bomb_return;

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y�� �����ϰ� �����Ѵ�.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_reset > 0) {//���� x,y��ǥ�� ��ġ�� �湮�� ���� ���� ���� reset ��ź�� ���� �ִٸ�

				board.gameBoard[x][y] = BOMB_SCORE;//�����Ϳ� reset ��ź ��ġ
				bomb_reset--;
				board.visited[x][y] = VISITED;//�湮�ߴٰ� üũ
				board.view[x][y] = FLAG;//ȭ�鿡�� ��߷� ��ġ
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y�� �����ϰ� �����Ѵ�.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_map > 0) {//���� x,y��ǥ�� ��ġ�� �湮�� ���� ���� ���� ���� ���ġ ��ź�� ���� �ִٸ�

				board.gameBoard[x][y] = BOMB_MAP;//�����Ϳ��� ��ź ��ġ
				bomb_map--;
				board.visited[x][y] = VISITED;//�湮�ߴٰ� üũ
				board.view[x][y] = FLAG;//ȭ�鿡�� ��߷� ��ġ
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y�� �����ϰ� �����Ѵ�.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_return > 0) {//���� x,y��ǥ�� ��ġ�� �湮�� ���� ���� ���� �������� ���� ��ź�� ���� �ִٸ�

				board.gameBoard[x][y] = BOMB_RETURN;//�����Ϳ� ��ź ��ġ
				bomb_return--;
				board.visited[x][y] = VISITED; //�湮�ߴٰ� üũ
				board.view[x][y] = FLAG;//ȭ�鿡�� ��߷� ��ġ
			}
		}
	}
}


void reAllocateMap(int x, int y) {//��ġ�� ���Ҵ��ϴ� �Լ�

	int bomb_reset, bomb_map, bomb_return;
	int treasure_plus, treasure_double;




	treasure_double = treasure.doubule;
	treasure_plus = treasure.score;

	bomb_reset = bombs.reset;
	bomb_map = bombs.map;
	bomb_return = bombs.ret;

	//�� �ʱ�ȭ

	initWall();

	//�÷��̾�� ���ڸ��� ��ġ�ؾ���.

	board.gameBoard[man.x][man.y] = MAN;
	board.visited[man.x][man.y] = VISITED;
	board.view[man.x][man.y] = MAN;

	//reallocate bomb

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_reset > 0) {

				board.gameBoard[x][y] = BOMB_SCORE;
				bomb_reset--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_map > 0) {

				board.gameBoard[x][y] = BOMB_MAP;
				bomb_map--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_return > 0) {

				board.gameBoard[x][y] = BOMB_RETURN;
				bomb_return--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

	//reallocate treasure

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_plus > 0) {

				board.gameBoard[x][y] = TREASURE_PLUS;
				treasure_plus--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_double > 0) {

				board.gameBoard[x][y] = TREASURE_DOUBLE;
				treasure_double--;
				board.visited[x][y] = VISITED;
				board.view[x][y] = FLAG;
			}
		}
	}

}




void initMap(int bombCount, int flagCount, int trasureCount) {//�� �ʱ�ȭ �Լ�


	



	//wall init

	initWall();

	//man init
	man.x = START_X;
	man.y = START_Y;
	board.gameBoard[man.x][man.y] = MAN;
	board.visited[man.x][man.y] = VISITED;
	board.view[man.x][man.y] = MAN;

	//bomb init
	initBomb( bombCount);


	//treasure init
	initTreasure(trasureCount);

	//�ʱ�ȭ�ߴٰ� �÷��׿� ����
	board.initFlag = ON;

}

void initWall() {//���� �ʱ�ȭ�ϴ� �Լ�
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (i == 0 || j == 0 || i == BOARD_WIDTH - 1 || j == BOARD_HEIGHT - 1) {//�������� �ܺ�����
				board.gameBoard[i][j] = WALL;
				board.visited[i][j] = VISITED;
				board.view[i][j] = WALL;
			}
			else {
				board.gameBoard[i][j] = NONE;
				board.visited[i][j] = YET;
				board.view[i][j] = NONE;

			}

		}
	}
}


void backToMain(int* bombCount, int* flagCount, int* trasureCount) {//�Ͻ� ���� �� ���� ���ư��� �Լ�
	int cursorCount_back = 1;//Ŀ�� ��ġ�� ��Ÿ���� ����
	while (1) {
		//�� �� ���� �Ŵ� ���
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

				board.initFlag = OFF;//���� ���� �ٽ� �ʱ�ȭ

				//�޴��� �ٽ� ���ư���.
				progressMenu();

			}
			else {
				progressGame(bombCount, flagCount, trasureCount);//���� �ٽ� ����
				
			}
		}
		



	}
}
void initGameFormat() {//���� ���� �ʱ�ȭ �Լ�
	//game init
	if (format.isNew == ON) {//������ ó�� �����������(=���� Ŭ��� �ƴ�, ���� �޴����� ����������)
		format.score = 0;//������ 0���� ����. �ƴ϶�� ������.
	}
	
	format.keyCount =600;//�̵�Ƚ���� 600���� �ʱ�ȭ
}


extern void progressGame(int* bombCount, int* flagCount, int* trasureCount) {//������ �����Ű�� �Լ�
	
	int temp_x, temp_y;//������ �־��� �÷��̾� ��ǥ�� ����ϱ� ���� �ӽú���
	int canGo_flag=OFF;//�浹 ���θ� ��Ÿ���� �÷���

	initGameFormat();//���� ������ �ʱ�ȭ�Ѵ�.

	if (board.initFlag == OFF) {//���� �ʱ�ȭ�� �� ������ ���� �ʱ�ȭ�Ѵ�.
      initMap((*bombCount), (*flagCount), (*trasureCount));
	}
	
	cursorFix(D_X, D_Y, 1, FLAG_GAME);

	while (treasure.doubule+treasure.score>0) {//���� ������ 0���� ū ���� �ݺ��Ѵ�.

		if (flag_ESC == ON_ESC) {//ESC�� ���� ���
		
			//�� �� ���� ȣ��
			backToMain(bombCount, flagCount, trasureCount);
		}
		else {
			//�ƴ϶�� ���� ȭ�� ���
			cursorFix(D_X, D_Y, 1, FLAG_GAME);
		}

		input = _getch();
		if (flag_ESC==OFF_ESC&& input == 27) {//ó�� ESCŰ ������ ��� ESC�� �����ٰ� �÷��׿� ����
			
			flag_ESC = ON_ESC;
		}
		else if (flag_ESC == ON_ESC && input == 27) {//ESC�� ���� ������ ��� �÷��� ����
			flag_ESC = OFF_ESC;
		}
		else {//ESCŰ�� �ƴ� �Է¿� ���ؼ�
			if (input == 224 || input == 0) {//����Ű���
			input = _getch();
			//���� ��ǥ �ӽ� ����
			temp_x = man.x;
			temp_y = man.y;	

			//�ϴ� �� �� ���ٰ� ����
			canGo_flag = OFF;

			//�̵� Ƚ�� 1 ����
			format.keyCount--;
			switch (input) {//����Ű�� ���ؼ�
				
			case 72://��
				if (canGo(man.x,man.y - 1)==ON) {//���� �� �� ������
					man.y = man.y -1;//y��ǥ 1�����ϰ� �� �� �ִٰ� �÷��׿� ����
					canGo_flag = ON;
				}
				

				break;

			case 75://��
				if (canGo(man.x - 1,man.y)== ON) {//�������� �� �� ������
					man.x = man.x -1 ;//x��ǥ 1�����ϰ� �� �� �ִٰ� �÷��׿� ����
					canGo_flag = ON;
				}
			
				break;

			case 77://������
				if (canGo(man.x + 1,man.y)== ON) {//���������� �� �� ������
					man.x = man.x + 1;//x��ǥ 1�����ϰ� �� �� �ִٰ� �÷��׿� ����
					canGo_flag = ON;
				}
				
				break;

			case 80://�Ʒ�
				if (canGo(man.x,man.y + 1)== ON) {//�Ʒ��� �� �� ������
					man.y = man.y + 1;//y��ǥ 1�����ϰ� �� �� �ִٰ� �÷��׿� ����
					canGo_flag = ON;
				}
				
				break;

			default:break;
			}//switch �� ��

			if (canGo_flag == ON) {//�� �� ������
				
				if (whatsThis(man.x, man.y)==ON) {//�Դٰ� ���� �����ϰ� ������
					findAndCollect(man.x, man.y);//�⹰�� ȿ�� ó��
				}

				board.gameBoard[man.x][man.y] = MAN;//�̵��� ���� �÷��̾� ���
			    board.gameBoard[temp_x][temp_y] = NONE;//�־��� ���� none���� ó���ؼ� ������ ����
				board.view[temp_x][temp_y] = NONE;//ȭ�鵵 ���� ������ �Ⱥ��̰� ���
			}
			

		}

		}
		
		


	}

	calculateScore();
	board.initFlag = OFF;
	format.isNew = OFF;
	if (*(flagCount) == easyMode.flagCount) {
		progressGame(&(normalMode.bombCount), &(normalMode.flagCount), &(normalMode.treasureCount));
	}
	else if (*(flagCount) == normalMode.flagCount) {
		progressGame(&(hardMode.bombCount), &(hardMode.flagCount), &(hardMode.treasureCount));
	}
	else  {
		cursorFix(D_X, D_Y, 1, FLAG_FINAL);
		exit(0);
	}
	
}

void calculateScore() {//������ ����ϴ� �Լ�
	
	//����=����*10-�̵�Ƚ��*2�� å���Ͽ���.
	format.score = format.score * 10 - format.keyCount * 2;
	
 }

void findAndCollect(int x, int y) {//�⹰ ȿ�� ó��, �б⺰��
	/* 
#define TREASURE_PLUS 0
#define BOMB_MAP 1
#define FLAG 2
#define MAN 3
#define WALL 4
#define NONE 5
#define BOMB_SCORE 6
#define BOMB_RETURN 7
#define TREASURE_DOUBLE 8
*/
	int temp_x=x, temp_y=y;//������ �־��� �÷��̾� ��ǥ�� ����ϱ� ���� �ӽú���
	
	switch (board.gameBoard[x][y]) {//�Է� ���� ��ǥ����
	case TREASURE_PLUS://������ �߰��ϴ� ������ �����Ѵٸ�,
		treasure.score -= 1;//���� �߰� ������ ������ 1���̰�,
		
		format.score += 100; break;//������ 100�� �߰��Ѵ�.

	case BOMB_MAP://���� ��ġ ��ź�̶��
		bombs.map -= 1;//���� ��ġ ��ź ������ 1 ���̰�
		
		reAllocateMap(x,y);//���� ���Ҵ��Ѵ�.

		break;

	case BOMB_SCORE://���� ��ź�̶��
		bombs.reset -= 1;//���� ��ź ������ 1���̰�


		

		format.score =0;//������ 0���� �����Ѵ�.
		break;

	case BOMB_RETURN://������ ��ź�̶��
		bombs.ret -= 1;//������ 1���̰�

		
		//�÷��̾� ��ǥ�� ���������� �ϰ�, ���� �־��� ���� ������ ��ź�� �����.
		man.x = START_X;
		man.y = START_Y;
		board.gameBoard[temp_x][temp_y] = NONE;
		break;

	case TREASURE_DOUBLE://���� 2�� �����̶��
		treasure.doubule -= 1;//������ 1���̰�
		

		if (format.score == 0) {//�����̸�
			format.score = format.score + 100;//100���� �߰����ش�.
		}
		else if (format.score < 0) {//0���ϸ�
			format.score = 0;//0���� �������ش�.
		}
		
		format.score *= 2;//2�� ���Ѵ�.
		break;

	default:break;

	}

}

int whatsThis(int x, int y) {//�Է� ���� ��ǥ�� ���� �����ϴ���

	if (board.gameBoard[x][y] == NONE) {//���ٸ�
	
		return OFF;
	}
	else {//�ִٸ�
		
		return ON;
	}
}

int canGo(int man_x,int man_y) {//�Է� ���� ��ǥ�� ���� �� �� �ִ� ������ ���θ� ������ �Լ�.(������ �浹 ����)

	if (board.gameBoard[man_x][man_y] == WALL) {//���̶��
		return OFF;//������
	}
	else {//�ƴ϶��
		return ON;//�� �� �ִ�
	}
}