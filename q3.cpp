#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    private:
            string name;
            int score;
    public:
            Player();
            Player(int newScore, string newName);
            void setName(string newName) { name = newName; };
            void setScore(int newScore) { score = newScore; };
            string getName() { return name; };
            int getScore() { return score; };
};

void addPlayer(int &numPlayers, vector<Player> &Players);
void printPlayer(int numPlayers, vector<Player> Players);
void searchPlayer(int numPlayers, vector<Player> Players);
void removePlayer(int &numPlayers, vector<Player> &Players);


int main() 
{
    int numPlayers = 0;
    vector<Player> Players;
    int option;

    cout << "Welcome to the game!" << endl;

    while (option != 5) {
        cout << "[1] Add a new player" << endl
            << "[2] Print all players" << endl
            << "[3] See player score" << endl
            << "[4] Remove player" << endl
            << "[5] Exit" << endl;
        cin >> option;
        while (option < 1 || option > 5) {
            cout << "Enter a valid option." << endl;
            cin >> option;
        };
        switch (option) { 
            case 1: {
                addPlayer(numPlayers, Players);
                break;
            }
            case 2: {
                printPlayer(numPlayers, Players);
                break;
            }
            case 3: {
                searchPlayer(numPlayers, Players);
            }    
            case 4: {
                removePlayer(numPlayers, Players);
                break;
            }
            case 5: {
                cout << "Thank you for playing!" << endl;
            }
        }
    }
}

void addPlayer(int &numPlayers, vector<Player> &Players){
    if (numPlayers >= 10)
        cout << "10 player maximum has been reached, please delete a player entry" << endl;
    else {
        cout << "Welcome to the game!" << endl;
        cout << "Please enter your name: " << endl;
        string inputName;
        cin >> inputName;
        cout << "and your score: " << endl;
        int inputScore;
        cin >> inputScore;
        Player newPlayer(inputScore, inputName);
        Players.push_back(newPlayer);
        numPlayers++;
    }
}

void printPlayer(int numPlayers, vector<Player> Players){
    cout << "Player Scores: " << endl;
    for (int i = 0; i < numPlayers; i++)
        cout << Players[i].getName() << " " << Players[i].getScore() << endl;
}

void searchPlayer(int numPlayers, vector<Player> Players){
    bool found = false;
    cout << "Enter player name you wish to search for." << endl;
    string searchName;
    cin >> searchName;
    for (int i = 0; i < numPlayers; i++){
        if (Players[i].getName() == searchName) {
            cout << "Player found!" << endl;
            cout << Players[i].getName() << " scored " << Players[i].getScore() << " points." << endl;
            found = true;
        }
    }
    if (found == false)
        cout << "Player not found, please check spelling or try another name.";    
} 

void removePlayer(int &numPlayers, vector<Player> &Players){
    bool removed = false;
    cout << "Enter a player name you would like to remove." << endl;
    string removeName;
    cin >> removeName;
    for (int i = 0; i < numPlayers; i++){
        if (Players[i].getName() == removeName) {
            Players.erase(Players.begin() + i);
            cout << "Player erased." << endl;
            removed = true;
        }
    }
    if (removed == false)
        cout << "Player name not found, no player entry erased. Try again." << endl;
}