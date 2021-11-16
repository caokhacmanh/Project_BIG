#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string>
using namespace std;

int random(int a, int b){
    srand((int) time(0));
    int c = a + rand() % (b + 1 - a);
    return c;
}

int main(){
    int n = random(3, 5);
    cout << "Preparing for the Tournament...";
    int b = n - 1;
    sleep(random(1, 5));
    freopen("list.inp", "r", stdin);
    freopen("list_club.inp", "w", stdout);
    string a[198];
    for(int i = 0; i < 198; ++i){
        cin >> a[i];
    }
    for(int x = 0; x < n; ++x){
        for(int i = 0; i < 198; ++i){
            if((i+1)%n == b){
                cout << a[i] << "\n";
            }
        }
        --b;
    }
    
    b=n-1;
    freopen("list.inp", "w", stdout);
    freopen("list_club.inp", "r", stdin);
    for(int x = 0; x < n; ++x){
        for(int i = 0; i < 198; ++i){
            if((i+1)%n == b){
                cout << a[i] << "\n";
            }
        }
        --b;
    }
    ////////////////////////////////
    sleep(random(1, 5));
    freopen("nums.inp", "r", stdin);
    b=n-1;
    // freopen("nums.inp", "w", stdout);
    for(int i = 0; i < 16; ++i){
        cin >> a[i];
    }
    freopen("nums.inp", "w", stdout);
    for(int x = 0; x < n; ++x){
        for(int i = 0; i < 16; ++i){
            if((i+1)%n == b){
                cout << a[i] << "\n";
            }
        }
        --b;
    }
    
}