#include <iostream>

using namespace std;
const int* f1(const int* ,int n); // ����������ʡ��
const int* f2(const int [],int n);
const int* f3(const int [],int n);
int main()
{
    int a[3] = {1,2,3};
    /* ����ָ������ָ��*/
    cout << "����ָ������ָ�룺" << endl;
    const int* (*p)(const int* ,int n) = f1;
    cout << "��Ϊ��" << *(*p)(a,3) << "��ַΪ��" << (*p)(a,3) << endl;
    // �Զ���������,ֻ�����ڵ�ֵ��ʹ��
    auto p2 = f2;
    cout << "��Ϊ��" << *p2(a,3) << "��ַΪ��" << p2(a,3) << endl;
    cout << "ʹ��ָ������ָ�����飺" << endl;
    const int* (*pa[3])(const int [],int n) = {f1,f2,f3};
    for (int i = 0; i < 3; ++i) {
        cout << "��Ϊ��" << *pa[i](a,3) << "��ַΪ��" << pa[i](a,3) << endl;
    }

    cout << "ʹ��ָ����ָ���ָ�룺" << endl;
    auto pb = pa;
    for (int i = 0; i < 3; ++i) {
        cout << "��Ϊ��" << *pb[i](a,3) << "��ַΪ��" << pb[i](a,3) << endl;
    }

    cout << "ʹ��ָ�������ָ�� auto��" << endl;
    auto pc = &pa;
    for (int i = 0; i < 3; ++i) {
        cout << "��Ϊ��" << *(*pc)[i](a,3) << "��ַΪ��" << (*pc)[i](a,3) << endl;
    }

    cout << "ʹ��ָ�������ָ�� ����auto��" << endl;
    const int* (*(*pd)[3])(const int[],int n) = &pa;
    for (int i = 0; i < 3; ++i) {
        cout << "��Ϊ��" << *(*pd)[i](a,3) << "��ַΪ��" << (*pd)[i](a,3) << endl;
    }
}
const int* f1(const int* ar,int n)
{
    return ar;
}
const int* f2(const int ar[],int n)
{
    return ar+1;
}
const int* f3(const int ar[],int n)
{
    return ar+2;
}