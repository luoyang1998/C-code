#include <iostream>
using namespace std;
int fill_array(double arr[], int limit);
void show_array(const double arr[],int n);
void revalue(double r,double arr[],int n);

//  使用一个数组记录房地产的价值。1.输入五个房子价格并把他们价格输出出来 2.假设所有房子以相同比例增加或减少，输入一个系数，再次输出房子的价格

int main()
{
    const int Max{5};
    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties,size);
    if (size > 0){
        cout << "请输入重估系数：";
        double factor{};
        while (!(cin>>factor)) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "请重新输入一个数：";
        }
        revalue(factor,properties,size);
        show_array(properties,size);
    }
}
int fill_array(double arr[], int limit)
{
    double temp{};
    int i{};
    for(i = 0; i < limit; i++) {
        cout << "房子价格 第" << (i+1) << ":";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
//            int b = cin.get();
//            cout << b;
            // 判断输入是否为回车
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "输入有误，请重新输入！";
            break;
        } else if(temp < 0){
            cout << "输入为负数！";
        }
        arr[i] = temp;
    }
    return i;
}
void show_array(const double arr[],int n)
{
    for (int i = 0; i < n; i++) {
        cout << "房子价格为" << (i+1) << ":" << arr[i] << endl;
    }
}
void revalue(double r,double arr[],int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] *= r;
    }
}

