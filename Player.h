#ifndef PLAYER_H_
#define PLAYER_H_

#include<string>
using namespace std;

class Player{

    private:
        string name;
        string colour;     
        //int counterOfLeftElements;   

    public:
        void moveLeft();
        void moveRight();
        void moveAhead();

};
#endif