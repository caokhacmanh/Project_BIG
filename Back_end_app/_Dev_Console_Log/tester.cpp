#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ofstream fout;

int main(){
    system("start _Dev_Console_Log.exe");
    string s;
    fout.open("report.code");
    while(true){
        cout << "prompt$- ";
        cin >> s;
        fout << s << "\n";
    }
}