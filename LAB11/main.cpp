#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Person {
private:
    string name_;
    int age_;

public:
    string name() const {return this->name_;}
    void name(string n) { this->name_ = n;}

    int age() const {return age_;}
    void age(int a) {this->age_ = a; }

    Person() {
    }

    Person(string name, int age)
     : name_(name)
     , age_(age)
     {}

     friend ostream& operator <<(ostream& os, const Person& p);
};

ostream& operator <<(ostream& os, const Person& p)
{
    os << "{name: " << p.name_ << "; age=" << p.age_ << "}";
    return os;
}

ostream& operator <<(ostream& os, const vector<Person>& pvec)
{
    for (const auto& p: pvec) {
        os << p << endl;
    }
    return os;
}


int main()
{
    vector<Person> personVectors;
    personVectors.push_back(Person("John Lin", 27));
    personVectors.push_back(Person("Robert Gelhm", 22));
    personVectors.push_back(Person("Linda Am", 31));
    cout << personVectors << endl;

    sort(begin(personVectors), end(personVectors),
         [](const Person& p1, const Person& p2) -> bool {
            return p1.age() < p2.age();
         });

    cout << personVectors << endl;

    sort(begin(personVectors), end(personVectors),
         [](const Person& p1, const Person& p2) -> bool {
            return p1.name() < p2.name();
         });
    cout << personVectors << endl;

    return 0;
}
