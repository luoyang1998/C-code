#include <iostream>
/* 类对象作为类成员
 * 1. 输入谁拿着什么手机*/
using namespace std;

// 手机类别
class Phone
{
public:
    Phone(string Pname)
    {
        cout << "Phone 构造函数调用" << endl;
        m_Pname = Pname;
    }
    ~Phone()
    {
        cout << "Phone 析构函数调用" << endl;
    }
    string m_Pname;
};

class Person
{
public:
    // Phone m_Phone = pname
    Person(string name, string pname):m_name(name), m_Phone(pname)
    {
        cout << "Person 构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person 析构函数调用" << endl;
    }

    // 姓名
    string m_name;
    // 手机
    Phone  m_Phone;
};
void test()
{
    Person p("张三","苹果");
    cout << p.m_name << p.m_Phone.m_Pname << endl;
}
int main()
{
    test();
}