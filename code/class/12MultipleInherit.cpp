#include <iostream>
#include <string>
/* ��̳�
 * 1. �麯��
 * 2. ������*/
using namespace std;

class Base1 {
public:
    Base1() {
        m_A = 100;
    }

    int m_A;
};

class Base2 {
public:
    Base2() {
        m_A = 200;
    }

    int m_A;
};

// ���� �̳�Base1 �� Base2
class Son : public Base1, public Base2 {
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

class Animal{
public:
    Animal()
    {
        cout << "Animal���캯������" << endl;
    }
    // �麯��
    virtual void speak(){
        cout << "������˵��" << endl;
    }
//    virtual ~Animal() // ��Ϊ������ �������������
//    {
//        cout << "Animal������������" << endl;
//    }
    // �������� ��Ҫ�д������ʵ��
    virtual ~Animal() = 0;
};
// �������� ��Ҫ���� Ҳ��Ҫʵ�� �д������� ���ڳ�����
Animal::~Animal(){
    cout << "Animal��������������" << endl;
};
class Cat:public Animal{
public:
    Cat(string name)
    {
        cout << "Cat���캯������" << endl;
        m_Name = new string(name);
    }
    virtual void speak(){  // ������д�����麯��virtual void speak()
        cout << *m_Name << "Сè��˵��" << endl;
    }
    ~Cat()
    {
        if(m_Name != NULL){
            cout << "Cat������������" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};
// C++��������֮�������ת��������Ҫ��ǿ������ת��
// ������˵��  ��ַ���  �ڱ���׶�ȷ��������ַ
// speakǰ��virtual����麯��  ��ɶ�̬��̬�������  ʵ��Сè˵��
void doSpeak(Animal &animal){ // Animal & animal = cat ����ִ���������
    animal.speak();
}
void test01()
{
    Son s;
    cout << "size of s = " << sizeof(s) << endl;
    // ���������ͯ����Ա ��Ҫ������������
    cout << "m_A = " << s.Base1::m_A << endl; // 200
    cout << "m_A = " << s.Base2::m_A << endl; // 100
}
//void test02(){
//    Cat cat;
//    doSpeak(cat);
//}
void test03(){
    Animal * animal = new Cat("Tom");
    animal->speak();
    // ����ָ��������ʱ�򣬲����������������������������������ж������ԣ������ڴ�й¶
    delete animal;
}
int main()
{
//    test01();
//    test02();
    test03();
}
