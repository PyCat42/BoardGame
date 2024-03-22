#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

#define ROW_MAX 8
#define ROW_MIN 1
#define COLUMN_MAX 'H'
#define COLUMN_MIN 'A'

enum Direction
{
    UP, RIGHT, DOWN, LEFT
};

class Position
{
public:
    Position();
    Position(int r, char c);

    void setPosition(int r, char c);
    int getRow();
    char getColumn();

    void print();
    void changePosition(Direction direction);
    bool sameDirection(Position* pos);
    bool samePosition(Position* pos);

private:
    int row;
    char column;
};

#endif // POSITION_H_INCLUDED

