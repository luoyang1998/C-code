#include <iostream>
#include "person.cpp"
using namespace std;

void test01()
{
    Person <string,int>p("Jerry",18);
    p.showPerson();
}

int main() {
    test01();
}
