#include<iostream>
using namespace std;
void fill_arr(int *arr,unsigned int sizex,unsigned int sizey);
void show_arr(int* arr,unsigned int sizex,unsigned int sizey);
// 定义一个二维数组，给数组赋值，并输出

int main()
{
    unsigned int x{},y{};
    cout << "请输入数组的x,y：" << endl;
    for (int i = 0; i < 2; i++) {
        if (i == 0){
            cin >> x;
        }
        if (i == 1){
            cin >> y;
        }
        if (!cin){
            cin.clear();
            while (cin.get() != '\n'){
                continue;
            }
            cout << "您输入的不是正整数！请重新输入！" << endl;
            break;
        }
    }
    int* p = new int[x * y];
    cout << "数组已经创建完毕！请赋值！" << endl;
    fill_arr(p,x,y);
    cout << "写入成功！显示写入数组：" << endl;
    show_arr(p,x,y);
    return 0;
}
void fill_arr(int* arr,unsigned int sizex,unsigned int sizey)
{
    for (int i = 0; i < sizex; i++) {
        for (int j = 0; j < sizey; j++) {
            cin >> arr[i * sizey + j];
        }
    }
}
void show_arr(int* arr,unsigned int sizex,unsigned int sizey)
{
    for (int i = 0; i < sizex; i++) {
        for (int j = 0; j < sizey; j++) {
            cout << arr[i * sizey + j] << " ";
        }
        cout << endl;
    }
}