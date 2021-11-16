// the file that throw exception
// it's read data from _DCL.data

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ofstream fout; // set the 'fout <<' as the default file out
ifstream fin; // set the 'fin <<' as the default file in


int iinp, tmp = 0; // int input
string runner; // for running ???
string sinp; // stream input
pair<string,string> report_codes[2000]; // the first value are the codes, the second value are meaning of those codes


int main(){
    fin.open("_DCL.data");
    fin >> iinp;
    for(int i = 0; i < iinp; ++i){
        fin >> report_codes[i].first;
        fin >> report_codes[i].second;
    }
    fin.close();
    while(true){
        fin.open("report.code");
        runner = "";
        // for(int i = 0; i <= tmp; ++i){
            fin >> runner;
        // }
        for(int i = 0; i < iinp; ++i){
            if(report_codes[i].first == runner){
                ++tmp;
                cout << "_Dev_Console_Log (code #" << report_codes[i].first << "): " << report_codes[i].second << "\n";
                break;
            }
        }
        fin.close();
        fout.open("report.code");
        fout.close();
    }
}
