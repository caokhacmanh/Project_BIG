#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string>
using namespace std;

int check;
char loll;
string namefc[8][4], group[8] = {"A", "B", "C", "D", "E", "F", "G", "H"}, nameall[32];
string name16[16], name8[8], name4[4], namefin[2], dcm[32], dcm2[16];
int scoreall[8][4], score16[16], score8[8], score4[4], scorefin[2];

int random(int a, int b){
    srand((int) time(0));
    int c = a + rand() % (b + 1 - a);
    return c;
}

void swapstr(string *a, string *b){
    string c = *a;
    *a = *b;
    *b = c;
}

void get_score_all(int check, int i, int a, int b){
    --a;
    --b;
    int more = random(0, 5);
    sleep(random(1, 2));
    int less = random(0, 5);
    if(check == 0){
        scoreall[i][a] += more;
        scoreall[i][b] += less;
        cout << namefc[i][a] << "     " << more << "|" << less << "     " << namefc[i][b] << "\n";
    }else{
        scoreall[i][b] += more;
        scoreall[i][a] += less;
        cout << namefc[i][b] << "     " << more << "|" << less << "     " << namefc[i][a] << "\n";

    }
    
}

void get_score16(int check, int a, int b){
    int more = random(0, 5);
    sleep(random(1, 3));
    int less = random(0, 5);
    if(check == 0){
        score16[a] += more;
        score16[b] += less;
        cout << name16[a] << "     " << more << "|" << less << "     " << name16[b] << "\n";
    }else{
        score16[b] += more;
        score16[a] += less;
        cout << name16[b] << "     " << more << "|" << less << "     " << name16[a] << "\n";

    }
}

void get_score8(int check, int a, int b){
    int more = random(0, 5);
    sleep(random(2, 4));
    int less = random(0, 5);
    if(check == 0){
        score8[a] += more;
        score8[b] += less;
        cout << name8[a] << "     " << more << "|" << less << "     " << name8[b] << "\n";
    }else{
        score8[b] += more;
        score8[a] += less;
        cout << name8[b] << "     " << more << "|" << less << "     " << name8[a] << "\n";

    }
}

void get_score4(int check, int a, int b){
    int more = random(0, 5);
    sleep(random(3, 5));
    int less = random(0, 5);
    if(check == 0){
        score4[a] += more;
        score4[b] += less;
        cout << name4[a] << "     " << more << "|" << less << "     " << name4[b] << "\n";
    }else{
        score4[b] += more;
        score4[a] += less;
        cout << name4[b] << "     " << more << "|" << less << "     " << name4[a] << "\n";

    }
}

void get_score_fin(int check, int a, int b){
    int more = random(0, 5);
    sleep(random(5, 10));
    int less = random(0, 5);
    if(check == 0){
        scorefin[a] += more;
        scorefin[b] += less;
        cout << namefin[a] << "     " << more << "|" << less << "     " << namefin[b] << "\n";
    }else{
        scorefin[b] += more;
        scorefin[a] += less;
        cout << namefin[b] << "     " << more << "|" << less << "     " << namefin[a] << "\n";

    }
}

int findmax(int a[], int n){
    int max = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] > a[max]){
            max = i; 
        }
    }
    return max;
}

int find2(int a[], int n){
    int max = findmax(a, n);
    int max2 = 0;
    if(max2 == max){
        max2++;
    }
    for(int i = 0; i < n; ++i){
        if(a[i] > a[max2] && i != max){
            max2 = i;
        }
    }
    return max2;
}

int main(){
    cout << "Preparing...\n";
    system("start .\\randomswap.exe");
    sleep(10);
    freopen("list_club.inp", "r", stdin);
    for(int i = 0; i < 32; ++i){
        cin >> nameall[i];
    }
    system("pause");
    cout << "\n" << "///---KNOCKOUT ROUND---///" << "\n\n\n";
    ////////////////////////////////
    int p1 = random(10, 20);
    for(int i = 0; i < p1; ++i){
        int p2 = random(0, 31);
        sleep(random(0,2));
        int p3 = random(0, 31);
        sleep(random(0,2));
        // nameall[p2].swap(nameall[p3]);
        swap(nameall[p2], nameall[p3]);
    }
    
    for(int i = 0; i < 32; ++i){
        cout << nameall[i] << "\n";
    }
    getch();
    int ano = 0;
    for(int i = 0; i < 8; ++i){
        for(int ii = 0; ii < 4; ++ii){
            namefc[i][ii] = nameall[ano];
            ++ano;
        }
    }
    for(int i = 0; i < 8; ++i){
        cout << "--[Group " << group[i] << "]--" << "\n";
        sleep(random(1, 2));
        get_score_all(random(0, 1), i, 1, 2);
        sleep(random(1, 2));
        get_score_all(random(0, 1), i, 1, 3);
        sleep(random(1, 2));
        get_score_all(random(0, 1), i, 1, 4);
        sleep(random(1, 2));
        get_score_all(random(0, 1), i, 2, 3);
        sleep(random(1, 2));
        get_score_all(random(0, 1), i, 2, 4);
        sleep(random(1, 2));
        get_score_all(random(0, 1), i, 3, 4);
        cout << "\n";
        getch();
    }
    cout << "\n\n\n\n";
    ////////////////////////////////////////
    int run = 0;
    int temp[16];
    freopen("nums.inp", "r", stdin);
    for(int i = 0; i < 16; ++i){
        cin >> temp[i];
        swap(name16[0], name16[temp[i]]);
    }
    cout << "---Move on to the 1/8:--- \n\n";
    for(int i = 0; i < 8; ++i){
        name16[run] = namefc[i][findmax(scoreall[i], 4)];
        cout << name16[run] << ": " << scoreall[i][findmax(scoreall[i], 4)] << "\n";
        ++run;
        name16[run] = namefc[i][find2(scoreall[i], 4)];
        cout << name16[run] << ": " << scoreall[i][find2(scoreall[i], 4)] << "\n";
        ++run;
    }
    getch();
    cout << "\n\n\n\n";
    ////////////////////////////////////////////
    cout << "///---ROUND 1/8---///\n\n\n";
    cout << "Swaping...";
    //TODO:
    // int temp[16];
    // freopen("nums.inp", "r", stdin);
    // for(int i = 0; i < 16; ++i){
    //     cin >> temp[i];
    //     swap(name16[0], name16[temp[i]]);
    // }
    
    cout << "Finish!, Start!" << "\n\n";
    for(int i = 0; i < 8; ++i){
        int a = i*2;
        int b = a + 1;
        sleep(random(0,2));
        get_score16(random(0,1), a, b);
        if(score16[a] > score16[b]){
            name8[i] = name16[a];
        }else if(score16[a] < score16[b]){
            name8[i] = name16[b];
        }else{
            if(random(0, 1) == 1){
                name8[i] = name16[a];
            }else{
                name8[i] = name16[b];
            }
        }
        getch();
        
    }
    cout << "\n\n";
    cout << "---Move on to the 1/4:--- \n\n";
    for(int i = 0; i < 8; ++i){
        cout << name8[i] << "\n";
    }
    getch();
    cout << "\n\n\n\n";
    ///////////////////////////////////
    cout << "///---ROUND 1/4---///\n\n\n";
    for(int i = 0; i < 4; ++i){
        int a = i*2;
        int b = a + 1;
        sleep(random(0,2));
        get_score8(random(0,1), a, b);
        if(score8[a] > score8[b]){
            name4[i] = name8[a];
        }else if(score8[a] < score8[b]){
            name4[i] = name8[b];
        }else{
            if(random(0, 1) == 1){
                name4[i] = name8[a];
            }else{
                name4[i] = name8[b];
            }
        }
        getch();
    }
    cout << "\n\n";
    cout << "---Move on to the 1/2:--- \n\n";
    for(int i = 0; i < 4; ++i){
        cout << name4[i] << "\n";
    }
    getch();
    cout << "\n\n\n\n";

    //////////////////////////////////////////////
    cout << "///---ROUND 1/2---///\n\n\n";
    for(int i = 0; i < 2; ++i){
        int a = i*2;
        int b = a + 1;
        sleep(random(0,2));
        get_score4(random(0,1), a, b);
        if(score4[a] > score4[b]){
            namefin[i] = name4[a];
        }else if(score8[a] < score8[b]){
            namefin[i] = name4[b];
        }else{
            if(random(0, 1) == 1){
                namefin[i] = name4[a];
            }else{
                namefin[i] = name4[b];
            }
        }
        getch();
    }
    cout << "\n\n";
    cout << "---Move on to the FINAL round:--- \n\n";
    for(int i = 0; i < 2; ++i){
        cout << namefin[i] << "\n";
    }
    getch();
    cout << "\n\n\n\n";

    ////////////////////////////////////////////////
    cout << "///---FINAL ROUND---///\n";
    for(int i = 0; i < 1; ++i){
        int a = 0;
        int b = 1;
        sleep(random(0,2));
        get_score_fin(random(0,1), a, b);
        cout << "The Winner Is: ";
        if(scorefin[a] > scorefin[b]){
            cout << namefin[a];
            freopen("champions.out", "a", stdout);
            cout << "\n" << time(0) << ": " << namefin[a] << "\n";
        }else{
            cout << namefin[b];
            freopen("champions.out", "a", stdout);
            cout << "\n" << time(0) << ": " << namefin[b] << "\n";
        }
    }
    getch();
    return 0;


}