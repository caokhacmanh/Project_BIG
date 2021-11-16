#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string>
#include "functions_scripts.h"
using namespace std;

const int limit = 5000;
char texture_each[limit][limit];
bool pos_block[limit][limit]; // x,y for World
char inpkey = 'a'; // input key
char block_texture = '#'; // texture for blocks

void do_save(){
    freopen(".\\back_code\\saved_game.blo", "w", stdout);
    cout << "\n";
    for(int i = 0; i < limit; ++i){
        for(int j = 0; j < limit; ++j){
            if(pos_block[i][j] == 1){
                cout << i << "\n";
                cout << j << "\n";
                cout << texture_each[i][j] << "\n";
            }
        }
    }
    cout << -1 << "\n";
    cout << -1 << "\n";
}


void do_exit(){
    clr();
    cout << "Do you what to save the game? (y/n)";
    char ans = getch();
    if(ans == 'y'){
        cout << "\nSaving World...";
        freopen(".\\back_code\\saved_game.blo", "w", stdout);
        do_save();
    }
}



void get_block_texture(){
    if(inpkey != 27 && inpkey != 'a' && inpkey != 'w' && inpkey != 'd' && inpkey != 's'&& inpkey != 'q' && inpkey != 'e'){
        block_texture = inpkey;
    }
}

void do_load_world(){
    cout << "Loading Saved World...";
    freopen(".\\back_code\\saved_game.blo", "r", stdin);
    int x = 1, y = 1;
    char tmp;
    x = 1;
    for(int i = 0; i < limit; ++i){
        for(int j = 0; j < limit; ++j){
           
            pos_block[i][j] = 0;
            
        }
    }
    while(true){
        cin >> x;
        if(x == -1){
            break;
        }
        cin >> y;
        if(y == -1){
            break;
        }
        cin >> texture_each[x][y];
        pos_block[x][y] = 1;
    }
}
void do_new_void(){
    cout << "Generating Void World...";
    for(int i = 0; i < limit; ++i){
        for(int j = 0; j < limit; ++j){
            pos_block[i][j] = 0;
        }
    }
}

void do_new_shuffled(){
    srand((int) time(0));
    cout << "Generating Shuffled World...";
    for(int i = 0; i < limit; ++i){
        for(int j = 0; j < limit; ++j){
            srand(rand());
            pos_block[i][j] = (0 + rand() % (4 + 1 - 0) == 1);
            // cout << pos_block[i][j] << "\n";
            texture_each[i][j] = (34 + rand() % (126 + 1 - 0)) * (0 + rand() % (4 + 1 - 0) == 1);
            // cout << texture_each[i][j] << "\n";
        }
    }
}

class player{
private:
    int posx, posy; // var for player
    char blocking_direc; // direc: <^v>
    int direc_value;
    bool teleport; // if both true, that's bad
    friend int main();
public:
    player(int posx3, int posy3, char blocking_direc3, int direc_value3){
        this->posx = posx3;
        this->posy = posy3;
        this->blocking_direc = blocking_direc3;
        this->direc_value = direc_value3;
        gotoxy(posx, posy);
    }
    // ~player();
    void do_move(char left, char right, char down, char up){
        int check = 0;
        if(inpkey == left){
            if(pos_block[posx - 1][posy] == 0){
                check = 1;
                --posx;
            }
        }
        if(inpkey == right){
            if(pos_block[posx + 1][posy] == 0){
                check = 1;
                ++posx;
            }
        }
        if(inpkey == down){
            if(pos_block[posx][posy + 1] == 0){
                check = 1;
                ++posy;
            }
        }
        if(inpkey == up){
            if(pos_block[posx][posy - 1] == 0){
                check = 1;
                --posy;
            }
        }
        if(check == 1){
            if(teleport == false){
                cout << " ";
            }
            gotoxy(posx, posy);
            cout << blocking_direc;
            gotoxy(posx, posy);
        }


    }

    void do_blocking(){
        if(blocking_direc == '<'){
            if(pos_block[posx - 1][posy] == 0){
                pos_block[posx - 1][posy] = 1;
                gotoxy(posx - 1, posy);
                cout << block_texture;
                texture_each[posx - 1][posy] = block_texture;
                gotoxy(posx, posy);
            }else{
                pos_block[posx - 1][posy] = 0;
                gotoxy(posx - 1, posy);
                cout << " ";
                gotoxy(posx, posy);
            }
        }else if(blocking_direc == '>'){
            if(pos_block[posx + 1][posy] == 0){
                pos_block[posx + 1][posy] = 1;
                gotoxy(posx + 1, posy);
                texture_each[posx + 1][posy] = block_texture;
                cout << block_texture;
                gotoxy(posx, posy);
            }else{
                pos_block[posx + 1][posy] = 0;
                gotoxy(posx + 1, posy);
                cout << " ";
                gotoxy(posx, posy);
            }
        }else if(blocking_direc == '^'){
            if(pos_block[posx][posy - 1] == 0){
                pos_block[posx][posy - 1] = 1;
                gotoxy(posx, posy - 1);
                texture_each[posx][posy - 1] = block_texture;
                cout << block_texture;
                gotoxy(posx, posy);
            }else{
                pos_block[posx][posy - 1] = 0;
                gotoxy(posx, posy - 1);
                cout << " ";
                gotoxy(posx, posy);
            }
        }else if(blocking_direc == 'v'){
            if(pos_block[posx][posy + 1] == 0){
                pos_block[posx][posy + 1] = 1;
                gotoxy(posx, posy + 1);
                texture_each[posx][posy + 1] = block_texture;
                cout << block_texture;
                gotoxy(posx, posy);
            }else{  
                pos_block[posx][posy + 1] = 0;
                gotoxy(posx, posy + 1);
                cout << " ";
                gotoxy(posx, posy);
            }
        }
    }


    void key_to_direc(){ // to change the blocking direc
        if(inpkey == '<' || inpkey == '^' || inpkey == 'v' || inpkey == '>'){
            blocking_direc = inpkey;
        }
    }
};

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // system("cd .\\back_code");
    clr();
    cout << "PLAYER1:- Press WASD to move, E to place blocks, Q to change blocking direction\n";
    cout << "PLAYER2:- Press IJKL to move, U to place blocks, O to change blocking direction\n";
    cout << "Choose Options:\n" << "(1) New Void World\n" << "(2) New Shuffled World\n" << "(3) Load Saved World\n";
    inpkey = getch();
    clr();
    if(inpkey == '1'){
        do_new_void();
    }else if(inpkey == '2'){
        do_new_shuffled();
    }else{
        do_load_world();
    }
    cout << " Done" << "\n";
    sleep(1);
    clr();
    for(int i = 0; i < limit; ++i){
        for(int j = 0; j < limit; ++j){
            if(pos_block[i][j] == 1){
                gotoxy(i,j);
                cout << texture_each[i][j];
            }
        }
    }
    player pla1(1, 1, '>', 1), pla2(1, 1, '>', 1);
    while(true){
        inpkey = getch();
        if(inpkey == 27){
            do_exit();
            clr();
            break;
        }
        pla1.key_to_direc();
        pla2.key_to_direc();
        if(inpkey == 'j' || inpkey == 'l' || inpkey == 'k' || inpkey == 'i'){
            pla1.teleport = true;
            pla2.teleport = false;
            gotoxy(pla2.posx, pla2.posy);
        }else if(inpkey == 'a' || inpkey == 'd' || inpkey == 's' || inpkey == 'w'){
            pla2.teleport = true;
            pla1.teleport = false;
            gotoxy(pla1.posx, pla1.posy);
        }else if(inpkey != 'q' && inpkey != 'e' && inpkey != 'u' && inpkey != 'o'){
            get_block_texture();
        }
        pla1.do_move('a', 'd', 's', 'w');
        pla2.do_move('j', 'l', 'k', 'i');
        if(inpkey == 'e'){
            pla1.do_blocking();
        }
        if(inpkey == 'u'){
            pla2.do_blocking();
        }
        if(inpkey == 'q'){
            pla1.direc_value++;
            if(pla1.direc_value % 4 == 1){
                pla1.blocking_direc = '^';
                cout << '^';
                gotoxy(pla1.posx,pla1.posy);
            }
            if(pla1.direc_value % 4 == 2){
                pla1.blocking_direc = '<';
                cout << '<';
                gotoxy(pla1.posx,pla1.posy);
            }
            if(pla1.direc_value % 4 == 3){
                pla1.blocking_direc = 'v';
                cout << 'v';
                gotoxy(pla1.posx,pla1.posy);
            }
            if(pla1.direc_value % 4 == 0){
                pla1.blocking_direc = '>';
                cout << '>';
                gotoxy(pla1.posx,pla1.posy);
            }
        }
        if(inpkey == 'o'){
            pla2.direc_value++;
            if(pla2.direc_value % 4 == 1){
                pla2.blocking_direc = '^';
                cout << '^';
                gotoxy(pla2.posx,pla2.posy);
            }
            if(pla2.direc_value % 4 == 2){
                pla2.blocking_direc = '<';
                cout << '<';
                gotoxy(pla2.posx,pla2.posy);
            }
            if(pla2.direc_value % 4 == 3){
                pla2.blocking_direc = 'v';
                cout << 'v';
                gotoxy(pla2.posx,pla2.posy);
            }
            if(pla2.direc_value % 4 == 0){
                pla2.blocking_direc = '>';
                cout << '>';
                gotoxy(pla2.posx,pla2.posy);
            }
        }
    }
    
}