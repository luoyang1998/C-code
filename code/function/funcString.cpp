#include <iostream>
#include <string>
using namespace std;
void display(const string sa[],int n);
int main()
{
    const unsigned int size = 5;
    string a[size];
    cout << "�����С��" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i+1 << ":";
        getline(cin,a[i]);
    }
    cout << "����ַ�Ϊ��" << endl;
    display(a,size);
}
// ����������������
void display(const string sa[],int n)
{
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ":" << sa[i] << endl;
    }
}
