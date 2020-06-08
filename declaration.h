#pragma once
#ifndef __DECLARATION_H_
#define _DECLARATION_H_
//헤더파일 중복 오류 방지

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

//함수 선언
void progressMenu();
void initMode();
void printMenu(int, int);
void printBackToMenu(int, int);
void printGame(int, int);
void cursorFix(int, int, int, int);
void progressGame(int,int,int);
int canGo(int,int);
int whatsThis(int,int);
void initMap(int,int,int);
void findAndCollect(int, int);
void printGameHelp();
void initGameFormat();
void initBomb(int);
void initFlag( int);
void initTreasure(int);

//기호 상수 선언

#define D_X 9
#define D_Y 2
#define MENU_MAX 4
#define BACK_TO_MENU_MAX 2

#define WIDTH_MAX 59
#define STANDARD_CONSOLE 35
#define STANDARD_HELP_X 12
#define STANDARD_HELP_Y 0

#define HEIGHT_MAX 22
#define START_CURSOR 12

#define FLAG_MENU 0
#define FLAG_BACK_TO_MENU 1
#define FLAG_GAME 2

#define EASYMODE 0
#define NORMALMODE 1
#define HARDMODE 2

#define ON 1
#define OFF 0

#define TREASURE_PLUS 0
#define BOMB_MAP 1
#define FLAG 2
#define MAN 3
#define WALL 4
#define NONE 5
#define BOMB_SCORE 6
#define BOMB_RETURN 7
#define TREASURE_DOUBLE 8


#define VISITED 1
#define YET 0

#define BOARD_WIDTH 57
#define BOARD_HEIGHT 20

#define START_X 1
#define START_Y 1

#define HELP_X 75
#define HELP_Y 3


struct Board {
	int gameBoard[BOARD_WIDTH][BOARD_HEIGHT];
	int visited[BOARD_WIDTH][BOARD_HEIGHT];
	int realMap[BOARD_WIDTH][BOARD_HEIGHT];
	int initFlag;
}board;

struct Easy {
	int bombCount;
	int flagCount;
	int treasureCount;
}easyMode;

struct Normal {
	int bombCount;
	int flagCount;
	int treasureCount;
}normalMode;

struct Hard {
	int bombCount;
	int flagCount;
	int treasureCount;
}hardMode;

struct Man {
	int x;
	int y;
}man;

struct GameFormat {
	int score;
	long start;
	long end;
	long elapse;

}format;

#endif