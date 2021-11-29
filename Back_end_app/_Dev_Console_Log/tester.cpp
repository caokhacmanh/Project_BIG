#include <bits/stdc++.h>
#include <fstream>
#include ".\\back_code.cpp"
using namespace std;

ofstream fout;

void clearFileData(string fileName){
    fout.open(fileName);
    fout << "";
    fout.close();
}

int main(){
    clearFileData(".\\\\report.code");
    system("start _Dev_Console_Log.exe");
    string s;
    cout << "uncool\n";
    cout << "endConsoleLog\n";
}