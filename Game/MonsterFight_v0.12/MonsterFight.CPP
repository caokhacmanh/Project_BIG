// <--CỐT TRUYỆN GAME-->
// mình trong vai 1 thằng tên "Kren" xong chơi từng màn một
// kiểu như đánh quái lấy điểm cho vui 
// luật chơi: chơi như đánh bài nhưng mà mình đánh trước, quái đánh sau, mình có thể chọn 
// sau mỗi màn được x2 số heart còn lại
// phòng thủ hay tấn công. chi tiết như này:
// -tấn công (ATK): nếu quái chọn ATK thì cả 2 bị mất máu, nếu quái chọn DEF thì quái mất máu
// -phòng thủ (DEF): nếu quái chọn DEF thì mình hồi máu DEF, nếu quái chọn ATK thì mình mất ATK(quái) - DEF
// Màn 0: giới thiệu
// Màn 1: 50 atk, 50 def, 100 heart

////////////////////////////////////////////////////////////////////////

// IMPORTANT CODES:
// srand(time(NULL));
// int r = minN + rand() % (maxN + 1 - minN)

//IMPORTANT NOTES:
//my_decide = 0(phong thu)
//my_decide = 1(tan cong)

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// #include "Cheat_tools_cpp.cpp"

//game story:
// system("");

int my_atk = 50, my_def = 50, my_heart = 300, combats = 0, num_of_combats = 0;// for Kren info
int my_coin = 10000;// for Kren's money
float medicines = 0; int num_of_medicines = 0;

void input_int(int *a){
    cin >> *a;
}

// THEME 0:
void theme_0(){
    cout << "my_atk = " << &my_atk << "   my_def = " << &my_def << "   my_heart = " << &my_heart << "    my_coin = " << &my_coin << "\n\n\n";// cheat code
    cout << "Oh...\n";
    cout << "Welcome to the MONSTER world...\n";
    cout << "ya see...this game...heheh...it's easy, huh...\n";
    cout << "So...can ya survive...though this...trap, huh...\n";
    cout << "Start...\n";
    system("pause");
}

// fight theme
void theme_all(int atk, int def, int heart, int num_theme){
    system("cls");
    cout << "\n\n\n" << "THEME:" << num_theme << "\n";
    system("pause");
    while(heart > 0 && my_heart > 0){
        if(combats == 1){
            my_atk += 400 * num_of_combats;
        }
        if(combats == 2){
            my_def += 150 * num_of_combats;
            my_heart += 250 * num_of_combats;
        }
        system("cls");
        int my_decide = 5;
        if(combats == 1){
            cout << "Kren has " << num_of_combats << " Sword(s)\n";
        }
        if(combats == 2){
            cout << "Kren has " << num_of_combats << " Armor(s)\n";
        }
        if(combats == 3){
            cout << "Kren has " << num_of_combats << " Shield(s)\n";
        }
        cout << "my_atk = " << my_atk << "   my_def = " << my_def << "   my_heart = " << my_heart << endl;
        cout << "atk = " << atk << "   def = " << def << "   heart = " << heart << endl;
        cout << "your turn atk(1) def (0)" << endl;
        input_int(&my_decide);
        srand(time(NULL));
        int decide = rand() % (2 - 1 + 1) + 1;
        if(my_decide == 1){
            if(decide == 1){
                my_heart -= atk;
                heart -= my_atk;
                cout << "Kren lose " << atk << "\n";
                cout << "monster lose " << my_atk << "\n";
                system("pause");
            }else{
                if (def < my_atk){
                    heart = heart - my_atk + def;
                    cout << "monster lose " << my_atk - def << "\n";
                }else{
                    cout << "monster's heart didn't change...hahahahhahahahahh\n";
                }
                
                system("pause");
            }
        }else if(my_decide == 0){
            if(decide == 1){
                my_heart = my_heart - atk + my_def;
                if(atk >= my_def){
                    cout << "Kren lose " << atk - my_def << "\n";
                }
                if(atk >= my_def){
                    cout << "Kren resume " << my_def - atk << "\n";
                }
                system("pause");
            }else{
                my_heart += my_def;
                cout << "Kren resume " << my_def << "\n";
            }
        }
        if(my_heart <= 0){
            if(combats == 3 && num_of_combats >= 1){
                --num_of_combats;
                my_heart += atk;
                cout << "but Kren have " << num_of_combats << " Shield(s), so Kren resume " << atk << "\n";
            }
        }
    }
    system("cls");
    if(my_heart <= 0){
        cout << "Kren have slained by monster...hahahahahahahahahahahahahahahah!!!!!!!" << "\n";
        system("pause");
    }else if(my_heart > heart){
        int b;
        my_heart *= 2;
        cout << "monster has slained by...you, heheh..." << "\n";
        cout << "Kren can increase atk(1) or def(0)" << "\n";
        input_int(&b);
        if(b == 0){
            my_def += my_heart;
        }else if(b == 1){
            my_atk += my_heart;
        }
        system("pause");
    }
}


void shops_strength(){
    system("cls");
    int choice, payment = 0;
    cout << "What type of strength do you want to increase?\n\n" << "(0)EXIT\n" << "(1)Attack\n" << "(2)Defence\n" << "(3)Heart\n";
    cin >> choice;
    switch (choice){
        case 1:
            cout << "Each Attack-point cost 1/50 coins. You pay: ";
            cin >> payment;
            if(payment <= my_coin){
                my_atk += payment * 50;
                my_coin -= payment;
                break;
            }
            break;
            
        
        case 2:
            cout << "Each Defence-point cost 1/30 coins. You pay: ";
            cin >> payment;
            if(payment <= my_coin){
                my_def += payment * 30;
                my_coin -= payment;
                break;
            }
            break;
            

        case 3:
            cout << "Each Heart cost 1/40 coins. You pay: ";
            cin >> payment;
            if(payment <= my_coin){
                my_heart += payment * 40;
                my_coin -= payment;
                break;
            }
            break;
            

        default:
            break;
    }
}



void shops_combats(){
    system("cls");
    int choice, payment = 0;
    cout << "What type of combats do you what to choose?\n\n" << "(0)EXIT\n" << "(1)Sword - each add 400 atk - 800 coins\n" << "(2)Armor - each add 150 def & 250 heart - 650 coins\n" << "(3)Shield - each save you once when you die - 500 coins\n";
    input_int(&choice);
    switch (choice){

        case 1:
        combats = 1;
            cout << "Each Sword cost 800 coins. You pay: ";
            input_int(&payment);
            // cout << payment;
            // system("pause");
            if(payment <= my_coin){
                num_of_combats += payment / 800;
                my_coin -= payment;
            }
            break;
            
        case 2:
        combats = 2;
            cout << "Each Armor cost 650 coins. You pay: ";
            input_int(&payment);
            if(payment <= my_coin){
                num_of_combats += payment / 650;
                my_coin -= payment;
            }
            break;

        case 3:
        combats = 3;
            cout << "Each Shield cost 500 coins. You pay: ";
            input_int(&payment);
            if(payment <= my_coin){
                num_of_combats += payment / 500;
                my_coin -= payment;
            }
            break;
        


        default:
            break;
    }
}



void shops_medicines(){
    system("cls");
    // TODO:
    float choice;
    system("cls");
    cout << "which medicine do you want to buy?\n\n";

    cout << "(0)EXIT\n\n";

    cout << "(1.1)Heal potion (I) - heal 20.000 hearts in time\n";
    cout << "(1.2)Heal potion (II) - heal 200.000 hearts in time\n";
    cout << "(1.3)Heal potion (III) - heal 2.000.000 hearts in time\n";
    cout << "(1.4)Heal potion (IV) - heal 20.000.000 hearts in time\n\n";

    cout << "(2.1)Poison (I) - monster lose 20.000 hearts each time\n";
    cout << "(2.2)Poison (II) - monster lose 200.000 hearts each time\n";
    cout << "(2.3)Poison (III) - monster lose 2.000.000 hearts each time\n";
    cout << "(2.4)Poison (IV) - monster lose 20.000.000 hearts each time\n\n";

    cout << "(3.1)Invisble potion (I) - you are invisible twice, but you can't hit the monster\n";
    cout << "(3.2)Invisble potion (II) - you are invisible five times, but you can't hit the monster\n";
    cout << "(3.3)Invisble potion (III) - you are invisible ten times, but you can't hit the monster\n";
    cout << "(3.4)Invisble potion (IV) - you are invisible twenty times, but you can't hit the monster\n\n";


    cin >> choice;
    
}   



void shops_pets(){
    system("cls");
}



void shops_all(){
    system("cls");
    int choice;
    cout << "my_atk = " << my_atk << "   my_def = " << my_def << "   my_heart = " << my_heart << endl;
    cout << "you have " << my_coin << " coin\n";
    cout << "What do you want to buy?\n\n" << "(0)EXIT\n" << "(1)Strength\n" << "(2)Combats\n" << "(3)Medicines\n" << "(4)Pets\n";
    cin >> choice;
    switch (choice){
        case 1:
            shops_strength();
            break;

        case 2:
            shops_combats();
            break;

        case 3:
            shops_medicines();
            break;

        case 4:
            shops_pets();
            break;

        default:
            break;
    }
}

// TODO:
void earn_money(){
    system("cls");
    // srand(time(NULL));
    // int r = minN + rand() % (maxN + 1 - minN);
    int choice, random_money, random_number, my_number;
    earn_money_goto_here:
    system("cls");
    cout << "my_atk = " << my_atk << "   my_def = " << my_def << "   my_heart = " << my_heart << endl;
    choice = 0;
    cout << "Mode:\n\n" << "(0)EXIT\n" << "(1)Easy - 1/10 - 5.000-15.000 coins\n" << "(2)Normal - 1/25 - 20.000-100.000 coins\n" << "(3)Hard - 1/50 - 250.000-1.000.000\n";
    cin >> choice;
    system("cls");
    switch (choice){
        case 1:
            cout << "Choose a number between 1 - 10\n\n";
            srand(time(NULL));
            random_number = 1 + rand() % (10 + 1 - 1);
            // cout << random_number;
            cin >> my_number;
            if(my_number == random_number){
                random_money = 5000 + rand() % (15000 + 1 - 5000);
                my_coin += random_money;
                cout << "Kren earns " << random_money << " coins\n";
            }else {
                cout << "Oh ****, Kren has earned 0000000000000 coin";
            }
            system("pause");
            goto earn_money_goto_here;
        
        case 2:
            cout << "Choose a number between 1 - 25\n\n";
            srand(time(NULL));
            random_number = 1 + rand() % (25 + 1 - 1);
            // cout << random_number;
            cin >> my_number;
            if(my_number == random_number){
                random_money = 20000 + rand() % (100000 + 1 - 20000);
                my_coin += random_money;
                cout << "Kren earns " << random_money << " coins\n";
            }else {
                cout << "Oh ****, Kren has earned 0000000000000 coin";
            }
            system("pause");
            goto earn_money_goto_here;

        case 3:
            cout << "Choose a number between 1 - 50\n\n";
            srand(time(NULL));
            random_number = 1 + rand() % (50 + 1 - 1);
            // cout << random_number;
            cin >> my_number;
            if(my_number == random_number){
                random_money = 250000 + rand() % (1000000 + 1 - 250000);
                my_coin += random_money;
                cout << "Kren earns " << random_money << " coins\n";
            }else {
                cout << "Oh ****, Kren has earned 0000000000000 coin";
            }
            system("pause");
            goto earn_money_goto_here;

        default:
            break;
    }
}

void do_something(){
    system("cls");
    int choice;
    cout << "my_atk = " << my_atk << "   my_def = " << my_def << "   my_heart = " << my_heart << endl;
    cout << "What do you want to do?\n\n" << "(0) EXIT\n" << "(1) Earn money\n" << "(2) Go to Shops\n";
    cin >> choice;
    switch (choice){
        case 1:
            earn_money();
            break;

        case 2:
            shops_all();
            break;

        default:
            break;
    }
}

int main(){
    system("cls");
    int num_theme = 1;
    int atk = 200, def = 150, heart = 100;
    theme_0();

    while(my_heart > 0){
        do_something();
        theme_all(atk, def, heart, num_theme);
        num_of_combats = 0;
        combats = 0;
        atk *= 4;
        def *= 4;
        heart *= 5;
        system("cls");
        ++num_theme;
    }
    

    
    

    
    
    
    cout << "end game..." << endl;
    cout << "THEME: " << num_theme << endl;
    system("pause");
}



// TODO:

// (1) shops_medicines
// Làm xong shops_medicines