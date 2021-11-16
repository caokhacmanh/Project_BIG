#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <fstream>
#include ".\\back_code.h"
using namespace std;

ofstream fout;
ifstream fin;

int runner = 0, n = 0;
string words[20002];
string meanings[20002];
string user_command, opt1, opt2; // for user's input

void _help();
void _save();
void _new();
void _delete();
void _search();
void _checkout();
void _test();
void _list();

int main(){
    system("cls");
    cout << "WELCOME TO SELF_DICTIONARY (BASH VER.) BY H1A4C3K\n\n";
    cout << "loading data... ";
    fin.open("words.data");
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> words[i];
    }
    fin.close();
    fin.open("meanings.data");
    fin >> n;
    for(int i = 0; i < n;++i){
        fin >> meanings[i];
    }
    fin.close();
    cout << "Done\n";
    sleep(1);
    system("cls");
    while(true){
        system("cls");
        cout << "'#help 0 0' for commands list and offline helper\n\n";
        cin >> user_command >> opt1 >> opt2;
        if(user_command == "#help"){
            _help();
        }
        if(user_command == "#save"){
            _save();
        }
        if(user_command == "#quit"){
            return 0;
        }
        if(user_command == "#save@quit"){
            _save();
            return 0;
        }
        if(user_command == "#new"){
            _new();
        }
        if(user_command == "#delete"){
            _delete();
        }
        if(user_command == "#search"){
            _search();
        }
        if(user_command == "#checkout"){
            _checkout();
        }
        if(user_command == "#test"){
            _test();
        }
        if(user_command == "#list"){
            _list();
        }
        // sleep(3);
        getch();
    }
    
}

void _save(){
    cout << "Saving data... ";
    fout.open("words.data");
    fout << n << "\n";
    for(int i = 0; i < n; ++i){
        fout << words[i] << "\n";
    }
    fout.close();
    fout.open("meanings.data");
    fout << n << "\n";
    for(int i = 0; i < n;++i){
        fout << meanings[i] << "\n";
    }
    fout.close();
    cout << "Done\n";
}

void _new(){
    bool chk = false;
    for(int i = 0; i < n; ++i){
        if(words[i] == opt1){
            chk = true;
        }
    }
    if(chk == false){
        cout << "\n_Dev_Console_Log: Added successfully!";
        words[n] = opt1;
        meanings[n] = opt2;
        ++n;
    }else{
        cout << "\n_Dev_Console_Log: Already added!";
    }
}

void _delete(){
    bool chk = false;
    for(int i = 0; i < n; ++i){
        if(words[i] == opt1){
            chk = true;
        } 
        if(chk && i < n - 1){
            words[i] = words[i+1];
            meanings[i] = meanings[i+1];
        }
    }
    if(chk){
        --n;
        words[n] = "";
        words[n] = "";
        cout << "\n_Dev_Console_Log: Deleted successfully!";
    }else{
        cout << "\n_Dev_Console_Log: The word does not exist!";
    }
}

void _list(){
    for(int i = 0; i < n; ++i){
        if(words[i] != "") cout << words[i] << " = " << meanings[i] << "\n";
    }
}

void _search(){
    bool chk = false;
    for(int i = 0; i < n; ++i){
        if(words[i] == opt1 && words[i] == opt2){
            cout << meanings[i];
            chk = true;
            break;
        }
    }
    if(chk){
        cout << "\n_Dev_Console_Log: The word does not exist!";
    }
}

void _checkout(){
    for(int i = 0; i < n; ++i){
        if(words[i] == opt1){
            if(meanings[i] == opt2){
                cout << "It's true, bro :D";
            }else {
                cout << "You SUCKS!!!";
            }
            break;
        }
    }
}

void _test(){
    int rd = 0;
    for(int i = 0; i < 5; ++i){
        rd = random(0, n - 1);
        cout << "Question number " << i + 1 << ":\n";
        cout << words[rd] << " = ";
        cin >> opt2;
        if(opt2 == meanings[rd]) cout << "Okey, That's true, and u're good btw\n";
        if(opt2 != meanings[rd]){
            cout << "Heheh, ya'r sooooo SUCKS and FUCKING STUPID, B****\n";
            cout << "The true answer is: " << meanings[rd] << "\n";
        }
    }
}

void _help(){
    system("cls");
    cout << "/* HERE ARE THOSE COMMANDS YOU CAN USE, EACH COMMANDS HAVE TO BE TRUE */\n";
    cout << "#help 0 0" << "\n";
    cout << "#command 0 0" << "\n";
    cout << "#new <word> <meaning>" << "\n";
    cout << "#delete <word> 0" << "\n";
    cout << "#search 0 0" << "\n";
    cout << "#checkout <word> <meaning>" << "\n";
    cout << "#test 0 0" << "\n";
    cout << "#quit 0 0" << "\n";
}
