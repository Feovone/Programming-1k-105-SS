#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <cmath>
#include "menu.cpp"
using namespace std;
class MAP{
private:
    vector<int> ID;
    vector<string> NAME;
    vector<int> NUM;
public:
    vector <int> const &id() const {return ID;}
    void id(int a) {ID.push_back(a);}
    vector <string> const &name() const {return NAME;}
    void name(const string &c) {NAME.push_back(c);}
    vector <int> const &num() const {return NUM;}
    void num(int a) {NUM.push_back(a);}

    MAP(){};

    void get(int a, string b,int c){
        this->ID.push_back(a);
        this->NAME.push_back(b);
        this->NUM.push_back(c);

    }
    void eras(int a){
        this->ID.erase(ID.begin()+a);
        this->NAME.erase(NAME.begin()+a);
        this->NUM.erase(NUM.begin()+a);
    }

    void print(){
        for ( int i=0;i<ID.size();++i ) {
        cout << ID[i] << ") " << NAME[i] << " " << NUM[i]<<";"<<endl;
        }}
    void sortv(int var){
        int id=0;
        string name="-";
        int num=0;
        for(int i=0;i<ID.size()-1;i++){
            for(int j=0;j<ID.size()-i-1;j++){
                if(ID[j]>ID[j+1] && var==1){
                    id=ID[j];
                    ID[j]=ID[j+1];
                    ID[j+1]=id;
                    name=NAME[j];
                    NAME[j]=NAME[j+1];
                    NAME[j+1]=name;
                    num=NUM[j];
                    NUM[j]=NUM[j+1];
                    NUM[j+1]=num;
                }
                if(NUM[j]>NUM[j+1] && var==2){
                    id=ID[j];
                    ID[j]=ID[j+1];
                    ID[j+1]=id;
                    name=NAME[j];
                    NAME[j]=NAME[j+1];
                    NAME[j+1]=name;
                    num=NUM[j];
                    NUM[j]=NUM[j+1];
                    NUM[j+1]=num;
                }

            }
        }

    }
};


int main()
{
    MAP PARK;
    MAP CITY;
    short choice;
    bool meny=true;
    while(meny!=false){
    meny=false;
    choice=mainmenu();
    if (choice == 1){
        int id;
        string name;
        int num;
        cin >> id >> name >> num;
        PARK.id(id);
        PARK.name(name);
        PARK.num(num);
    meny=true;
    }
    if (choice == 2){
        for ( int i=0;i<PARK.id().size();++i ) {
        cout << PARK.id()[i] << ") " << PARK.name()[i] << " " << PARK.num()[i]<<";"<<endl;
    meny=true;
    }}
    if (choice == 3){
        cout << "You got 3 new cars" << endl;
        PARK.get(1,"FIRST",50);
        PARK.get(2,"SECOND",52);
        PARK.get(3,"THIRT",91);
        meny=true;
    }
    if (choice == 4){
        int id=0;
        string name="-";
        int num=0;
        int a;
        PARK.print();
        cout << "Enter the ID of the car that will go to the CITY" << endl;
        cin >>a;
        int i=0;
        do{
        id=PARK.id()[i];
        name=PARK.name()[i];
        num=PARK.num()[i];
        i++;
        }while(a!=PARK.id()[i-1]);
        meny=true;
      //  cout << id <<" "<< name << " " << num;
        PARK.eras(i-1);
        CITY.get(id,name,num);
    }
    if (choice == 5){
        for ( int i=0;i<CITY.id().size();++i ) {
        cout << CITY.id()[i] << ") " << CITY.name()[i] << " " << CITY.num()[i]<<";"<<endl;

    }meny=true;}
    if (choice == 6){
        int id=0;
        string name="-";
        int num=0;
        int a;
        CITY.print();
        cout << "Enter the ID of the car that will go to the PARK" << endl;
        cin >>a;
        int i=0;
        do{
        id=CITY.id()[i];
        name=CITY.name()[i];
        num=CITY.num()[i];
        i++;
        }while(a!=CITY.id()[i-1]);
        meny=true;
      //  cout << id <<" "<< name << " " << num;
        CITY.eras(i-1);
        PARK.get(id,name,num);
    }
    if (choice == 7){
    PARK.sortv(1);
    cout << "Get sorted array by ID ;D" << endl;
    PARK.print();
    meny=true;
    }
    if (choice == 8){
    PARK.sortv(2);
    cout << "Get sorted array by number ;D" << endl;
    PARK.print();
    meny=true;
    }
    if (choice == 9){
        int a;
        int b;
        cout << "From where?[1]PARK [2]CITY" << endl;
        cin >> b;
        if (b==1) {
            PARK.print();
        }
        if (b==2){
           CITY.print();
        }
        cout << "Which car by ID do you want to delete?If not one, enter -1" << endl;
        cin >> a;
        int j=0;
            if (a==-1){
                cout << "Enter correct place next time!" << endl;

            }
            if (b==1 && a!=-1) {
                PARK.eras(a-1);
                PARK.print();

            }
            if (b==2&& a!=-1){
               CITY.eras(a-1);
               CITY.print();
            }


    meny=true;
    }
  }  return 0;
}
