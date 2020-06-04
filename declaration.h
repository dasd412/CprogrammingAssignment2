#pragma once
#ifndef __DECLARATION_H_
#define _DECLARATION_H_
//헤더파일 중복 오류 방지

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//함수 선언
void progressMenu();

void printMenu(int, int);
void printBackToMenu(int, int);
void printGame(int, int);
void cursorFix(int, int, int, int);
void progressGame();

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



#endif