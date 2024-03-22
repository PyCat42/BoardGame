#ifndef TABLE_H
#define TABLE_H

#include "Player.h"

using namespace std;

struct Elem
{
    Player* player;
    Elem* prev;
    Elem* next;
};

class Table
{
public:
    Table();

    void printTable();
    void addPlayer();
    void moveNext();

    int getNumber();

    ~Table();
private:
    Elem* first;
    Elem* current;
    Elem* last;
    int number;


};

#endif // TABLE_H
