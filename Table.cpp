#include "Table.h"
#include <iostream>

using namespace std;

Table::Table()
{
    this->first = nullptr;
    this->last = nullptr;
    this->current = nullptr;
    this->number = 0;
}

int Table::getNumber()
{
    return this->number;
}

void Table::printTable()
{
    char table[ROW_MAX][COLUMN_MAX]; //matrix of -

    for(int r = ROW_MAX; r >= ROW_MIN; r--)
    {
        for(int c = COLUMN_MIN; c <= COLUMN_MAX; c++)
        {
            table[r - 1][c - 'A'] = '-';
        }
    }

    Elem* element = this->first; //going through the list
    while(element)
    {
        // change - with first letter of players name
        table[element->player->getPosition()->getRow()- 1][element->player->getPosition()->getColumn()- 'A'] = element->player->getName()[0];
        element = element->next;
    }

    for(int r = ROW_MAX; r >= ROW_MIN; r--)
    {
        for(int c = COLUMN_MIN; c <= COLUMN_MAX; c++)
        {
            cout << table[r - 1][c - 'A'] << " "; //print final table
        }
        cout << endl;
    }
    cout << endl;

}

void Table::addPlayer()
{
    Player* p = nullptr;

    char c;
    int r;
    cout << "Enter player's position (first enter column (A to H) and then enter row (1 to 8)";
    cin >> c >> r;
    Position* pos = new Position(r, c);

    string name;
    cout << "Enter player's name: ";
    cin >> name;

    p = new Player(name, pos);

    Elem* element = new Elem; // new list element
    element->player = p;
    element->next = nullptr;
    element->prev = nullptr;

    if(this->first == nullptr) //if this is first entered player
    {
        this->first = element;
        this->last = element;
        this->current = element;
    }
    else //if there are already players added
    {
        element->prev = this->last;
        this->last->next = element;
        this->last = element;
    }

    this->number++;
}

void Table::moveNext()
{
    cout << "To move players enter: " << endl << " 0 for UP" << endl << " 1 for RIGHT" << endl << " 2 for DOWN" << endl << " 3 for LEFT" << endl;
    cout << endl;

    int direction;
    cout << "Direction for " << this->current->player->getName() << ": ";
    cin >> direction;
    this->current->player->movePlayer((Direction) direction);

    Elem* element = this->first;
    while(element)
    {
        if(element != this->current && element->player->getPosition()->samePosition(current->player->getPosition())) // same position as some other player
        {
            if(element == this->first) this->first = this->first->next; //eat first
            if(element == this->last) this->last = this->last->prev; //eat last
            if(element->next) element->next->prev = element->prev; //eat player in the middle
            if(element->prev) element->prev->next = element->next;
            delete element; //delete player
            this->number--;
            break; //cannot eat two players at once
        }
        element = element->next;
    }

    this->current = this->current->next; //next player
    if(this->current == nullptr) this->current = this->first; //hit the end of the list, go to beginning
}

Table::~Table()
{
    while(this->first != nullptr)
    {
        Elem* old = this->first;
        this->first = this->first->next;
        delete old->player;
        delete old;
    }

    this->first = nullptr;
    this->last = nullptr;
    this->current = nullptr;
    this->number = 0;
}
