#include "GameBoard.h"
#include "GameBoard.cpp"
#include "Square.h"
#include "Player.h"
// #include "Dice.cpp"
// #include "Dice.h"
#include "player.cpp"
#include <thread>

#include <string>
#include <iostream>
using namespace std;

int main()
{
    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "-----------------------------------------------\n";
    //     // cout << "\n WELCOME TO IGLE ARGEN\n";
    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "-----------------------------------------------\n";
    Player playerObject;

    // Initialize colors CHECKED
    playerObject.initializeAvailableColors();

    //     // Get the number of players
    //     // int numberOfPlayers = Player::enterNumberOfPlayers();
    int numberOfPlayers = 2;

    // Create a vector to hold all players
    vector<Player> players;

    // INITIALIZE PLAYERS CHECKED!
    // playerObject.initializePlayers(players, numberOfPlayers);

    // HARDCODED FOR NOW< TO BE DELETED LATER
    Player p2("ria", "red");
    Player p1("jaswanth", "blue");
    players.push_back(p1);
    p1.flush();
    p2.flush();
    players.push_back(p2);

    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "-----------------------------------------------\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(1));
    // Square * square;
    // square = new Player();
    //     // Confirm the players' information
    playerObject.print(players, numberOfPlayers);
    cout << "\n";
    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "-----------------------------------------------\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(1));

    //     // cout << "\nSPIDERMAN - I AM SPIDERMAN! I'LL BE HELPING YOU ALONG THE WAY IN THIS GAME! LET'S HAVE A BLAST!" << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(2));

    //     // cout << "\nSPIDERMAN - CREATING THE BOARD.......\n\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(2));

    //     // CREATION OF GAME BOARD
    GameBoard game(6, 9);

    //     // cout << "\n-----------------------------------------------\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(2));
    //     // cout << "-----------------------------------------------\n\n";

    //     // Board initialization
    game.initializeBoard();

    //     // Call this to place obstacles on the board
    game.placeObstacles();

    set<int> numset; // Set to keep track of chosen tracks

    game.displayBoard();

    //     // cout << "\n-----------------------------------------------\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(2));
    //     // cout << "-----------------------------------------------\n";

    //     cout << "\nSPIDERMAN - SO, " << endl;

    bool looper = true;
    int loopCounter = 0;
    int level = 0;
    while (looper)
    {
        for (Player &player : players)
        {
            player.placeHedgehogs(game, numset, loopCounter, level);

            // cout << "\n-----------------------------------------------\n";

            game.displayBoard();

            // cout << "\n-----------------------------------------------\n";

            loopCounter++; // This check is to handle when to stop the looping. If we have 2 players, then there are 8 hedgehogs. Therefore after placement, 4 places will be left open. For cases like these, we are checking if all the placement Counters of the players have been 0 or not.
            if (loopCounter == (numberOfPlayers * 4))
            {
                looper = false;
            }
        }
    }

    //     // cout << "\n-----------------------------------------------\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(2));

    //     // cout << "-----------------------------------------------\n";

    //     // cout << "\nSPIDERMAN - THE PLACING OF HEDGEHOGS HAS BEEN DONE! I'LL NOW DISPLAY THE RULES!" << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    //     // cout << "\nSPIDERMAN - THE OBSTACLES ARE MARKED WITH X. THE PATHS ARE MADE WITH ____." << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    //     // cout << "\nSPIDERMAN - THE OBSTACLES ARE BLACKHOLES. IF YOUR HEDGEHOG FALLS INTO IT, YOUR HEDGEHOG WILL GO TO SLEEP AND WON'T WAKE UP!" << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    //     // cout << "\nSPIDERMAN - YOU NEED TO TAKE 3 HEDGEHOGS PAST THE FINISH LINE IN ORDER TO BE NAMED THE CHAMPION OF IGLE ARGEN!" << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    //     // cout << "\nSPIDERMAN - THE PLAYERS WILL PLAY IN ORDER." << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    //     // cout << "\nSPIDERMAN - THE PLAYERS CAN MOVE EITHER FORWARD OR LEFT OR RIGHT! THE NUMBER THAT COMES ON THE DICE, THAT TRACK'S HEDGEHOG WILL MOVE, AND THAT IS COMPULSARY." << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    //     // cout << "\nSPIDERMAN - AS YOU PLAY THE GAME, THINGS WILL BE CLEARER. AND DON'T WORRY, SPIDERMAN IS HERE TO HELP YOU OUT." << endl;

    //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    //     // cout << "\nSPIDERMAN - SIT TIGHT, PLAY AND FIGHT! ALL THE BEST!" << endl;

    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "-----------------------------------------------\n";

    //     // cout << "\n PLEASE PRESS 1 TO START THE GAME " << endl;

    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "-----------------------------------------------\n";

    int playerInput, trackNumber, columnNumber;
    int hedgehogNumber;

    //     // if (cin >> playerInput)
    //     // {
    //     //     cout << "\nSPIDERMAN - LET THE GAMES BEGIN" << endl;

    //     //     cout << "\n-----------------------------------------------\n";
    //     //     cout << "-----------------------------------------------\n";
    //     // }

    bool mainLoop = true;
    //     // // Dice dice;

    //     // std::this_thread::sleep_for(std::chrono::seconds(1));
    //     // cout << "\nSPIDERMAN - BOARD IS DIPLAYED AS FOLLOWS" << endl;

    //     // cout << "\n-----------------------------------------------\n";

    //     // game.displayBoard();

    //     // cout << "\n-----------------------------------------------\n";
    //     // cout << "1";

    int indexOfWinner;
    // mainLoopOfTheGame:
    while (mainLoop)
    {
        for (auto &playerIterator : players)
        {
            cout << "\nSPIDERMAN - " << playerIterator.getName() << ", PLEASE PRESS ANY KEY TO ROLL YOUR DICE - ";
            cin >> playerInput;

            // Need to be shifted to dice class
            srand(time(0));
            int random = 1 + (rand() % 6);
            int userChoice = playerIterator.movement(game, random);

            if (userChoice == 1)
            {

                if (playerIterator.intialMovement == -1)
                {
                    cout << "\nSPIDERMAN -  YOU HAVE CHOSEN MOVEMENT. YOUR HEDGEHOG WILL MOVE AHEAD!";
                    userChoice = 1;
                }

                else
                {
                    cout << "\nSPIDERMAN -  WHERE WOULD YOU LIKE TO MOVE YOUR PIECE? AHEAD?(1) LEFT?(2) RIGHT?(3) :: ";
                    cin >> userChoice;

                    // Prints the location where the user's hedgehog can move!
                    playerIterator.printUserHhgPositions(game);

                    cout << "\n\nSPIDERMAN - PLEASE SELECT THE TRACK NUMBER FROM THE ABOVE OPTIONS :: ";
                    cin >> trackNumber;

                    if (trackNumber < 1 || trackNumber > 7)
                    {
                        bool y = true;

                        while (y)
                        {
                            cout << "\nSPIDERMAN - DON'T BE SMART! ENTER CORRECT TRACK NUMBER :: ";
                            cin >> trackNumber;

                            if (trackNumber > 0 || trackNumber < 7)
                            {
                                break;
                            }
                        }
                    }

                    if (userChoice == 2 && (trackNumber - 1) < 0)
                    {

                        bool l = true;
                        while (l)
                        {
                            cout << "\nSPIDERMAN - FUNNY OF YOU TO MOVE YOUR HEDGEHOG OUT OF THE BOARD " << playerIterator.getName() << ". CHOOSE A PROPER TRACK. YOU CAN'T MOVE TO LEFT! ";

                            cin >> trackNumber;

                            if (-1 < (trackNumber - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (userChoice == 3 && (trackNumber + 1) > 6)
                    {
                        bool l = true;
                        while (l)
                        {
                            cout << "\nSPIDERMAN - FUNNY OF YOU TO MOVE YOUR HEDGEHOG OUT OF THE BOARD " << playerIterator.getName() << ". CHOOSE A PROPER TRACK. YOU CAN'T MOVE TO RIGHT! :: ";

                            cin >> trackNumber;

                            if (7 > (trackNumber + 1) && -1 < (trackNumber))
                            {
                                break;
                            }
                        }
                    }
                }

                // We are taking the column number also because what if the track has multiple open hedgehogs. The only way to differentiate that is by column number
                cout << "\nSPIDERMAN - ENTER COLUMN NUMBER :: ";
                cin >> columnNumber;

                if (game.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.empty() == 1 || game.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top().find(playerIterator.getColor()) == -1)
                {

                    bool k = true;
                    while (k)
                    {

                        cout << "\nSPIDERMAN - LOOKS LIKE THE COLUMN NUMBER YOU CHOSE IS NOT CORRECT. PLEASE RECHECK THE COLUMN NUMBER AND ENTER IT :: ";
                        cin >> columnNumber;

                        if (game.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.empty() == 1 || game.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top().find(playerIterator.getColor()) != -1)
                        {
                            break;
                        }
                    }
                }

                // ADD A CHECK WHETHER THE USER HAS GIVEN PROPER TRACK NUMBER OR NOT, BUT DO WE NEED TO THOUGH?
                playerIterator.move(userChoice, trackNumber - 1, columnNumber - 1, game, players);

                if (playerIterator.sleepingHedgehogs == 2)
                {
                    cout << "\nSPIDERMAN - " << playerIterator.getName() << " BOOO! YOU ARE OUT OF THE GAME! BETTER LUCK NEXT TIME BUDDY!" << endl;
                    for (int i = 0; i < players.size(); i++)
                    {
                        if (players[i].getName().find(playerIterator.getName()) != -1)
                        {
                            players.erase(players.begin() + i);
                            indexOfWinner = i;
                        }
                    }
                }

                if (players.size() < 2)
                {

                    cout << "\nSPIDERMAN - AND THE WINNER OF IGLE ARGEN IS " << players[indexOfWinner].getName();
                    cout << "\nSPIDERMAN - CONGRATULATIONS!!" << endl;
                    mainLoop = false;
                    break;
                }

                if (playerIterator.finishedHedgehogs == 3)
                {
                    cout << "\nSPIDERMAN - WE HAVE A WINNER FOR OUR IGLE ARGEN!! EVERONE PlEASE GIVE A HUGE ROUND OF APPLAUSE FOR " << playerIterator.getName() << endl;
                    mainLoop = false;
                    break;
                }
            }

            else if (userChoice == 2)
            {
                cout << "\nSPIDERMAN - OHO!!! " << playerIterator.getName() << " IS NOT GOING TO MOVE THEIR PIECE. WHAT A STRATEGIST!!";
            }

            cout << "\nSPIDERMAN - TIME FOR THE MANDATORY MOVEMENT!" << endl;

            // Checking if anything is available on track to even move.
            // We have used random because this is the third step that is going to happen next.
            bool check = game.checkPresenceOfHedgeHog(random - 1);

            // if we have any hedgehog available to move on the track then we allow the movement, otherwise we say there is no movement allowed for the track.
            if (check)
            {
                cout << "\nSPIDERMAN - THIS IS THE MANDATORY STEP. ON TRACK " << random << ", " << playerIterator.getName() << ", CHOOSE THE COLUMN OF THE HEDGEHOG YOU WOULD LIKE TO MOVE FORWARD! :: ";
                cin >> columnNumber;

                if (game.mainBoard[random - 1][columnNumber - 1].cellStack.empty() == 1)
                {
                    bool k = true;
                    while (k)
                    {

                        cout << "\nSPIDERMAN - LOOKS LIKE THE COLUMN NUMBER YOU CHOSE IS NOT CORRECT. PLEASE RECHECK THE COLUMN NUMBER AND ENTER IT :: ";
                        cin >> columnNumber;

                        if (game.mainBoard[random - 1][columnNumber - 1].cellStack.empty() == 1)
                        {
                            break;
                        }
                    }
                }

                // Sending hardcoded 1 since the player is supposed to move forward, random - 1 is the track
                playerIterator.move(1, random - 1, columnNumber - 1, game, players);
            }

            else
            {
                cout << "\nSPIDERMAN - LOOKS LIKE THIS TRACK IS EMPTY FOR NOW!";
            }
            // Adding the flow for obstacles

            // throw the player out of the game
            if (playerIterator.sleepingHedgehogs == 2)
            {
                cout << "\nSPIDERMAN - " << playerIterator.getName() << " BOOO! YOU ARE OUT OF THE GAME! BETTER LUCK NEXT TIME BUDDY!" << endl;

                for (int i = 0; i < players.size(); i++)
                {
                    if (players[i].getName().find(playerIterator.getName()) != -1)
                    {
                        players.erase(players.begin() + i);
                        indexOfWinner = i;
                    }
                }
            }

            if (players.size() < 2)
            {
                cout << "\nSPIDERMAN - AND THE WINNER OF IGLE ARGEN IS " << players[indexOfWinner].getName();
                cout << "\nSPIDERMAN - CONGRATULATIONS!!" << endl;
                mainLoop = false;
                break;
            }

            if (playerIterator.finishedHedgehogs == 3)
            {
                cout << "\nSPIDERMAN - WE HAVE A WINNER FOR OUR IGLE ARGEN!! EVERONE PlEASE GIVE A HUGE ROUND OF APPLAUSE FOR " << playerIterator.getName() << endl;
                mainLoop = false;
                break;
            }
        }
    }
    //     std::this_thread::sleep_for(std::chrono::seconds(5));
    //     cout << "";

    return 0;
}

// NOTES
//  Don't allow the players to move left or right in the starting