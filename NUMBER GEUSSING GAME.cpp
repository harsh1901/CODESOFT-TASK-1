#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Function to play the game for a given difficulty level
void playGame(int difficultyChoice) {
    srand(time(0));

    int secretNumber = 0; 
    int playerChoice = 0;
    int maxChoices   = 0;
    int choiceleft   = 0;

     secretNumber = 1 + (rand() % 100);
     playerChoice;

     maxChoices;
    if (difficultyChoice == 1) {
        cout << "\nYou have 7 choices for finding the secret number between 1 and 100.";
        maxChoices = 7;
    } else if (difficultyChoice == 2) {
        cout << "\nYou have 5 choices for finding the secret number between 1 and 100.";
        maxChoices = 5;
    }

    choiceleft = maxChoices;
    for (int i = 1; i <= maxChoices; i++) {
        cout << "\n\nEnter the number:\n ";
        cin >> playerChoice;

        if (playerChoice == secretNumber) {
            cout << "Well played! You won, " << playerChoice << " is the secret number" << endl;
            cout << "\t\t\t Thanks for playing...." << endl;
            cout << "Play the game again with us!!\n\n" << endl;
            return;  // Exit the function and thus end the game
        } else {
            cout << "Nope, " << playerChoice << " is not the right number\n";
            if (playerChoice > secretNumber) {
                cout << "The secret number is smaller than the number you have chosen" << endl;
            } else {
                cout << "The secret number is greater than the number you have chosen" << endl;
            }
            choiceleft--;
            cout << choiceleft << " choices left. " << endl;
            if (choiceleft == 0) {
                cout << "You couldn't find the secret number, it was " << secretNumber << ", You lose!!\n\n";
                cout << "Play the game again to win!!!\n\n";
                return;  // Exit the function and thus end the game
            }
        }
    }
}

// Function to display the welcome message and get difficulty choice
void displayWelcomeMessage() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and 100. "
            "You'll have limited choices based on the "
            "level you choose. Good Luck!"
         << endl;
}

int main() {
    displayWelcomeMessage();

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\t";
        cout << "2 for difficult!\t";
        cout << "0 for ending the game!\n" << endl;

        int difficultyChoice = 0;
        cout << "Enter the number:\n ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            exit(0);
        } else if (difficultyChoice == 1 || difficultyChoice == 2) {
            playGame(difficultyChoice);
        } else {
            cout << "Wrong choice, Enter a valid choice to play the game! (0, 1, 2)" << endl;
        }
    }

    return 0;
}
