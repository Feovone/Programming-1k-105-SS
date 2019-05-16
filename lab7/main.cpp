#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
    static const char DELIM;
    int age_;
    string namebook_;
    string name_;
public:
    int age() const {return age_; }
    void age(int a) {age_ = a; }

    string namebook() const {return namebook_; }
    void namebook(const string& c) {namebook_ = c; }

    string name() const {return name_; }
    void name(const string& n) {name_ = n; }

    Person() {}

    Person(const int age, string namebook, const string& name) {
        this->age_ = age;
        this->namebook_ = namebook;
        this->name_ = name;
    }

    virtual ~Person() {}

    friend ostream& operator<<(ostream&, const Person&);
    friend istream& operator>>(istream&, Person&);
};

const char Person::DELIM = ';';

ostream& operator<<(ostream& os, const Person& p) {
    os << p.age() << Person::DELIM << p.namebook() << Person::DELIM << p.name();
    return os;
}

istream& operator>>(istream& is, Person& p) {
    string name, namebook;
    int age;

    is >> age;
    is.ignore(1, Person::DELIM);

    getline(is, namebook,';');

    getline(is, name);

    p.age(age);
    p.namebook(namebook);
    p.name(name);
    return is;
}

int main(int argc, char* argv[])
{

     if (argc <= 1) {
        cout << "Usage " << argv[0] << " <file name> <arg> \n[1]Status lib \n[2]Add new book \n[3]Create test lib \n[4]Sort";
        cout << "\n[R]README " ;
        return -1;
     }

     string fname(argv[1]);
     string param(argv[2]);

     if (param == "1") {
        ifstream is(fname.c_str());
        if (!is) {
            cout << "File " << fname << " doesn't exist" << endl;
            return -1;
        }

        while(!is.eof()) {
            Person p1;
            is >> p1;
            cout << p1 << endl;
        }

        is.close();

     }else
     if(param == "2") {
            cout << "Enter your book in format '" << argv[0] <<" "<< argv[1]<<" 2 YEAR;NAME BOOK;AUTHOR'\n";
            string book(argv[3]);
            ofstream out;
            out.open(argv[1], ios::in);
            out.seekp(0, ios::end);
            out << endl;
            out << book;
            out.close();
      }else {
         if (param == "3") {
            Person p1(1999, "LICHKING", "John Doe");
            Person p2(2001,"TRENT", "Marry King");

            ofstream os(fname.c_str());
            if (!os) {
                cout << "Can't create file " << fname << endl;
                return -1;
            }
            os << p1 << endl;
            os << p2;
            os.close();
         }
         else {
         if (param == "4") {
            ofstream os(fname.c_str());
            ifstream is(fname.c_str());
            string sort(argv[3]);
            int year=1990;
            Person p1;
            Person p2;
            while(is!='\0'){
            is >> p1;
            is >> p2;
            cout << p1 << endl;
            ++year;
        }}
        else {
         if (param == "R") {
           cout << "In ADD and SORT use 3 arg or program crash!!";
        }

         }


    return 0;
}}}
