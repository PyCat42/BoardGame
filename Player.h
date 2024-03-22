#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Position.h"
#include <string>

using namespace std;

class Player
{
public:
    Player(string name, Position* position);
    ~Player();

    string getName();
    Position* getPosition();

    virtual void movePlayer(Direction direction);
protected:
    string name;
    Position* position;

};

#endif // PLAYER_H_INCLUDED

