#ifndef BOARD_H_
#define BOARD_H_

#include<stack>
#include<queue>

class Square{

    private:
        int rnum, cnum;
        int * * board;

        // stack<int> hedgehogStack;
        // queue<int> hedgehogQueue;
         

    public:
        void createBoard();
        virtual void display();

};

class Obstacle : public Square{

    private:

    public:

};

class Ob1 : public Obstacle{

};

class Ob2 : public Obstacle{

};

class Ob3 : public Obstacle{

};

class Ob4 : public Obstacle{

};

class Ob4 : public Obstacle{

};

class Ob5 : public Obstacle{

};
#endif

//Rename the class