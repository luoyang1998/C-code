#include <iostream>
using namespace std;

// ��һ��·��ʱ��5:45���ڶ���ʱ��4:55��������4:32��
// 1.���ǰ������·��ʱ��
// 2.���������·��ʱ��

struct travel_time
{
    int hours;
    int mins;
};
// �������ṹ��
travel_time sump(const travel_time* t1,const travel_time* t2);
void show_timep(const travel_time* t);
travel_time sum(travel_time t1,travel_time t2);
void show_time(travel_time t);

int main()
{
    travel_time day1{5,45};
    travel_time day2{4,55};
    travel_time day3{4,32};
//    travel_time trip = sum(day1,day2);
//    cout << "�����ʱ��Ϊ��";
//    show_time(trip);
//
//    cout << "�����ʱ��Ϊ��";
//    show_time(sum(trip,day3));

    travel_time trip = sump(&day1,&day2);
    cout << "�����ʱ��Ϊ��";
    show_timep(&trip);

    // sum(trip,day3)Ϊ��ʱ���� �����ڵ�ַ
    cout << "�����ʱ��Ϊ��";
    travel_time trip2 = sump(&trip,&day3);
    show_timep(&trip2);
}
// ���ݽṹ��ָ��
travel_time sump(const travel_time* t1,const travel_time* t2)
{
    travel_time total;
    total.mins = (t1->mins + t2->mins) % 60;
    total.hours = t1->hours + t2->hours + (t1->mins + t2->mins) / 60;
    return total;
}
void show_timep(const travel_time* t)
{
    cout << t->hours << "Сʱ" << t->mins << "����" << endl;
}

// �ṹ�巵�����ͺ���
travel_time sum(travel_time t1,travel_time t2)
{
    travel_time total;
    total.mins = (t1.mins + t2.mins) % 60;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / 60;
    return total;
}
void show_time(travel_time t)
{
    cout << t.hours << "Сʱ" << t.mins << "����" << endl;
}