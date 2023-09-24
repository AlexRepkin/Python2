#include <iostream>
#include <string>
#include <map>
using namespace std;

int lives = 3, max_lives = 3, bandages = 1, luck_meter = 0, rooms = 0, walked = 0;
map<string, int> items;

void prizes() {
    cout << "You've obtained...";
    srand((unsigned)time(0));
    switch (rand() % 10) {
    case 0:
    case 1:
    case 2: {
        cout << "Bandages! They can heal your wounds! ( +1 healed life)";
        bandages++;
        break;
    }
    case 3:
    case 4: {
        cout << "Prosthesis! It increased your maximum amount of lives! ( +1 life)";
        max_lives++;
        lives++;
        break;
    }
    case 5:
    case 6: {
        int luck = rand() % 10;
        cout << "Amulet! It gave you some luck! ( +"<<luck<<"% luck)";
        luck_meter += luck;
        items.insert(pair<string, int>("Amulet", luck));
        break;
    }
    case 7:
    case 8: {
        int luck = (rand() % 10) + 10;
        cout << "Four-leaf clover! It gave you some luck! ( +" << luck << "% luck)";
        luck_meter += luck;
        items.insert(pair<string, int>("Four-leaf clover", luck));
        break;
    }
    case 9:
        cout << "Oh no! Rat stole your prize!";
    }
}

void minigames() {
    srand((unsigned)time(0));
    if (rand() % 2) {
        int number;
        cout << "You've encountered a minigame! Pick a number from 0 to 9.";
        cin >> number;
        for (int i = 0; i < (3 + luck_meter/20); i++) {
            if (rand() % 10 == number) cout << "Congratulations, you've won! Here is your prize: ";
            prizes();
            break;
        }
    }
    else {
        //Some other minigame
    }
}

void inventory() {
    cout << "In your inventory:\n";
    for (auto elem : items) {
        cout << elem.first << " - " << elem.second << "% luck\n";
    }
}

void stats() {
    cout << "Right now your stats are:\nLuck - " << luck_meter << "%\nMaximum lives - "<<max_lives<<"\nCurrent lives - "<<lives;
}

void room() {
    walked += 1;
    srand((unsigned)time(0));
    switch (rand() % 10) {
    case 0:
    case 1:
    case 2: {
        if (rand() % 100 < luck_meter) {
            cout << "Enemy! You've lost one life! ( -1 life)";
            lives--;
            break;
        }
    }
    case 3:
    case 4:
    case 5:
    case 6: {
        cout << "Empty room";
        break;
    }
    case 7:
    case 8: {
        if (bandages > 0) {
            char agree;
            cout << "You've found an old lady. She asked you for some Bandages. Will you give them to her?\nRight now you have " << bandages << " Bandages.\n" << "Y/N?";
            cin >> agree;
            if (agree == 'Y' || agree == 'y') {
                bandages--;
                cout << "You gave her 1 Bandage. You now have " << bandages << " Bandages.";
                luck_meter += 20;
            }
            else cout << "You've excused yourself and continued your journey.";
        }
        else cout << "Empty room";
        break;
    }
    case 9:
        cout << "You've found something lying on the floor.";
        prizes();
    }
}

int main() {
    string choosing;
    cout << "Hello! Welcome to my little game, specially created for this task!\nMain idea in this game is to stay alive till the end.\nHow many rooms do you want to go through?\nRooms = ";
    cin >> rooms;
    cout << "Great! You've started your journey.";
    while (true) {
        if (lives < 1) {
            cout << "\n~~~~~Oh no! You've lost all your lives!~~~~~";
            break;
        }
        if (walked == rooms) {
            cout << "\n~~~~~Hooray! You've visited all the rooms!~~~~~";
            break;
        }
        cout << "\n\nChoose the door.\n1/ 2/ 3/ stats/ inventory/ bandages?\n";
        cin >> choosing;
        if (choosing == "1" || choosing == "2" || choosing == "3") room();
        else if (choosing == "stats" || choosing == "s") stats();
        else if (choosing == "inv" || choosing == "inventory" || choosing == "i") inventory();
        else if (choosing == "bandages" || choosing == "bandage" || choosing == "b") {
            cout << "You have " << bandages << " Bandages.\n";
            if (bandages > 0) {
                cout << "Do you want to use them? Y/N?  ";
                cin >> choosing;
                if (choosing == "Y" || choosing == "y")
                    if (lives < max_lives) {
                        bandages--;
                        lives++;
                        cout << "You've used Bandages. There are " << bandages << " Bandages left.";
                    }
                    else cout << "You already have maximum amount of lives.";
                else cout << "You decided not to use them.";
            }
        }
        else cout << "Wrong input!";
    }
    cout << "\nYou've finished your journey.";
}