#include <iostream>

using namespace std;
struct YEAR {
    int day{18};
    int month{12};
    int year{2022};
};

YEAR &display(YEAR &a);

YEAR &display2(YEAR &a);

int main() {
    YEAR year;
    cout << display(year).year << display(year).month << display(year).day << endl;
    cout << display2(display(year)).year << display2(display(year)).month << display2(display(year)).day << endl;
}

YEAR &display(YEAR &a) {
//    cout << "???????";
//    cout << a.year << "??" << a.month << "??" << a.day << "??" << endl;
    a.year = 2025;
    a.month = 13;
    a.day = 14;
    return a;
}

YEAR &display2(YEAR &a) {
//    cout << "???????";
//    cout << a.year << "??" << a.month << "??" << a.day << "??" << endl;
    a.year = 2023;
    a.month = 11;
    a.day = 14;
    return a;
}