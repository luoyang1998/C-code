#include <iostream>
using namespace std;
int fill_array(double arr[], int limit);
void show_array(const double arr[],int n);
void revalue(double r,double arr[],int n);

//  ʹ��һ�������¼���ز��ļ�ֵ��1.����������Ӽ۸񲢰����Ǽ۸�������� 2.�������з�������ͬ�������ӻ���٣�����һ��ϵ�����ٴ�������ӵļ۸�

int main()
{
    const int Max{5};
    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties,size);
    if (size > 0){
        cout << "�������ع�ϵ����";
        double factor{};
        while (!(cin>>factor)) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "����������һ������";
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
        cout << "���Ӽ۸� ��" << (i+1) << ":";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
//            int b = cin.get();
//            cout << b;
            // �ж������Ƿ�Ϊ�س�
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "�����������������룡";
            break;
        } else if(temp < 0){
            cout << "����Ϊ������";
        }
        arr[i] = temp;
    }
    return i;
}
void show_array(const double arr[],int n)
{
    for (int i = 0; i < n; i++) {
        cout << "���Ӽ۸�Ϊ" << (i+1) << ":" << arr[i] << endl;
    }
}
void revalue(double r,double arr[],int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] *= r;
    }
}

