#include <iostream>
/* ��̬��Ա����
 * 1.���ж�����ͬһ������
 * 2.����׶ξͷ����ڴ�
 * 3.���������������ʼ������*/

/* ��̬��Ա����
 * 1.���ж�����ͬһ������
 * 2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա���� */
using namespace std;
class Person
{
public:
    static int m_A;
    int m_C; // �Ǿ�̬��Ա

    // ��̬��Ա����Ҳ�з���Ȩ��
private:
    static int m_B;

public:
    // ��̬��Ա����
    static void func()
    {
        m_A = 100;
        //m_C = 200; ��̬���� �����Է��� �Ǿ�̬��Ա���� �ǹ������޷������ĸ����������
        cout << "static void func ����" << endl;
    }

    // ��̬��Ա�������з���Ȩ�޵�
private:
    static void func2()
    {
        cout << "static void func2 ����" << endl;
    }
};

// �����ʼ��
int Person::m_A = 0;
int Person::m_B = 200;

void test01()
{
    Person p;
    cout << p.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}
void test02()
{
    // ��̬��Ա���� ������ĳ���������ж��󶼹���ͬһ������
    // ��̬��Ա���������ַ��ʷ�ʽ
    // 1. ͨ��������з���
    Person p;
    cout << p.m_A << endl;
    // 2. ͨ���������з���
    cout << Person::m_A << endl;
//    cout << Person::m_B << endl; ������ʲ���˽�г�Ա
}
void test03()
{
    // 1. ͨ��������з���
    Person p;
    p.func();
    // 2. ͨ���������з���
    Person::func();
    //Person::func2(); ������ʲ���˽�о�̬��Ա����
}
int main()
{
//    test01();
    test02();
    test03();
}