#include <iostream>
/* ��ͨҳ��ʵ��*/
using namespace std;

// �̳�ʵ��
// ����ҳ��
class BasePage
{
public:
    void header()
    {
        cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
    }
    void footer()
    {
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
    }
    void left()
    {
        cout << "Java��Python��C++...(���������б�)" << endl;
    }
};
// Javaҳ��ʵ��
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Javaѧ����Ƶ" << endl;
    }
};
// C++ҳ��
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "CPPѧ����Ƶ" << endl;
    }
};
// Pythonҳ��
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Pythonѧ����Ƶ" << endl;
    }
};

void test01()
{
    cout << "Java������Ƶҳ�����£�" << endl;
    Java Ja;
    Ja.header();
    Ja.footer();
    Ja.content();
    Ja.left();
    cout << "----------------------------" << endl;
    cout << "C++������Ƶҳ�����£�" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.content();
    cpp.left();
    cout << "----------------------------" << endl;
    cout << "Python������Ƶҳ�����£�" << endl;
    Python Py;
    Py.header();
    Py.footer();
    Py.content();
    Py.left();
}
int main()
{
    test01();
}
