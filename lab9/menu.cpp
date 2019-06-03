#pragma once
#include <iostream>
using namespace std;
int mainmenu(){
    cout  << "\nChoose the action" <<endl
    << "[1] Add/change value CARS"<< endl
    << "[2] CARS in car's park" << endl
    << "[3] Test set of cars " << endl
    << "[4] Move car in the CITY" << endl
    << "[5] CARS in CITY" << endl
    << "[6] Move car in the PARK" << endl
    << "[7] Sorting cars in the park by ID " << endl
    << "[8] Sorting cars in the park by number" << endl
    << "[9] Delete car" << endl
    << "Your choice: ";
    short choice;
    cin >> choice;
    return choice;
}



