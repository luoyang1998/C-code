#include <iostream>
#include <string>
/* ���������
 * 1. �Ӻ���������� 1)��Ա�������� 2)ȫ�ֺ�������
 * 2. ������������� 1)ȫ�ֺ������� �������ó�Ա�������� p.operator<<(cout) �޷�cout�����
 * 3. ������������� �Զ�������
 * 4. ��ֵ���������
 * 5. ��ϵ��������� 1) = 2) !=
 * 6. ����������������� 1)��ӡ 2)�ӷ�*/
using namespace std;

class Person {
public:
    Person() {
    }

    Person(int age) {
        m_Age = new int(age);
    }

    Person(string name, int age) {
        m_Name = name;
        m_age = age;
    }

    ~Person() {
        if (m_Age != NULL) {
            delete m_Age;
        }
    }

    // ���ظ�ֵ�����
    Person &operator=(Person &p) {
        // �������ṩǳ����
        // ���ж��Ƿ��������ڶ��� ��������ͷ� �����
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
        // ���
        m_Age = new int(*p.m_Age);
        return *this;
    }

    // ����==
    bool operator==(Person &p) {
        if (this->m_Name == p.m_Name && this->m_age == p.m_age) {
            return true;
        }
        return false;
    }
    bool operator!=(Person &p) {
        if (this->m_Name != p.m_Name || this->m_age != p.m_age) {
            return false;
        }
        return true;
    }
    // ��Ա��������+��
//    Person operator+(Person &p) {
//        Person temp;
//        temp.m_A = this->m_A + p.m_A;
//        temp.m_B = this->m_B + p.m_B;
//        return temp;
//    }

    int m_A;
    int m_B;

    int *m_Age;

    string m_Name;
    int m_age;

};

// �Զ�������
class MyInteger {
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger() {
        m_Num = 0;
    }

    // ����ǰ��++����� ����������Ϊ��һֱ��һ�������в���
    MyInteger &operator++() {
        m_Num++;
        return *this;
    }

    // ���غ���++����� int��ʾռλ������������������ǰ�ú��õ������� tempΪ��ʱ���� ���ɷ�������
    MyInteger operator++(int) {
        // �ȷ��ؽ��
        MyInteger temp = *this;
        // �ٵ���
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};

// ��ӡ�����
class MyPrint
{
public:
    // ���غ������������
    void operator()(string text)
    {
        cout << text << endl;
    }
};
// �º�����û�й̶�д��
// �ӷ���
class MyAdd
{
public:
    int operator()(int a,int b)
    {
        int c = a + b;
        return c;
    }
};

// ȫ�ֺ�������+
Person operator+(Person &p1, Person &p2) {
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// Ҳ�ɺ�������
Person operator+(Person &p1, int num) {
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}

// ȫ�ֺ�������<<
ostream &operator<<(ostream &cout, Person &p) // ostream�����
{
    cout << p.m_A << " " << p.m_B;
    return cout; // cout��һ����������񣬷��������ʱ�����Լ�����ͬһ��ʹ��<<���������ַ�
}

ostream &operator<<(ostream &cout, MyInteger myint) // ostream�����
{
    cout << myint.m_Num;
    return cout; // cout��һ����������񣬷��������ʱ�����Լ�����ͬһ��ʹ��<<���������ַ�
}


void test01() {
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;
//    Person p3 = operator+(p1,p2); ���ʵ��� ����������
    Person p3 = p1 + p2;
    cout << p3.m_A << " " << p3.m_B << endl;

    Person p4 = p1 + 20; // ��������
    cout << p4.m_A << " " << p4.m_B << endl;
}

void test02() {
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;

    cout << p1 << endl;
}

void test03() {
    MyInteger myint;
    cout << myint << endl;
    cout << ++myint << endl;
    cout << myint << endl;

    MyInteger myint2;
    cout << myint2++ << endl;
    cout << myint2 << endl;
}

void test04() {
    Person p1(18);
    cout << "p1�����䣺" << *p1.m_Age << endl;
    Person p2(20);
    p2 = p1; // ��ֵ���� ��������ʱ ���new�����ظ��ͷ� ����������
    cout << "p2�����䣺" << *p2.m_Age << endl;
    Person p3(30);

    p3 = p2 = p1;
    cout << "p1�����䣺" << *p1.m_Age << endl;
    cout << "p2�����䣺" << *p2.m_Age << endl;
    cout << "p3�����䣺" << *p3.m_Age << endl;
}

void test05() {
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 == p2) {
        cout << "p1��p2Ϊͬһ��" << endl;
    } else {
        cout << "p1��p2��Ϊͬһ��" << endl;
    }
    if (p1 != p2) {
        cout << "p1��p2Ϊͬһ��" << endl;
    } else {
        cout << "p1��p2��Ϊͬһ��" << endl;
    }
}

void test06()
{
    MyPrint myPrint;
    myPrint("Hello World!");
    MyAdd myAdd;
    cout << myAdd(1,2) << endl;
    cout << MyAdd()(1,2) << endl; // ������������ �����������ͷ�
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
}
