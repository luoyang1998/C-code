#include <iostream>
#include <string>
using namespace std;
/* ��Ա��������Ϊ˽��
 * 1. �Լ���������
 * 2. ����д���Լ����Ч�� */

class Person
{
public:
    // ��������
    void setname(string name)
    {
        m_name = name;
    }
    // ��ȡ����
    string getname()
    {
        return m_name;
    }
    // ��ȡ���� ��Ϊ�ɶ���д �������䷶Χ 0-100
    int getage()
    {
//        m_age = 0;
        return m_age;
    }
    void setage(int age)
    {
        if (age < 0 | age > 100){
            m_age = 0;
            cout << "������������" << endl;
            return;
        }
        m_age = age;
    }
    // ��������
    void setcar(string car)
    {
        m_car = car;
    }

private:
    string m_name;  // �ɶ���д
    string m_car;  // ֻд
    int m_age;  // ֻ��

};
int main(){
    Person p1;
    p1.setname("����");
    cout << "����Ϊ��" << p1.getname() << endl;
    cout << "����Ϊ��" << p1.getage() << endl;
    p1.setcar("������");
    p1.setage(101);
}
