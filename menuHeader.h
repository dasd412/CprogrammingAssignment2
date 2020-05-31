#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
void printMenu(int, int);

#define STANDARD_CONSOLE 35
#define D_X 9
#define D_Y 2
#define MENU_MAX 4
#define WIDTH_MAX 59
#define HEIGHT_MAX 22
#define START_CURSOR 12

char* menus[MENU_MAX] = { "EASY","NORMAL","HARD","EXIT" };