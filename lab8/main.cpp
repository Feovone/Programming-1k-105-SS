#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <cmath>
#include "menu.cpp"
using namespace std;
double iter(double x1, double y1, double x2 , double y2, double x3, double y3 , double x4, double y4);
class Factory{
protected:
    double x_=0;
    double y_=0;
public:

    double x() const {return x_; }
    void x(double a) {x_ = a; }
    double y() const {return y_; }
    void y(double a) {y_ = a; }

    double movef(int dx,int dy, double x, double y){
                 this->x_=x+dx;
                 this->y_=y+dy;


        }

    Factory(){};
    Factory(double a,double b):x_(a),y_(b){};
    virtual ~Factory(){};

};

class Triangle : public Factory{
public:
    void sdot(double a,double b){
    x(a);
    y(b);
    }
    void get(){
    cout << "Succesfull add dot("<<x() << ";"<< y()<<")\n"<< endl;
    }
    void print(){
    cout << "("<<x() << ";"<< y()<<")"<< endl;
    }
};

class Rectangle : public Factory{
public:
    void sdot(double a,double b){
    x(a);
    y(b);
    }
    void get(){
    cout << "Succesfull add dot("<<x() << ";"<< y()<<")\n"<< endl;
    }
    void print(){
    cout << "("<<x() << ";"<< y()<<")"<< endl;
    }
};


main(){
    Triangle dott1;
    Triangle dott2;
    Triangle dott3;
    Rectangle dot1;
    Rectangle dot2;
    Rectangle dot3;
    Rectangle dot4;
    short choice;
    bool meny=true;
    while(meny!=false && choice!='4'){
    meny=false;
    choice=mainmenu();

    if (choice == 1){
        system("cls");
        cout << "Entered your dots of triangle\n"
            << "In format \"Number of dot(1-3) X Y\"" << endl;
        int numb;
        double a,b;
        cin >> numb >> a >> b;
        if (numb > 3 || numb < 1){
            cout << "Error dots number" << endl;
        }else
        if (numb == 1){
            dott1.sdot(a,b);
            dott1.get();
        }else
        if (numb == 2){
            dott2.sdot(a,b);
            dott2.get();
        }else
        if (numb == 3){
            dott3.sdot(a,b);
            dott3.get();
        }
    meny=true;
    }
    if (choice == 2){
        system("cls");
        cout << "Entered your dots of Rectangle\n"
            << "In format \"Number of dot(1-4) X Y\"" << endl;
        int numb;
        double a,b;
        cin >> numb >> a >> b;
        if (numb > 4 || numb < 1){
            cout << "Error dots number" << endl;
        }else
        if (numb == 1){
            dot1.sdot(a,b);
            dot1.get();
        }else
        if (numb == 2){
            dot2.sdot(a,b);
            dot2.get();
        }else
        if (numb == 3){
            dot3.sdot(a,b);
            dot3.get();
        }
        if (numb == 4){
            dot4.sdot(a,b);
            dot4.get();
        }
//    cout << "Do you have add more dots? Yes[1];No[2]" << endl;
//    cin<< choice;
//    if (choice==1){
//        choic
//    }
    meny=true;
    }
    if (choice == 3){
        system("cls");
        cout << "Triangle dots" <<endl;
        cout << "1)";
        dott1.print();
        cout << "2)";
        dott2.print();
        cout << "3)";
        dott3.print();
        cout << "Rectangle dots" <<endl;
        cout << "1)";
        dot1.print();
        cout << "2)";
        dot2.print();
        cout << "3)";
        dot3.print();
        cout << "4)";
        dot4.print();
        cout << "\n";
        meny=true;
    }
    if (choice == 4){
        int dx;
        int dy;
        short fig;
        cout << "Enter your figure for move (1-2)" << endl;
        cin >> fig;
        cout << "Enter your vec move x0 y0 (new x->x+x0 )" << endl;
        cin >> dx >> dy;
        if (fig==1){
            dott1.movef(dx,dy,dott1.x(),dott1.y());
            dott2.movef(dx,dy,dott2.x(),dott2.y());
            dott3.movef(dx,dy,dott3.x(),dott3.y());
            cout << "Your figure have new coord :D" << endl;
            dott1.print();
            dott2.print();
            dott3.print();
        }
        if (fig==2){
            dot1.movef(dx,dy,dot1.x(),dot1.y());
            dot2.movef(dx,dy,dot2.x(),dot2.y());
            dot3.movef(dx,dy,dot3.x(),dot3.y());
            dot4.movef(dx,dy,dot4.x(),dot4.y());
            cout << "Your figure have new coord :D" << endl;
            dot1.print();
            dot2.print();
            dot3.print();
            dot4.print();
        }
        meny=true;
    }
    if (choice == 5){
    int a=0;
    if((dott1.x() == dott2.x() && dott1.y() == dott2.y())||(dott1.x() == dott3.x() && dott1.y()== dott3.y())||(dott2.x() == dott3.x() && dott2.y() == dott3.y())){
        cout << "\nError,triangle dots no valid\n" << endl;
    }else
    if((dot1.x() == dot2.x() && dot1.y() == dot2.y())||(dot1.x() == dot3.x() && dot1.y() == dot3.y())){
        cout << "\nError, rectangle dots no valid\n" << endl;
    }else
    if((dot2.x() == dot4.x() && dot2.y() == dot4.y())||(dot3.x() == dot4.x() && dot3.y() == dot4.y())){
        cout << "\nError, rectangle dots no valid\n" << endl;
    }else{
    system("cls");
    a+=iter(dott1.x(), dott1.y(), dott2.x(), dott2.y(), dot1.x(), dot1.y(), dot2.x(), dot2.y());
    a+=iter(dott1.x(), dott1.y(), dott2.x(), dott2.y(), dot2.x(), dot2.y(), dot3.x(), dot3.y());
    a+=iter(dott1.x(), dott1.y(), dott2.x(), dott2.y(), dot3.x(), dot3.y(), dot4.x(), dot4.y());
    a+=iter(dott1.x(), dott1.y(), dott2.x(), dott2.y(), dot4.x(), dot4.y(), dot1.x(), dot1.y());
    //second
    a+=iter(dott2.x(), dott2.y(), dott3.x(), dott3.y(), dot1.x(), dot1.y(), dot2.x(), dot2.y());
    a+=iter(dott2.x(), dott2.y(), dott3.x(), dott3.y(), dot2.x(), dot2.y(), dot3.x(), dot3.y());
    a+=iter(dott2.x(), dott2.y(), dott3.x(), dott3.y(), dot3.x(), dot3.y(), dot4.x(), dot4.y());
    a+=iter(dott2.x(), dott2.y(), dott3.x(), dott3.y(), dot4.x(), dot4.y(), dot1.x(), dot1.y());
    //thirt
    a+=iter(dott1.x(), dott1.y(), dott3.x(), dott3.y(), dot1.x(), dot1.y(), dot2.x(), dot2.y());
    a+=iter(dott1.x(), dott1.y(), dott3.x(), dott3.y(), dot2.x(), dot2.y(), dot3.x(), dot3.y());
    a+=iter(dott1.x(), dott1.y(), dott3.x(), dott3.y(), dot3.x(), dot3.y(), dot4.x(), dot4.y());
    a+=iter(dott1.x(), dott1.y(), dott3.x(), dott3.y(), dot4.x(), dot4.y(), dot1.x(), dot1.y());
    cout << "\nFigurs have " << a << " intersect\n"<< endl;
    }
    meny=true;
    }
    if (choice == 6){
    dot1.x(0);
    dot2.x(2);
    dot3.x(2);
    dot4.x(0);
    dot1.y(1);
    dot2.y(1);
    dot3.y(3);
    dot4.y(3);
    dott1.x(1);
    dott2.x(4);
    dott3.x(1);
    dott1.y(0);
    dott2.y(0);
    dott3.y(2);
    meny=true; }
}
    return 0;
}
double iter(double x1, double y1, double x2 , double y2, double x3, double y3 , double x4, double y4){

    int a=0;
    double Ua, Ub, numerator_a, numerator_b, denominator;

    denominator=(y4-y3)*(x1-x2)-(x4-x3)*(y1-y2);
    if (denominator == 0){
        if ( (x1*y2-x2*y1)*(x4-x3) - (x3*y4-x4*y3)*(x2-x1) == 0 && (x1*y2-x2*y1)*(y4-y3) - (x3*y4-x4*y3)*(y2-y1) == 0)
            a++;
         }
    else{
        numerator_a=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
        numerator_b=(x1-x2)*(y4-y2)-(x4-x2)*(y1-y2);
        Ua=numerator_a/denominator;
        Ub=numerator_b/denominator;
        if (Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1){
            a++;
        }

    }
    if (a>0){
            return 1;
    }
    else return 0;
}
