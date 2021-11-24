#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

ofstream fout;
ifstream fin;
void clearFileData(string fileName){
    fout.open(fileName);
    fout << "";
    fout.close();
}