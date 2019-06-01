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
        cout << "Usage " << argv[0] << " <file name> <arg> \n[1]Status lib \n[2]Add new book \n[3]Create test lib \n[4]delete book";
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

        }
        else
        if(param == "2") {
            cout << "Enter your book in format '" << argv[0] <<" "<< argv[1]<<" 2 YEAR;NAME BOOK;AUTHOR'\n";
            string book(argv[3]);
            ofstream out;
            out.open(argv[1], ios::in);
            out.seekp(0, ios::end);
            out << endl;
            out << book;
            out.close();
        }
        else {
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
            ifstream file_in;
            file_in.open("stud.txt");
            if(!file_in){
                cerr << "Error file not found:" << "stud.txt" << endl;
                return -1;
                }
            int i_number_line_now = 0; //счётчик строк
            string line; //для хранения строки
            string line_file_text; //для хранения текста файла
            int line_file_delete;
            cin >> line_file_delete;
            while(getline(file_in,line)){
            i_number_line_now++;

            if(!(i_number_line_now == line_file_delete)){
                line_file_text.insert(line_file_text.size(),line); /*добавить строку*/
                    /*добавить перенос на следующую строку*/
               if(!(i_number_line_now-1 == line_file_delete)){
                    line_file_text.insert(line_file_text.size(),"\n");
               }
            }
            }

            file_in.close();
            ofstream file_out;
            file_out.open ("stud.txt",ios::trunc | ios::binary);
            file_out.write(line_file_text.c_str(), line_file_text.size());
            file_out.clear();
            }
         else {
         if (param == "5") {


        }

         else {
         if (param == "R") {
           cout << "In ADD and SORT use 3 arg or program crash!!";
        }

         }


    return 0;
}}}
