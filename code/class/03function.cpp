#include <iostream>

using namespace std;

/* ����ĳ�ʼ��������
 * 1. ���캯�����г�ʼ������
 * 2. ������������������� */

/* ���캯������ �� ���ֵ��÷�ʽ */

/* �������캯������������ʱ��
 * 1. ʹ��һ��������ϵĶ�������ʼ��һ���¶���
 * 2. ֵ���ݵķ�ʽ������������ֵ
 * 3. ��ֵ��ʽ���ش��ݶ��� */

class Person
{
public:
    // ���캯��
    Person()
    {
        cout << "Person �޲ι��캯������" << endl;
    }
    Person(int age)    // �вι���
    {
        m_age = age;
        cout << "Person �вι��캯������" << endl;
    }
    Person(const Person& p)// �������캯��
    {
        m_age = p.m_age;
        cout << "Person �������캯������" << endl;
    }
    // ��������
    ~Person()
    {
        cout << "Person ������������" << endl;
    }

    int m_age;
};
// ����
void test()
{
    // ��ͨ����
    Person p1; // ��ջ�ϵ����� testִ����Ͼͻ��ͷ�

    // ���ŷ�
    // 1.ʹ��һ��������ϵĶ�������ʼ��һ���¶���
    Person p2(10);
    Person p3(p2); // ����

    cout << "����Ϊ��" << p2.m_age << endl;
    cout << "����Ϊ��" << p3.m_age << endl;

    // ��ʾ��
    Person p4;
    Person p5 = Person(10); // Person(10) �������� �ص㣺��ǰִ�н����� ϵͳֱ���ͷ�
    Person p6 = Person(p5); //����

    // ��ʽת��
    Person p7 = 10; // �൱��Person p7 = Person(10);
    Person p8 = p7; // ����
}

// 2. ֵ���ݵķ�ʽ������������ֵ
void dowork(Person p)
{

}
void test01()
{
    Person p;
    dowork(p);
}

// 3. ��ֵ��ʽ���ش��ݶ���
Person dowork2()
{
    Person p;
    cout << (int*)&p <<endl;
    return p;
}
void test02()
{
    Person p = dowork2();
    cout << (int*)&p <<endl;
}
int main()
{
//    test(); // �Զ�����һ�ι��캯��
//    test01();
    test02();
}
