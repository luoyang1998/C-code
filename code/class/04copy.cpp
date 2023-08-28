#include <iostream>

using namespace std;

/* ǳ���������
 * 1. �������ṩ�Ŀ������캯�������ṩǳ��������*/

class Person
{
public:
    // ���캯��
    Person()
    {
        cout << "Person �޲ι��캯������" << endl;
    }
    Person(int age, int height)    // �вι���
    {
        m_age = age;
        m_height = new int(height);
        cout << "Person �вι��캯������" << endl;
    }
    Person(const Person &p)// �������캯��
    {
        m_age = p.m_age;
        // m_height = p.m_height; // ǳ����
        // ���
        m_height = new int(*p.m_height);
        cout << "Person �������캯������" << endl;
    }
    // ��������
    ~Person()
    {
        // �������룬����ȥ�����������ͷŲ���
        if (m_height != NULL){
            delete m_height;
            m_height = NULL;
        }
        cout << "Person ������������" << endl;
    }

    int m_age;
    int *m_height;
};
// ����
void test()
{
    Person p1(18,160);
    cout << "����Ϊ��" << p1.m_age << " ���Ϊ��" << *p1.m_height << endl;
    Person p2(p1);
    cout << "����Ϊ��" << p2.m_age << " ���Ϊ��" << *p2.m_height << endl;

}


int main()
{
    test();
}
