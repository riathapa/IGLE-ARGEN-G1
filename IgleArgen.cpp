#include <thread>

#include "GameBoard.h"
#include "Square.h"
#include "Player.h"
#include "Dice.cpp"
#include "Dice.h"
#include "player.cpp"

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
    
    Player p1("umema", "black");
    Player p2("ria", "red");
    // Player p3("sai", "green");
    // Player p4("gowtham", "blue");
    players.push_back(p1);
    players.push_back(p2);
    // players.push_back(p3);
    // players.push_back(p4);
    p1.flush();
    p2.flush();
    // p3.flush();
    // p4.flush();

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
    Square * game = new GameBoard(7,10);
    // GameBoard game(7, 10);

    //     // cout << "\n-----------------------------------------------\n";

    //     // std::this_thread::sleep_for(std::chrono::seconds(2));
    //     // cout << "-----------------------------------------------\n\n";

    //     // Board initialization
    game->initializeBoard();

    //     // Call this to place obstacles on the board
    game->placeObstacles();

    // Set to keep track of chosen tracks
    set<int> numset; 

    game->displayBoard();

    // //     // cout << "\n-----------------------------------------------\n";

    // //     // std::this_thread::sleep_for(std::chrono::seconds(2));
    // //     // cout << "-----------------------------------------------\n";

    // //     cout << "\nSPIDERMAN - SO, " << endl;

    Dice dice;

    bool looper = true;
    int loopCounter = 0;
    int level = 0;
    while (looper)
    {
        for (Player &player : players)
        {

            game -> placeHedgehogs(player, numset, loopCounter, level);
            // player.placeHedgehogs( game, numset, loopCounter, level);

            // cout << "\n-----------------------------------------------\n";

            game -> displayBoard();

            // cout << "\n-----------------------------------------------\n";

            loopCounter++; // This check is to handle when to stop the looping. If we have 2 players, then there are 8 hedgehogs. Therefore after placement, 4 places will be left open. For cases like these, we are checking if all the placement Counters of the players have been 0 or not.
            if (loopCounter == (numberOfPlayers * 4))
            {
                looper = false;
            }
        }
    }

    // //     // cout << "\n-----------------------------------------------\n";

    // //     // std::this_thread::sleep_for(std::chrono::seconds(2));

    // //     // cout << "-----------------------------------------------\n";

    // //     // cout << "\nSPIDERMAN - THE PLACING OF HEDGEHOGS HAS BEEN DONE! I'LL NOW DISPLAY THE RULES!" << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    // //     // cout << "\nSPIDERMAN - THE OBSTACLES ARE MARKED WITH X. THE PATHS ARE MADE WITH ____." << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    // //     // cout << "\nSPIDERMAN - THE OBSTACLES ARE BLACKHOLES. IF YOUR HEDGEHOG FALLS INTO IT, YOUR HEDGEHOG WILL GO TO SLEEP AND WON'T WAKE UP!" << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(3));
    // //     // cout << "\nSPIDERMAN - YOU NEED TO TAKE 3 HEDGEHOGS PAST THE FINISH LINE IN ORDER TO BE NAMED THE CHAMPION OF IGLE ARGEN!" << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    // //     // cout << "\nSPIDERMAN - THE PLAYERS WILL PLAY IN ORDER." << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    // //     // cout << "\nSPIDERMAN - THE PLAYERS CAN MOVE EITHER FORWARD OR LEFT OR RIGHT! THE NUMBER THAT COMES ON THE DICE, THAT TRACK'S HEDGEHOG WILL MOVE, AND THAT IS COMPULSARY." << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    // //     // cout << "\nSPIDERMAN - AS YOU PLAY THE GAME, THINGS WILL BE CLEARER. AND DON'T WORRY, SPIDERMAN IS HERE TO HELP YOU OUT." << endl;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(5));
    // //     // cout << "\nSPIDERMAN - SIT TIGHT, PLAY AND FIGHT! ALL THE BEST!" << endl;

    // //     // cout << "\n-----------------------------------------------\n";
    // //     // cout << "-----------------------------------------------\n";

    // //     // cout << "\n PLEASE PRESS 1 TO START THE GAME " << endl;

    // //     // cout << "\n-----------------------------------------------\n";
    // //     // cout << "-----------------------------------------------\n";

    int playerInput, trackNumber, columnNumber;
    int hedgehogNumber;

    // //     // if (cin >> playerInput)
    // //     // {
    // //     //     cout << "\nSPIDERMAN - LET THE GAMES BEGIN" << endl;

    // //     //     cout << "\n-----------------------------------------------\n";
    // //     //     cout << "-----------------------------------------------\n";
    // //     // }

    bool mainLoop = true;

    // //     // std::this_thread::sleep_for(std::chrono::seconds(1));
    // //     // cout << "\nSPIDERMAN - BOARD IS DIPLAYED AS FOLLOWS" << endl;

    // //     // cout << "\n-----------------------------------------------\n";

    // //     // game.displayBoard();

    // //     // cout << "\n-----------------------------------------------\n";
    // //     // cout << "1";

    int indexOfWinner;
    // mainLoopOfTheGame:
    while (mainLoop)
    {
        for (auto &playerIterator : players)
        {
            cout << "\nSPIDERMAN - " << playerIterator.getName() << ", PLEASE PRESS ANY KEY TO ROLL YOUR DICE - ";
            cin >> playerInput;

            int random = dice.roll();
            int userChoice = game -> movement(random);

            if (userChoice == 1)
            {
                cout << "\nSPIDERMAN -  WHERE WOULD YOU LIKE TO MOVE YOUR PIECE? AHEAD?(1) LEFT?(2) RIGHT?(3) :: ";
                cin >> userChoice;

                // Prints the location where the user's hedgehog can move!
                game -> printUserHhgPositions(playerIterator);

                cout << "\n\nSPIDERMAN - PLEASE SELECT THE TRACK NUMBER FROM THE ABOVE OPTIONS :: ";
                cin >> trackNumber;

                // Checks if the track entered is correct or not!
                game -> checkTrackEligibility(trackNumber, userChoice, playerIterator);

                if (userChoice == 2)
                {
                    game -> checkTrackEligibility(trackNumber, userChoice, playerIterator);
                }

                if (userChoice == 3)
                {
                    game -> checkTrackEligibility(trackNumber, userChoice, playerIterator);
                }

                // We are taking the column number also because what if the track has multiple open hedgehogs. The only way to differentiate that is by column number
                cout << "\nSPIDERMAN - ENTER COLUMN NUMBER :: ";
                cin >> columnNumber; 

                // add deep pit movement
                game -> playerTryingToMoveHedggehogFromDeepPit(trackNumber, columnNumber);

                // Takes the correct column number from the player
                game -> foundNothing(trackNumber, columnNumber, playerIterator, 1);

                game -> move(userChoice, trackNumber, columnNumber, playerIterator, players);

                // THIS REMOVES THE PLAYER FROM THE GAME
                if (playerIterator.sleepingHedgehogs == 2)
                {
                    // removes the player from the game
                    game->removePlayerFromGame(playerIterator, players, indexOfWinner);
                }

                if (players.size() < 2)
                {

                    cout << "\nSPIDERMAN - AND THE WINNER OF IGLE ARGEN IS " << players[indexOfWinner].getName();
                    cout << "\nSPIDERMAN - CONGRATULATIONS!!" << endl;
                    mainLoop = false;
                    break;
                }

                cout << "FINISHED HEDGEHOGS OF " << playerIterator.getColor() << " :: " << playerIterator.finishedHedgehogs << endl
                     << endl;
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

            // Checking if anything is available on track to even move.
            // We have used random because this is the third step that is going to happen next.
            bool check = game->checkPresenceOfHedgeHog(random);

            // if we have any hedgehog available to move on the track then we allow the movement, otherwise we say there is no movement allowed for the track.
            if (check)
            {
                cout << "\nSPIDERMAN - THIS IS THE MANDATORY STEP. ON TRACK " << random << ", " << playerIterator.getName() << ", CHOOSE THE COLUMN OF THE HEDGEHOG YOU WOULD LIKE TO MOVE FORWARD! :: ";

                // Prints the location where the user's hedgehog can move!
                game -> printUserHhgPositionsInTheTrack(playerIterator, random);

                cin >> columnNumber;

                game->playerTryingToMoveHedggehogFromDeepPit(random, columnNumber);

                game -> foundNothing(random, columnNumber, playerIterator, 2);

                // Sending hardcoded 1 since the player is supposed to move forward, random - 1 is the track
                cout << "\nCOLUMN NUMBER BEFORE GOING IN :: " << columnNumber << endl;
                game -> move(1, random, columnNumber, playerIterator, players);
            }

            if (!check)
            {
                cout << "\nSPIDERMAN - THE MANDATORY MOVEMENT CANNOT TAKE PLACE BECAUSE THERE IS NO HEDGEHOG AVAILABLE TO MOVE!" << endl;
            }

            if (playerIterator.sleepingHedgehogs == 2)
            {
                // removes the player from the game
                game->removePlayerFromGame(playerIterator, players, indexOfWinner);
            }

            if (players.size() < 2)
            {
                cout << "\nSPIDERMAN - AND THE WINNER OF IGLE ARGEN IS " << players[indexOfWinner].getName();
                cout << "\nSPIDERMAN - CONGRATULATIONS!!" << endl;
                mainLoop = false;
                break;
            }

            cout << "FINISHED HEDGEHOGS OF " << playerIterator.getColor() << " :: " << playerIterator.finishedHedgehogs << endl
                 << endl;
            if (playerIterator.finishedHedgehogs == 3)
            {
                cout << "\nSPIDERMAN - WE HAVE A WINNER FOR OUR IGLE ARGEN!! EVERONE PlEASE GIVE A HUGE ROUND OF APPLAUSE FOR " << playerIterator.getName() << endl;
                mainLoop = false;
                break;
            }
        }
    }

    return 0;
}