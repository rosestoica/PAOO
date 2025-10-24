#include "Book.hpp"
#include <utility>

using namespace std;
Book func()
{
    Book b("Emma", 900);
    b.print();
    Book b1 = b;
    Book b2("...",100);
    b2=b1;
    return b2;
}

int main() {

    Book b1("Pride and Prejudice", 900);
    b1.print();

    Book b2 = b1;
    b2.print();

    Book b3 = std::move(b1);
    b3.print();
   
    cout<<"Before func"<<endl;
    Book bb = func();
    cout<<"After func"<<endl;
    bb.print();
    return 0;
}
