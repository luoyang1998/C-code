#include <iostream>
/* thisָ��
 * 1. ������Ƴ�ͻ
 * 2. ���ض������õ�*this */

using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age = age;
    }
    Person& AddAge(Person p)
    {
        this->age += p.age;
        // thisָ��p2��ָ�룬��*thisָ��ľ���p2�������
        return *this;
    }
    int age;
};
/* ������Ƴ�ͻ
 * 1. ��ͬ����
 * 2. thisָ�� */
void test01()
{
    Person p1(18);
    cout << "p1�����䣺" << p1.age << endl;
}
// ���ض������õ�*this
void test02()
{
    Person p1(10);
    Person p2(10);
    p2.AddAge(p1);
    // p2.AddAge(p1).AddAge(p1); ����Ϊvoidʱ������˵���
    p2.AddAge(p1).AddAge(p1); //��ʽ���˼��
    cout << "p2�����䣺" << p2.age << endl;
}
int main()
{
//    test01();
    test02();
}