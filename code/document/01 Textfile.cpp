#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/* 文本文件
 * 1. 写文件
 * 2. 读文件*/
// 写文件
void test01()
{
    // 2.创建流对象
    ofstream ofs;
    // 3.指定打开防守
    ofs.open("../text.txt",ios::out);
    // 4.写内容
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;
    // 5.关闭文件
    ofs.close();
}
// 读文件
void test02()
{
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件 并判断是否打开成功
    ifs.open("../text.txt",ios::in);
    if (!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }
     // 4.读数据
    // 第一种
    char buf1[1024] = {0};
    while(ifs>>buf1){
        cout << buf1 << endl;
    }
    // 第二种
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2))){
        cout << buf2 << endl;
    }
    // 第三种
    string buf3;
    while (getline(ifs,buf3)){
        cout << buf3 << endl;
    }
    // 第四种
    char c;
    while((c = ifs.get()) != EOF) //EOF end of file
    {
        cout << c;
    }
    // 5.关闭文件
    ifs.close();
}
int main() {
//    test01();
    test02();
}
