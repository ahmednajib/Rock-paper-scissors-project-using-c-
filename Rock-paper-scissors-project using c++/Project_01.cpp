#include <conio.h> 
#include <iostream>
#include <stdlib.h>

using namespace std;

enum enChoiceType { Stone = 1, Paper = 2, Scissore = 3 };

int RandomNumber(int From, int To) {

    int RandumNumber = rand() % (To - From + 1) + From;
    return RandumNumber;
}

int ReadNumberInRange( int From,int To ) {
    int Number = 0;
    do {

        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}

enChoiceType PlayerChoices() {
    int PlayerChoice = 0;

    cout << "Your Choice : [1] : Stone , [2] : Paper, [3] : Scissore ? ";

    PlayerChoice = ReadNumberInRange(1, 3);

    return (enChoiceType)PlayerChoice;
}

enChoiceType ComputerChoices() {
    int ComputerChoice = 0;

    ComputerChoice = RandomNumber(1, 3);
    return (enChoiceType)ComputerChoice;
}

int TheWinner(enChoiceType PlayerChoice, enChoiceType ComputerChoice) {

    if (enChoiceType::Paper == PlayerChoice && enChoiceType::Paper == ComputerChoice) {
        cout << "Player choice : Paper\n";
        cout << "Player choice : Paper\n";
        cout << "Round winner  : [No winner]\n";
        system("Color 1B");
        return 0;
    }
        else if (enChoiceType::Scissore == PlayerChoice && enChoiceType::Scissore == ComputerChoice){
        cout << "Player choice   : Scissore\n";
        cout << "Computer choice : Scissore\n";
        cout << "Round winner    : [No winner]\n";
        system("Color 1B");
        return 0;
        }
        else if(enChoiceType::Stone == PlayerChoice && enChoiceType::Stone == ComputerChoice) {
        cout << "Player choice   : Stone\n";
        cout << "Computer choice : Stone\n";
        cout << "Round winner    : [No winner]\n";
        system("Color 1B");
        return 0;
        }
        else if (enChoiceType::Stone == PlayerChoice && enChoiceType::Scissore == ComputerChoice) {
        cout << "Player choice   : Stone\n";
        cout << "Computer choice : Scissore\n";
        cout << "Round winner    : [Player]\n";
        cout << system("Color a1");
        return 1;
    }
        else if (enChoiceType::Scissore == PlayerChoice && enChoiceType::Paper == ComputerChoice) {
        cout << "Player choice   : Scissore\n";
        cout << "Computer choice : Paper\n";
        cout << "Round winner    : [Player]\n";
        cout << system("Color a1");
        return 1;
    }
        else if (enChoiceType::Paper == PlayerChoice && enChoiceType::Stone == ComputerChoice) {
        cout << "Player choice   : Paper\n";
        cout << "Computer choice : Stone\n";
        cout << "Round winner    : [Player]\n";
        system("Color a1");
        return 1;
    }
        else if (enChoiceType::Scissore == PlayerChoice && enChoiceType::Stone == ComputerChoice) {
        cout << "Player choice   : Scissore\n";
        cout << "Computer choice : Stone\n";
        cout << "Round winner    : [Computer]\a\n";
        system("Color 4F");
        return 2;
    }
        else if (enChoiceType::Paper == PlayerChoice && enChoiceType::Scissore == ComputerChoice) {
        cout << "Player choice   : Paper\n";
        cout << "Computer choice : Scissore\n";
        cout << "Round winner    : [Computer]\a\n";
        system("Color 4F");
        return 2;
    }
        else if (enChoiceType::Stone == PlayerChoice && enChoiceType::Paper == ComputerChoice) {
        cout << "Player choice   : Stone\n";
        cout << "Computer choice : Paper\n";
        cout << "Round winner    : [Computer]\a\n";
        system("Color 4F");
        return 2;
    }
}

void FinalWinner(int P,int C) {
    if ( P > C ){
        cout << "[Player]";
    }
    else if (C > P) {
        cout << "[Computer]";
    }
    else {
        cout << "[No winner]";
    }
}

void ShowGameOverAndResult(int PWins, int CWins, int DTimes, int GameRounds) {

    cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\n--------------------------------------+++ GAME OVER +++-----------------------------------------------------------------\n";
    cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\n--------------------------------------+++ GAME RESULTS +++--------------------------------------------------------------\n";
    cout << "Game Rounds        : " << GameRounds << endl;
    cout << "Player won times   : " << PWins << endl;
    cout << "Computer won times : " << CWins << endl;
    cout << "Draw times         : " << DTimes << endl;
    cout << "Final winner       : ";
    FinalWinner(PWins, CWins);
    cout << endl;
}

void Game() {
    cout << "How many rounds do you want to play from 1 to 10 :\n";
    int GameRounds = ReadNumberInRange(1,10);
    int CWins=0,PWins=0,DTimes=0;
    enChoiceType PlayerChoice, ComputerChoice;
    int Winner;
    for (int i = 0; i < GameRounds; i++) {
    
        cout << "Round [ " << i + 1 << " ] begins : " << endl;

        PlayerChoice = PlayerChoices();
        ComputerChoice = ComputerChoices();
        cout << "\n---------------------------------------------Round [" << i + 1 << "] -----------------------------------------------\n";
        
        Winner = TheWinner(PlayerChoice, ComputerChoice);
        if (Winner == 0) {
            DTimes++;
        }
        else if (Winner == 1) {
            PWins++;
        }
        else {
            CWins++;
        }
    }
    ShowGameOverAndResult(PWins, CWins, DTimes, GameRounds);
}

void ResetScreen() {
    system("cls");
    system("color 0F"); }

void StartGame() {

    char PlayAgain;
    do {
        ResetScreen();
        Game();
        cout << "Dou you want to play again ? y / n ? \n";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    
    StartGame();
    
    return 0;
}