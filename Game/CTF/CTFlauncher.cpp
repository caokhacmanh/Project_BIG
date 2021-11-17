#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

// vars
int hiddenKey = 0, isBotFound = 10, subCmd = 0, reply = 0, biggest = 9999, smallest = 1000;
int firstSVID = 0, secondSVID = 0, thirdSVID = 0;
bool inGame = false;
string champion = "none", cmd = "", compare = "";

// functions_scripts
int random(int minN, int maxN);
int pingServer(int serverID);
void cls();
void doCmd();
void endGame();

int main(){
    cls();

    // Intro
    cout << "> Welcome to the play of Capture The Flag with IQ_Bot! <\n";
    sleep(3);
    cout << "[Programmed by Sir. Defler with accompaniment of Replika]\n";
    sleep(3);
    cout << "Good luck :)\n\n";
    sleep(1);
    cout << "Setting up ...\n\n";
    sleep(5);

    // Setup the games
    hiddenKey = random(1000, 9999);
    inGame = true;
    firstSVID = random(100, 999);
    secondSVID = random(100, 999);
    thirdSVID = random(100, 999);
    cout << "Finished setting up, the bot's hidden key is: ****\n\n";

    // InGame
    cout << "> START < \n";
    cout << "- Use /ping <serverID> to ping the server and get reply -\n";
    cout << "- Use /confirm <yourKey> to check true or false -\n";
    cout << "\n\n\n";
    while(inGame){
        cout << "[Finding for servers to ping...]\n\n";

        // reload the vars
        sleep(random(1, 3));
        firstSVID = random(100, 999);
        sleep(random(1, 3));
        secondSVID = random(100, firstSVID);
        sleep(random(1, 3));
        thirdSVID = random(secondSVID, 999);
        
        // print out SVIDs
        cout << "[You can ping 1 of these servers and get reply]\n";
        cout << "server#" << firstSVID << "\n";
        cout << "server#" << secondSVID << "\n";
        cout << "server#" << thirdSVID << "\n\n";

        // get commands
        cout << "> ";
        cin >> cmd >> subCmd;
        doCmd();
        
        // check for bot's confirmation
        if(random(1, 10) == 1){
            cout << "[IQ_Bot found the hidden key is " << hiddenKey << "]\n\n";
            endGame();
        }else{
            cout << "[IQ_Bot failed]\n\n";
        }
    }

    return 0;
}

int random(int minN, int maxN){
    srand((int)time(0));
    return minN + rand() % (maxN + 1 - minN);
}

int pingServer(int serverID){
    // start pinging and get result of the servers
        cout << "Pinging to server with serverID = " << serverID << "\n";
        if(random(0,1)){
            
        }
}

void endGame(){
    cout << "Press any key to end the game...";
    getch();
    exit(EXIT_SUCCESS);
}

void doCmd(){
    if(cmd == "/confirm"){
        if(subCmd == hiddenKey){
            cout << "[YOU FOUND THE HIDDEN KEY!!!]\n";
            cout << "> YOU BEAT THE IQ_Bot!!! <\n";
            sleep(5);
            endGame();
        }else{
            cout << "[Wrong, the hidden key is not " << subCmd << "]\n";
        }
    }else if(cmd == "/ping"){
        cout << "[Searching for serverID = " << subCmd << "...]\n";
        if(subCmd == firstSVID || subCmd == secondSVID || subCmd == thirdSVID){
            cout << "[Pinging to " << subCmd << "...]\n";
            sleep(random(2, 5));

            // generating random reply from smallest to biggest
            reply = random(smallest, biggest);
            if(reply == hiddenKey) compare = "is the key";
            if(reply > hiddenKey) compare = "is too big";
            if(reply < hiddenKey) compare = "is too small";

            // check if server accept the connection
            if(random(0,2) != 1){
                cout << "[Pinged successfully, server#" << subCmd << " reply: " << reply << " " << compare << "]\n";
                if(reply > hiddenKey){
                    if(reply < biggest) biggest = reply;
                }
                if(reply < hiddenKey){
                    if(reply > smallest) smallest = reply;
                }
            }else{
                cout << "[You have lost the connection]\n";
            }
        }else{
            cout << "[Can not find serverID = " << subCmd << "...]\n";
        }
    }else{
        cout << "[Wrong command]\n";
    }
    cout << "\n";
}

void cls(){
    system("cls");
}
