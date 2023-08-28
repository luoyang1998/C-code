#include <iostream>
/*
 * 模板
 */
using namespace std;

// 函数模板
template<typename T>  // 声明一个模板,T是一个同用类型
void mySwap( T &a, T &b ) {
    T temp = a;
    a = b;
    b = temp;
}
// 使用函数模板进行交换函数
void test01() {
    int a = 10;
    int b = 20;

    // 方式一：自动类型推导
    mySwap(a,b);
    cout << a << " " << b << endl;
    // 方式二：显示指定类型
    mySwap<int>(a,b);
    cout << a << " " << b << endl;
}
int main() {
    test01();
}
