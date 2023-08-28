#include <iostream>
#include <string>
using namespace std;
/*
 * ��ģ���������������
 * 1. ����ָ������ --- ֱ����ʾ�������������
 * 2. ����ģ�廯  --- �������еĲ�����Ϊģ����д���
 * 3. ������ģ�廯 --- ������������� ģ�廯���д���
 */

template<class T1,class T2>
class Person {
public:
    Person(T1 name,T2 age);
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }

    void showPerson();
//    {
//        cout << "������" << this->m_Name << " ���䣺" << this->m_Age << endl;
//    }

    T1 m_Name;
    T2 m_Age;
};
/// ���캯������ʵ��
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    this->m_Name = name;
    this->m_Age = age;
}
/// ��Ա��������ʵ��
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout << "������" << this->m_Name << " ���䣺" << this->m_Age << endl;
}

// 1.ָ����������  ��p��Ϊ��������
void printPerson1(Person<string ,int>&p) {
    p.showPerson();
}
void test01() {
    Person<string ,int>p("�����",100);
    printPerson1(p);
}
// 2.����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1 ,T2>&p) {
    p.showPerson();
    cout << "T1�����ͣ�" << typeid(T1).name() << endl;
    cout << "T2�����ͣ�" << typeid(T2).name() << endl;
}
void test02() {
    Person<string ,int>p("��˽�",90);
    printPerson2(p);
}
// 3.������ģ�廯
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T�����ͣ�" << typeid(T).name() << endl;
}
void test03(){
    Person<string ,int>p("ɳ��",60);
    printPerson3(p);
}
int main() {
//    test01();
//    test02();
    test03();
}
