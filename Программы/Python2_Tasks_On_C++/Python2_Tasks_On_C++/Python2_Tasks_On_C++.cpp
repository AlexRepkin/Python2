#include <iostream>

using std::cout;
using std::cin;

char first = 'X', second = 'O';
bool continuing, player;

char matrix[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

//void symbols() {
//    cout << "Please, choose symbol for the first player.\nCharacter - ";
//    cin >> first;
//    cout << "Please, choose symbol for the second player.\nCharacter - ";
//    cin >> second;
//}

bool checking() {
    if ((matrix[0] == matrix[1] && matrix[1] == matrix[2] && matrix[0] != ' ') || (matrix[3] == matrix[4] && matrix[4] == matrix[5] && matrix[3] != ' ') || (matrix[6] == matrix[7] && matrix[7] == matrix[8] && matrix[6] != ' ') || (matrix[0] == matrix[3] && matrix[3] == matrix[6] && matrix[0] != ' ') || (matrix[1] == matrix[4] && matrix[4] == matrix[7] && matrix[1] != ' ') || (matrix[2] == matrix[5] && matrix[5] == matrix[8] && matrix[2] != ' ') || (matrix[0] == matrix[4] && matrix[4] == matrix[8] && matrix[0] != ' ') || (matrix[2] == matrix[4] && matrix[4] == matrix[6] && matrix[2] != ' ')) return true;
    return false;
}

bool playing() {
    cout << "-------------\n|   |   |   |\n-------------\n|   |   |   |\n-------------\n|   |   |   |\n-------------\n";
    player = rand() % 2;
    int space;
    char current;
    if (player)cout << "First player plays first.\n";
    else cout << "Second player plays first.\n";
    while (true) {
        if (player) {
            cout << "\nFirst player's decision - ";
            current = first;
        }
        else {
            cout << "\nSecond player's decision - ";
            current = second;
        }
        cin >> space;
        if (matrix[space-1] == ' ') matrix[space-1] = current;
        cout << "-------------\n| " << matrix[0] << " | " << matrix[1] << " | " << matrix[2] << " |\n------------ - \n| " << matrix[3] << " | " << matrix[4] << " | " << matrix[5] << " |\n------------ - \n| " << matrix[6] << " | " << matrix[7] << " | " << matrix[8] << " |\n------------ - \n";
        if (checking()) {
            if (player) cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~First player wins!~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nWould you like to continue? 1/0?  -  ";
            else cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~Second player wins!~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nWould you like to continue? 1/0?  -  ";
            break;
        }
        player = !player;
    }
    cin >> continuing;
    return continuing;
}

int main(){
    cout << "Hey! I have prepared this small program for this task.\nThis time I've decided to make a very bad tic tac toe game.\n";
    //symbols();
    char choose;
    //cout << "Great, now that we've decided which symbol each of you have, we can start the game.\n";
    while (true) {
        cout << "\nYou are in the main menu right now. What would you like to do?\n1 - Start game\n2 - Change symbols\n3 - Exit the game\n\nInput - ";
        cin >> choose;
        if (choose == '1') {
            continuing = true;
            while (continuing) {
                playing();
                for (int i = 0; i < 9; i++) {
                    matrix[i] = ' ';
                }
            }
        }
        //if (choose == '2') symbols();
        if (choose == '3') break;
    }
    cout << "\nSee you soon!";
}