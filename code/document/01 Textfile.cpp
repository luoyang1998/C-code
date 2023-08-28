#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/* �ı��ļ�
 * 1. д�ļ�
 * 2. ���ļ�*/
// д�ļ�
void test01()
{
    // 2.����������
    ofstream ofs;
    // 3.ָ���򿪷���
    ofs.open("../text.txt",ios::out);
    // 4.д����
    ofs << "����������" << endl;
    ofs << "�Ա���" << endl;
    ofs << "���䣺18" << endl;
    // 5.�ر��ļ�
    ofs.close();
}
// ���ļ�
void test02()
{
    // 2.����������
    ifstream ifs;
    // 3.���ļ� ���ж��Ƿ�򿪳ɹ�
    ifs.open("../text.txt",ios::in);
    if (!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }
     // 4.������
    // ��һ��
    char buf1[1024] = {0};
    while(ifs>>buf1){
        cout << buf1 << endl;
    }
    // �ڶ���
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2))){
        cout << buf2 << endl;
    }
    // ������
    string buf3;
    while (getline(ifs,buf3)){
        cout << buf3 << endl;
    }
    // ������
    char c;
    while((c = ifs.get()) != EOF) //EOF end of file
    {
        cout << c;
    }
    // 5.�ر��ļ�
    ifs.close();
}
int main() {
//    test01();
    test02();
}
