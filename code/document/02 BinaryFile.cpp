#include <iostream>
#include <fstream>
/* �������ļ�
 * 1. д�ļ�
 * 2. ���ļ�*/
using namespace std;
class Person
{
public:
    char m_Name[64];
    int m_Age;

};
void test01()
{
    // 2.����������
    ofstream ofs("../person.txt",ios::out|ios::binary);
    // 3.ָ���򿪷�ʽ
//    ofs.open("../person.txt",ios::out|ios::binary);
    // 4.д����
    Person p = {"����",18};
    ofs.write((const char *)&p,sizeof(Person));
    // 5.�ر��ļ�
    ofs.close();
}
void test02(){
    // 2.����������
    ifstream ifs;
    // 3.�򿪷�ʽ �жϴ򿪳ɹ�
    ifs.open("../person.txt",ios::in|ios::binary);
    if (!ifs.is_open()){
        cout << "��ʧ��" << endl;
        return;
    }
    // 4.д����
    Person p;
    ifs.read((char *)&p,sizeof(Person));
    cout << "����:" << p.m_Name << "  ���䣺" << p.m_Age << endl;
    // 5.�ر��ļ�
    ifs.close();
}
int main()
{
//    test01();
    test02();
}