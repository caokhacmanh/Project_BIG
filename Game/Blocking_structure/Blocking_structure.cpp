#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string>
using namespace std;

int main(){
    system("cd .\\back_code");
    char inpkey = 'a';
    cout << "---BLOCKING_STRUCTURE---\n";
    cout << "by H1A4C3K\n\n";
    cout << "(1) One player \n" << "(2) Two players";
    inpkey = getch();
    if(inpkey == '2'){
        system("start .\\back_code\\two_players.exe");
    }else{
        system("start .\\back_code\\one_player.exe");
    }
}