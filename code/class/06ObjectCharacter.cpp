#include <iostream>
/* �������Ϊ���Ա
 * 1. ����˭����ʲô�ֻ�*/
using namespace std;

// �ֻ����
class Phone
{
public:
    Phone(string Pname)
    {
        cout << "Phone ���캯������" << endl;
        m_Pname = Pname;
    }
    ~Phone()
    {
        cout << "Phone ������������" << endl;
    }
    string m_Pname;
};

class Person
{
public:
    // Phone m_Phone = pname
    Person(string name, string pname):m_name(name), m_Phone(pname)
    {
        cout << "Person ���캯������" << endl;
    }
    ~Person()
    {
        cout << "Person ������������" << endl;
    }

    // ����
    string m_name;
    // �ֻ�
    Phone  m_Phone;
};
void test()
{
    Person p("����","ƻ��");
    cout << p.m_name << p.m_Phone.m_Pname << endl;
}
int main()
{
    test();
}