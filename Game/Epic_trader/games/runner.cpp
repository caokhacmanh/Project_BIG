#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

char user_chance = '0';

int main(){
    cout << "Options: \n";
    cout << "(1) Explore my Village\n";
    cout << "(2) Find new Village (The recent Village will be disapeared)\n";
    cout << "(3) Create a Village myself (The recent Village will not be disapared\n";

    switch(user_chance){
        case '1':
            system("start my_village.exe");
            break;
        case '2':
            system("start find_village.exe");
            break;
        default:
            system("start new_village.exe");
            break;
    }
}