#include"declaration.h"

//ESC 온오프 플래그
#define OFF_ESC 0
#define ON_ESC 1

int flag_ESC=OFF_ESC;
int input;//입력 키

void initTreasure(int trasureCount) {//보물 설치 함수
	int x, y;
	int treasure_plus, treasure_double;


	//입력 받은 인자에 대해 /2을 해주어 각각 대입한다.

	treasure_double = trasureCount / 2;
	treasure_plus = trasureCount / 2;

	treasure.doubule = treasure_double;
	treasure.score = treasure_plus;

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y를 랜덤하게 설정한다.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_plus > 0) {//만약 x,y좌표의 위치가 방문한 적이 없고 아직 점수 100점 보물이 남아 있다면

				board.gameBoard[x][y] = TREASURE_PLUS;//데이터에 보물 설치
				treasure_plus--;
				board.visited[x][y] = VISITED;//방문했다고 체크
				board.view[x][y] = FLAG;//화면에는 깃발로 설치
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y를 랜덤하게 설정한다.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && treasure_double > 0) {//만약 x,y좌표의 위치가 방문한 적이 없고 아직 두배 점수 보물이 남아 있다면

				board.gameBoard[x][y] = TREASURE_DOUBLE;//데이터에 보물 설치
				treasure_double--;
				board.visited[x][y] = VISITED;//방문했다고 체크
				board.view[x][y] = FLAG;//화면에는 깃발로 설치
			}
		}
	}
}

void initBomb(int bombCount) {//폭탄을 설치하는 함수
	int x, y;
	int bomb_reset, bomb_map, bomb_return;

	//입력 받은 인자에 대해 /3을 해주어 각각 대입한다.
	bomb_reset = bombCount / 3;
	bomb_map = bombCount / 3;
	bomb_return = bombCount / 3;

	bombs.reset = bomb_reset;
	bombs.map = bomb_map;
	bombs.ret = bomb_return;

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y를 랜덤하게 설정한다.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_reset > 0) {//만약 x,y좌표의 위치가 방문한 적이 없고 아직 reset 폭탄이 남아 있다면

				board.gameBoard[x][y] = BOMB_SCORE;//데이터에 reset 폭탄 설치
				bomb_reset--;
				board.visited[x][y] = VISITED;//방문했다고 체크
				board.view[x][y] = FLAG;//화면에는 깃발로 설치
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y를 랜덤하게 설정한다.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_map > 0) {//만약 x,y좌표의 위치가 방문한 적이 없고 아직 랜덤 재배치 폭탄이 남아 있다면

				board.gameBoard[x][y] = BOMB_MAP;//데이터에는 폭탄 설치
				bomb_map--;
				board.visited[x][y] = VISITED;//방문했다고 체크
				board.view[x][y] = FLAG;//화면에는 깃발로 설치
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//x,y를 랜덤하게 설정한다.
			x = rand() % BOARD_WIDTH;
			y = rand() % BOARD_HEIGHT;
			if (board.visited[x][y] == YET && bomb_return > 0) {//만약 x,y좌표의 위치가 방문한 적이 없고 아직 시작지점 점프 폭탄이 남아 있다면

				board.gameBoard[x][y] = BOMB_RETURN;//데이터에 폭탄 설치
				bomb_return--;
				board.visited[x][y] = VISITED; //방문했다고 체크
				board.view[x][y] = FLAG;//화면에는 깃발로 설치
			}
		}
	}
}


void reAllocateMap(int x, int y) {//배치를 재할당하는 함수

	int bomb_reset, bomb_map, bomb_return;
	int treasure_plus, treasure_double;




	treasure_double = treasure.doubule;
	treasure_plus = treasure.score;

	bomb_reset = bombs.reset;
	bomb_map = bombs.map;
	bomb_return = bombs.ret;

	//벽 초기화

	initWall();

	//플레이어는 제자리에 위치해야함.

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




void initMap(int bombCount, int flagCount, int trasureCount) {//맵 초기화 함수


	



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

	//초기화했다고 플래그에 저장
	board.initFlag = ON;

}

void initWall() {//벽을 초기화하는 함수
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (i == 0 || j == 0 || i == BOARD_WIDTH - 1 || j == BOARD_HEIGHT - 1) {//동서남북 외벽에만
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


void backToMain(int* bombCount, int* flagCount, int* trasureCount) {//일시 정지 및 메인 돌아가기 함수
	int cursorCount_back = 1;//커서 위치를 나타내는 변수
	while (1) {
		//백 투 메인 매뉴 출력
		cursorFix(D_X, D_Y, cursorCount_back, FLAG_BACK_TO_MENU);
	
		input = _getch();
		if (input == 224 || input == 0) {
			input = _getch();

			switch (input) {
			case 72://위
				
				if (cursorCount_back != 1) {
					--cursorCount_back;
				}
				break;

			case 80://아래
				
				if (cursorCount_back != 2) {
					++cursorCount_back;
				}
				break;

			default:break;
			}

		}

		if (input == 13) {//엔터 키를 누른 경우
			flag_ESC = OFF_ESC;//ESC키를 껏다고 알림
			if (cursorCount_back == 1) {//예를 누른 경우

				board.initFlag = OFF;//게임 보드 다시 초기화

				//메뉴로 다시 돌아간다.
				progressMenu();

			}
			else {
				progressGame(bombCount, flagCount, trasureCount);//게임 다시 진행
				
			}
		}
		



	}
}
void initGameFormat() {//게임 포맷 초기화 함수
	//game init
	if (format.isNew == ON) {//포맷이 처음 만들어졌으면(=게임 클리어가 아닌, 메인 메뉴에서 선택했으면)
		format.score = 0;//점수를 0으로 설정. 아니라면 누적됨.
	}
	
	format.keyCount =600;//이동횟수는 600으로 초기화
}


extern void progressGame(int* bombCount, int* flagCount, int* trasureCount) {//게임을 진행시키는 함수
	
	int temp_x, temp_y;//이전에 있었던 플레이어 좌표를 기록하기 위한 임시변수
	int canGo_flag=OFF;//충돌 여부를 나타내는 플래그

	initGameFormat();//게임 포맷을 초기화한다.

	if (board.initFlag == OFF) {//맵이 초기화된 적 없으면 맵을 초기화한다.
      initMap((*bombCount), (*flagCount), (*trasureCount));
	}
	
	cursorFix(D_X, D_Y, 1, FLAG_GAME);

	while (treasure.doubule+treasure.score>0) {//보물 개수가 0보다 큰 동안 반복한다.

		if (flag_ESC == ON_ESC) {//ESC를 누른 경우
		
			//백 투 메인 호출
			backToMain(bombCount, flagCount, trasureCount);
		}
		else {
			//아니라면 게임 화면 출력
			cursorFix(D_X, D_Y, 1, FLAG_GAME);
		}

		input = _getch();
		if (flag_ESC==OFF_ESC&& input == 27) {//처음 ESC키 눌렀을 경우 ESC를 눌렀다고 플래그에 저장
			
			flag_ESC = ON_ESC;
		}
		else if (flag_ESC == ON_ESC && input == 27) {//ESC를 누른 상태일 경우 플래그 오프
			flag_ESC = OFF_ESC;
		}
		else {//ESC키가 아닌 입력에 대해서
			if (input == 224 || input == 0) {//방향키라면
			input = _getch();
			//이전 좌표 임시 저장
			temp_x = man.x;
			temp_y = man.y;	

			//일단 갈 수 없다고 저장
			canGo_flag = OFF;

			//이동 횟수 1 감소
			format.keyCount--;
			switch (input) {//방향키에 대해서
				
			case 72://위
				if (canGo(man.x,man.y - 1)==ON) {//위로 갈 수 있으면
					man.y = man.y -1;//y좌표 1감소하고 갈 수 있다고 플래그에 저장
					canGo_flag = ON;
				}
				

				break;

			case 75://왼
				if (canGo(man.x - 1,man.y)== ON) {//왼쪽으로 갈 수 있으면
					man.x = man.x -1 ;//x좌표 1감소하고 갈 수 있다고 플래그에 저장
					canGo_flag = ON;
				}
			
				break;

			case 77://오른쪽
				if (canGo(man.x + 1,man.y)== ON) {//오른쪽으로 갈 수 있으면
					man.x = man.x + 1;//x좌표 1증가하고 갈 수 있다고 플래그에 저장
					canGo_flag = ON;
				}
				
				break;

			case 80://아래
				if (canGo(man.x,man.y + 1)== ON) {//아래로 갈 수 있으면
					man.y = man.y + 1;//y좌표 1증가하고 갈 수 있다고 플래그에 저장
					canGo_flag = ON;
				}
				
				break;

			default:break;
			}//switch 문 끝

			if (canGo_flag == ON) {//갈 수 있으면
				
				if (whatsThis(man.x, man.y)==ON) {//게다가 무언가 존재하고 있으면
					findAndCollect(man.x, man.y);//기물의 효과 처리
				}

				board.gameBoard[man.x][man.y] = MAN;//이동한 곳에 플레이어 출력
			    board.gameBoard[temp_x][temp_y] = NONE;//있었던 곳은 none으로 처리해서 궤적을 없앰
				board.view[temp_x][temp_y] = NONE;//화면도 역시 궤적이 안보이게 출력
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

void calculateScore() {//점수를 계산하는 함수
	
	//점수=점수*10-이동횟수*2로 책정하였다.
	format.score = format.score * 10 - format.keyCount * 2;
	
 }

void findAndCollect(int x, int y) {//기물 효과 처리, 분기별로
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
	int temp_x=x, temp_y=y;//이전에 있었던 플레이어 좌표를 기록하기 위한 임시변수
	
	switch (board.gameBoard[x][y]) {//입력 받은 좌표에서
	case TREASURE_PLUS://점수를 추가하는 보물이 존재한다면,
		treasure.score -= 1;//점수 추가 보물의 개수를 1줄이고,
		
		format.score += 100; break;//점수를 100점 추가한다.

	case BOMB_MAP://랜덤 배치 폭탄이라면
		bombs.map -= 1;//랜덤 배치 폭탄 개수를 1 줄이고
		
		reAllocateMap(x,y);//맵을 재할당한다.

		break;

	case BOMB_SCORE://점수 폭탄이라면
		bombs.reset -= 1;//점수 폭탄 개수를 1줄이고


		

		format.score =0;//점수를 0으로 리셋한다.
		break;

	case BOMB_RETURN://시작점 폭탄이라면
		bombs.ret -= 1;//개수를 1줄이고

		
		//플레이어 좌표를 시작점으로 하고, 원래 있었던 곳은 궤적과 폭탄을 지운다.
		man.x = START_X;
		man.y = START_Y;
		board.gameBoard[temp_x][temp_y] = NONE;
		break;

	case TREASURE_DOUBLE://점수 2배 보물이라면
		treasure.doubule -= 1;//개수를 1줄이고
		

		if (format.score == 0) {//빵점이면
			format.score = format.score + 100;//100점을 추가해준다.
		}
		else if (format.score < 0) {//0이하면
			format.score = 0;//0으로 복구해준다.
		}
		
		format.score *= 2;//2를 곱한다.
		break;

	default:break;

	}

}

int whatsThis(int x, int y) {//입력 받은 좌표에 무언가 존재하는지

	if (board.gameBoard[x][y] == NONE) {//없다면
	
		return OFF;
	}
	else {//있다면
		
		return ON;
	}
}

int canGo(int man_x,int man_y) {//입력 받은 좌표에 대해 갈 수 있는 곳인지 여부를 따지는 함수.(벽과의 충돌 여부)

	if (board.gameBoard[man_x][man_y] == WALL) {//벽이라면
		return OFF;//못간다
	}
	else {//아니라면
		return ON;//갈 수 있다
	}
}