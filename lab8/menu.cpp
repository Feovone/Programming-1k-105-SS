#pragma once
#include <iostream>
using namespace std;
int mainmenu(){
    cout  << "\t\tChoose the action" <<endl
    << "[1] Create/change value dots of element \"Triangle\"" << endl
    << "[2] Create/change value dots of element \"Rectangle\"" << endl
    << "[3] Status of dots " << endl
    << "[4] Move" << endl
    << "[5] Intersect" << endl
    << "[6] Test dots" << endl
    << "Your choice: ";
    short choice;
    cin >> choice;
    return choice;
}



