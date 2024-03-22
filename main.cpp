#include <iostream>
#include "Table.h"

using namespace std;

void tableTest()
{
    Table* tab = new Table();

    int num;
    cout << "Enter number of players: ";
    cin >> num;

    while(num > 0)
    {
        tab->addPlayer();
        num--;
    }

    cout << "Start" << endl;
    tab->printTable();

    while(tab->getNumber() > 1)
    {
        tab->moveNext();
        tab->printTable();
    }

    delete tab;
}

int main()
{

    tableTest();

    return 0;
}
