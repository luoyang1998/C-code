#include <iostream>
#include <string>
using namespace std;
/* ���һ��Բ�࣬����Բ���ܳ�
 * Բ�ܳ���ʽ��2*pi*r */
const double pi = 3.14;

// class�������һ����,����
class Circle
{
    // ����Ȩ��
    // ����Ȩ��
public:
    // ���ԣ��뾶
    int m_r;
    // ��Ϊ����ȡ�ܳ�
    double caculateZC()
    {
        return 2*pi*m_r;
    }
};

/* ����һ��ѧ���࣬��ѧ����ֵ������ѧ�ţ���� */
class student
{
public:
    int num;
    string name;
public:
    void display()
    {
        cout << "ѧ��ѧ�ţ�"  << num << endl;
        cout << "ѧ��������"  << name << endl;
    }
    void setname(string s_name)
    {
        name = s_name;
    }
    void setnum(int s_num)
    {
        num = s_num;
    }
};
int main() {
    // ͨ��Բ�࣬����һ�������Բ������
    Circle c1;
    // ��Բ���� ���Խ��и�ֵ
    c1.m_r = 10;
    cout << "Բ���ܳ�" << c1.caculateZC() << std::endl;

    student s1;
//    s1.name = "����";
//    s1.num = 123456;
    s1.setname("����");
    s1.setnum(12);
    s1.display();

}
