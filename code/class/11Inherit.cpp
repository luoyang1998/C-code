#include <iostream>
/* 普通页面实现*/
using namespace std;

// 继承实现
// 公共页面
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
};
// Java页面实现
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};
// C++页面
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "CPP学科视频" << endl;
    }
};
// Python页面
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};

void test01()
{
    cout << "Java下载视频页面如下：" << endl;
    Java Ja;
    Ja.header();
    Ja.footer();
    Ja.content();
    Ja.left();
    cout << "----------------------------" << endl;
    cout << "C++下载视频页面如下：" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.content();
    cpp.left();
    cout << "----------------------------" << endl;
    cout << "Python下载视频页面如下：" << endl;
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
