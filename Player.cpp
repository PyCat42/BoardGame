#include "Player.h"
#include <iostream>

using namespace std;

// class Player

Player::Player(string name, Position* position)
{
    this->name = name;
    this->position = position;
}

string Player::getName()
{
    return this->name;
}

Position* Player::getPosition()
{
    return this->position;
}

void Player::movePlayer(Direction direction)
{
    this->position->changePosition(direction);
}

Player::~Player()
{
	delete this->position;
}
