#include <iostream>
using namespace std;
unsigned int c_in_str(const char* str,char ch);
char* buildstr(char c,int n);
char* fill_str(char* str,unsigned int x);

int main()
{
//    char a[15] = "hehehehehelaa";
//    const char* p = "asdfasdfad";
//    unsigned int aaa = c_in_str(a,'h');
//    cout << aaa;

//    int integer; // ����
//    char ch;
//    cout << "�������ַ���";
//    cin >> ch;
//    cout << "������������";
//    cin >> integer;
//    char* p = buildstr(ch,integer);
//    cout << p;
//    delete[] p; // ʹ���� ��ն�̬�ڴ�

    unsigned int x{};
    cout << "������������";
    while (!(cin>>x)) {
        cin.clear();
        while (cin.get()  != '\n')
            continue;
        cout << "������������";
        break;
    }
    char* p = new char[x+1];
    p = fill_str(p,x);
    cout << p;\
    delete[] p;
}

// �ж��ַ������м���ָ����ĸ
unsigned int c_in_str(const char* str,char ch)
{
    unsigned int count = 0;
    // ����'\0'����
    while (*str){
        if (*str == ch){
            count++;
        }
        str++;
    }
    return count;
}

// ����һ���ַ���
char* buildstr(char c,int n) // ����ָ��
{
    char* pstr = new char[n+1]; //����\0
    pstr[n] = '\0';
    while (n-- > 0){
        pstr[n] = c;
    }
    return pstr;
}

// �����ַ������ȣ����������
char* fill_str(char* str,unsigned int x)
{
    cout << "�������ַ�����";
    for (int i = 0; i < x; ++i) {
        cin >> *str;
        str++;
    }
    *str = '\0';
    return str-x;
}