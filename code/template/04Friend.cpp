#include <iostream>
#include <string>
using namespace std;
/*
 * ��ģ��----��Ԫ��������ʵ��
 * ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
 * ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
 *
 * ͨ��ȫ�ֺ�����ӡPerson
 */

// ��ǰ�ñ�����֪��person��
template<class T1,class T2>
class Person;

// ����ʵ��
template<class T1,class T2>
void printPerson(Person<T1,T2> p){
    cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1,class T2>
class Person {
    // ȫ�ֺ��� ����ʵ��
    friend void showPerson(Person<T1,T2> p)
    {
        cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
    }
    // ȫ�ֺ��� ����ʵ��
    // �����ȫ�ֺ�����������ʵ�� ��Ҫ�ñ�������ʶ��
    friend void printPerson<>(Person<T1,T2> p);

public:
    Person(T1 name,T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 1. ȫ�ֺ�������ʵ��
void test01() {
    Person<string ,int>p("Jerry",18);
    showPerson(p);
}
// 2. ȫ�ֺ�������ʵ��
void test02() {
    Person<string ,int>p("Tom",20);
    printPerson(p);
}
int main(){
//    test01();
    test02();
}


