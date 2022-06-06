#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::cin;
using namespace std;


//Blackjack game played via text in terminal

string playerName()
{
    string const playerName;

    cout << "Please enter your name: ";
    cin >> playerName;

    cout << '\n';
    cout << "Welcome " << playerName << ", good to see you!" << '\n';
    cout << "Grab an open seat." << '\n';
    cout << '\n' << '\n';

    return playerName;
}

int main()
{
   
    cout << '\n' << '\n';
   
   //Player Greeting
    cout << "Howdy partner, welcome to blackjack!" << '\n';
    cout << "Where the winnings are high, and the worries are low." << '\n';

    cout << '\n' << '\n';
   
    //Grab Player Name
    playerName();
    
    //First Hand
    cout << "Let's Deal!" << '\n';
    cout << '\n' << '\n';

    //Player Card Variables
    int PlayerCardA = 0;
    int PlayerCardB = 0;
    int PlayerCardC = 0;
//  int PlayerCardD = 0; commented out as not using for now
//  int PlayerCardE = 0; commented out as not using for now

    //Dealer Card Variables
    int DealerCardA = 0;
    int DealerCardB = 0;
    int DealerCardC = 0;
//  int DealerCardD = 0; commented out as not using for now
//  int DealerCardE = 0; commented out as not using for now

    //Dealer's Hand Calculation
    srand(time(0));  // Initialize random number generator.
    
    DealerCardA = (rand() % 10) + 1;
        if (DealerCardA == 1) {
            DealerCardA = 11;
        }
    DealerCardB = (rand() % 10) + 1;
        if (DealerCardB == 1 && DealerCardA != 11) {
            DealerCardB = 11;
        }

    //Dealer Blackjack Check
    if (DealerCardA + DealerCardB == 21) {
        cout << "Dealer has Blackjack, better luck next time!" << '\n';
        cout << "[A] [K]";
    }
    else {
        cout << "Dealers Hand: [" << DealerCardA << "] []" << '\n'; 
    }

    //Player Hand Calculation
    PlayerCardA = (rand() % 10) + 1;
        if (PlayerCardA == 1) {
            PlayerCardA = 11;
        }
    PlayerCardB = (rand() % 10) + 1;
        if (PlayerCardB == 1 && PlayerCardA != 11) {
            PlayerCardB = 11;
        }
        
    //Player Blackjack Check
    if (PlayerCardA + PlayerCardB == 21) {
        cout << "You have Blackjack, you win all the money!" << '\n';
        cout << "[Q] [A]";
    }
    else {
        cout << playerName << "'s Hand: [" << PlayerCardA << "] [" << PlayerCardB << "]" << '\n'; 
    }

    //Ask if Player wants to hit
    cout << "Would you like to hit? (yes/no):";
    string PlayerWillHit = "no";
    cin >> PlayerWillHit;

    if (PlayerWillHit == "yes") {
        PlayerCardC = (rand() % 10) + 1;
        //Ace Check
        if (PlayerCardC == 1 && PlayerCardA + PlayerCardB + PlayerCardC <= 11) {
            PlayerCardC = 11;
        }
    }

    //Player Bust Check
    if (PlayerCardA + PlayerCardB + PlayerCardC > 21) {
        cout << "You busted out, better luck next time!" << '\n';
        cout << playerName << "'s Hand: [" << PlayerCardA << "] [" << PlayerCardB << "] [" << PlayerCardC << "]" << '\n';
    }

    //Dealer Hand Check
    if (DealerCardA + DealerCardB < 17) {
        DealerCardC = (rand() % 10) + 1;
        //Ace Check
        if (DealerCardC == 1 && DealerCardA + DealerCardB + DealerCardC <= 11) {
            DealerCardC = 11;
        }
    }

    //Dealer Bust Check
    if (DealerCardA + DealerCardB + DealerCardC > 21) {
        cout << "The Dealer busted out, you win all the money!" << '\n';
        cout << "Dealers's Hand: [" << DealerCardA << "] [" << DealerCardB << "] [" << DealerCardC << "]" << '\n';
    }

    //Show Cards
    
    //Extra Dealer Card Check
    if (DealerCardC > 0) {
        cout << "Dealers's Hand: [" << DealerCardA << "] [" << DealerCardB << "] [" << DealerCardC << "]" << '\n';
    }
    else {
        cout << "Dealers's Hand: [" << DealerCardA << "] [" << DealerCardB << "]" << '\n';
    }
   
    //Extra Player Card Check
    if (PlayerCardC > 0) {
        cout << playerName << "'s Hand: [" << PlayerCardA << "] [" << PlayerCardB << "] [" << PlayerCardC << "]" << '\n';
    }
    else {
        cout << playerName << "'s Hand: [" << PlayerCardA << "] [" << PlayerCardB << "]" << '\n';
    }
    
    //Winner Check
    int DealersHand = DealerCardA + DealerCardB + DealerCardC;
    int PlayersHand = PlayerCardA + PlayerCardB + PlayerCardC;

    if (PlayersHand > DealersHand) {
        cout << "Looks like you win, " << playerName << ". Don't forget to grab your money!" << '\n';
    }
    else {
        cout << "Dealer wins this round, better luck next time, " << playerName << '\n';
    }

    return 0;


    //Features to add later
        //break apart code into functions
        //break apart file into multiple files and headers
        //ability to hit more cards
        //translate 10's to 10,J,Q,K
        //keep track of which cards are in play
        //cheating mechanic
        //card counting tips and mechanics
        //betting mechanic
        //promote or demote playing tables, for example nicer casinos with higher limits or getting kicked out to worse casinos or back alleys or jail
        //ascii graphics
        //more flavor text
    
 
}
