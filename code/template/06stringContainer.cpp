#include <iostream>
#include <string>
/*
 * string����
 * 1. ���캯��
 * 2. ��ֵ
 * 3. �ַ���ƴ��
 * 4. ���Һ��滻
 * 5. �Ƚ�
 * 6. �ַ���ȡ
 * 7. �����ɾ��
 * 8. �Ӵ���ȡ
 */
using namespace std;

void test01() {
    string s1; // Ĭ�Ϲ���

    const char *str = "hello world";
    string s2(str);
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(10, 'a');
    cout << s4 << endl;
}
void test02() {
    string str1;
    str1 = "hello world";
    cout << str1 << endl;

    string str2;
    str2 = str1;
    cout << str2 << endl;

    string str3;
    str3 = 'c';
    cout << str3 << endl;

    string str4;
    str4.assign("hello world");
    cout << str4 << endl;

    string str5;
    str5.assign("hello world", 5);
    cout << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << str6 << endl;

    string str7;
    str7.assign(10, 'b');
    cout << str7 << endl;
}
void test03() {
    string str1 = "è";
    str1 += "����";
    cout << str1 << endl;

    str1 += ':';
    cout << str1 << endl;

    string str2;
    str2 = "������";
    str1 += str2;
    cout << str1 << endl;

    string str3 = "Cat";
    str3.append(" eat ");
    cout << str3 << endl;

    str3.append("fishaaaa", 4);
    cout << str3 << endl;

    str3.append(str2);
    cout << str3 << endl;

    str3.append(str2, 2, 6);
    cout << str3 << endl;
}
void test04() {
    string str1 = "abcdefg";
    int pos = str1.find("de");
    if (pos == -1) {
        cout << "δ�ҵ��ַ���" << endl;
    } else {
        cout << pos << endl;
    }
    // rfind����������ң�λ��������ɴ���ʼ
    pos = str1.rfind("de");
    cout << pos << endl;

    string str2 = "abcdef";
    // ��1��λ����3���ַ����滻Ϊ1111
    str2.replace(1, 3, "1111");  // a1111ef
    cout << str2 << endl;
}
void test05() {
    string str1 = "hello";
    string str2 = "xello";
    // һ��һ���ַ����бȽ�
    if (str1.compare(str2) == 0) {
        cout << "str1 = str2" << endl;
    } else if (str1.compare(str2) == 1) {
        cout << "str1 > str2" << endl;
    } else {
        cout << "str1 < str2" << endl;
    }
}
void test06() {
    string str = "hello";
    // ͨ��[]���ʵ����ַ�
    for (int i = 0; i < str.size(); ++i) {
        cout << str[i] << " ";
    }
    cout << endl;
    // ͨ��at���ʵ����ַ�
    for (int i = 0; i < str.size(); ++i) {
        cout << str.at(i) << " ";
    }
    cout << endl;
    // �޸ĵ����ַ�
    str[0] = 'x';
    cout << str << endl;
    str.at(1) = 'x';
    cout << str << endl;
}
void test07() {
    string str = "hello";
    // ����
    str.insert(1,"111");
    cout << str << endl;  // h111ello
    // ɾ��
    str.erase(1,3);
    cout << str << endl;
}
void test08() {
    string str = "abcdefg";
    string subStr = str.substr(1,3); // bcd
    cout << subStr << endl;

    // �������л�ȡ �û���Ϣ
    string email = "zhangsan@sina.com";
    int pos = email.find('@');
    string uarNmae = email.substr(0,pos);
    cout << uarNmae << endl;
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
    test08();
}