#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string>

void gotoxy(int posX, int posY)
{
posX *= 2;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

int random(int a, int b){
    srand((int) time(0));
    int c = a + rand() % (b + 1 - a);
    return c;
}

void clr(){
    system("cls");
}