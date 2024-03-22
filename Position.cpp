#include <iostream>
#include "Position.h"

using namespace std;

Position::Position()
{
    this->row = 1;
    this->column = 'A';
}

Position::Position(int r, char c)
{
    this->setPosition(r,c);
}

void Position::setPosition(int r, char c)
{
    this->row = (r <= ROW_MAX && r >= ROW_MIN) ? r : 1;
    this->column = (c <= COLUMN_MAX && c >= COLUMN_MIN) ? c : 'A';
}

int Position::getRow()
{
    return this->row;
}

char Position::getColumn()
{
    return this->column;
}

void Position::print()
{
    cout << this->column << this->row << endl;
}

void Position::changePosition(Direction direction)
{
    switch(direction)
    {
    case UP:
        if(this->row < ROW_MAX) this->row++;
        break;
    case RIGHT:
        if(this->column < COLUMN_MAX) this->column++;
        break;
    case DOWN:
        if(this->row > ROW_MIN) this->row--;
        break;
    case LEFT:
        if(this->column > COLUMN_MIN) this->column--;
        break;
    default:
		break;
    }
}

bool Position::sameDirection(Position* pos)
{
    return this->row == pos->row || this->column == pos->column;
}

bool Position::samePosition(Position* pos)
{
    return this->row == pos->row && this->column == pos->column;
}

