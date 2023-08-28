#include <iostream>
#include <fstream>
/* 二进制文件
 * 1. 写文件
 * 2. 读文件*/
using namespace std;
class Person
{
public:
    char m_Name[64];
    int m_Age;

};
void test01()
{
    // 2.创建流对象
    ofstream ofs("../person.txt",ios::out|ios::binary);
    // 3.指定打开方式
//    ofs.open("../person.txt",ios::out|ios::binary);
    // 4.写内容
    Person p = {"张三",18};
    ofs.write((const char *)&p,sizeof(Person));
    // 5.关闭文件
    ofs.close();
}
void test02(){
    // 2.创建流对象
    ifstream ifs;
    // 3.打开方式 判断打开成功
    ifs.open("../person.txt",ios::in|ios::binary);
    if (!ifs.is_open()){
        cout << "打开失败" << endl;
        return;
    }
    // 4.写内容
    Person p;
    ifs.read((char *)&p,sizeof(Person));
    cout << "姓名:" << p.m_Name << "  年龄：" << p.m_Age << endl;
    // 5.关闭文件
    ifs.close();
}
int main()
{
//    test01();
    test02();
}