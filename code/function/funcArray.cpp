#include <iostream>
#include <array>
using namespace std;

// ����array�洢��ͬ���ڵĲ�ͬ��֧

const int Season{4};
const array<string,Season>names{"����","����","����","����"};
void fill(array<double,Season>* p);
void show(array<double,Season>da);
void showp(array<double,Season>*p);
int main()
{
    array<double,Season>expenses;
    fill(&expenses);
//    show(expenses);
    showp(&expenses);
}
void fill(array<double,Season>* p)
{
    cout << "����������ڿ�֧��" << endl;
    for (int i = 0; i < Season; ++i) {
        cout << names[i] << "��֧Ϊ��";
        cin >> (*p)[i];
    }
}
void show(array<double,Season>da)
{
    double total = 0;
    cout << "�ܷ������Ϊ��" << endl;
    for (int i = 0; i < Season; ++i) {
        cout << "����" << names[i] << "��֧Ϊ��" << da[i] << endl;
        total  = total + da[i];
    }
    cout << "ȫ������Ϊ:" << total;
}
// ָ�봫��
void showp(array<double,Season>*p)
{
    double t = 0;
    cout << "�ܷ������Ϊ��" << endl;
    for (int i = 0; i < Season; ++i) {
        cout << "����" << names[i] << "��֧Ϊ��" << (*p)[i] << endl;
        t = t + (*p)[i];
    }
    cout << "ȫ������Ϊ:" << t;
}
