#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <fstream>

/////CODE///////


int random(int minN, int maxN){
    srand((int)time(0));
    return minN + rand() % (maxN + 1 - minN);
}