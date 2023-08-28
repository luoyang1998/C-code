#include <iostream>
#include <array>
using namespace std;

// 创建array存储不同季节的不同开支

const int Season{4};
const array<string,Season>names{"春天","夏天","秋天","冬天"};
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
    cout << "请输入个季节开支：" << endl;
    for (int i = 0; i < Season; ++i) {
        cout << names[i] << "开支为：";
        cin >> (*p)[i];
    }
}
void show(array<double,Season>da)
{
    double total = 0;
    cout << "总费用输出为：" << endl;
    for (int i = 0; i < Season; ++i) {
        cout << "季节" << names[i] << "开支为：" << da[i] << endl;
        total  = total + da[i];
    }
    cout << "全部费用为:" << total;
}
// 指针传参
void showp(array<double,Season>*p)
{
    double t = 0;
    cout << "总费用输出为：" << endl;
    for (int i = 0; i < Season; ++i) {
        cout << "季节" << names[i] << "开支为：" << (*p)[i] << endl;
        t = t + (*p)[i];
    }
    cout << "全部费用为:" << t;
}
