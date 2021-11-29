#include <bits/stdc++.h>
#include <fstream>
#include ".\\back_code.cpp"
#include ".\\vars.cpp"
using namespace std;

// paras
ofstream fout; // set the 'fout <<' as the default file out
ifstream fin; // set the 'fin <<' as the default file in
string tempoMessages;
bool chk = false;

int main(){
    fin.open("_DCL.data");
    // fout.open("_DCL.data");
    while(tempoMessages != "endConsoleLog"){
        fin >> tempoMessages;
        cout << tempoMessages << "\n";
    }
    fin.close();
}