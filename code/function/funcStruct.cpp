#include <iostream>
using namespace std;

// 第一天路程时长5:45，第二天时长4:55，第三天4:32。
// 1.算出前二天总路程时间
// 2.算出三天总路程时间

struct travel_time
{
    int hours;
    int mins;
};
// 先声明结构体
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
//    cout << "两天的时间为：";
//    show_time(trip);
//
//    cout << "三天的时间为：";
//    show_time(sum(trip,day3));

    travel_time trip = sump(&day1,&day2);
    cout << "两天的时间为：";
    show_timep(&trip);

    // sum(trip,day3)为临时变量 不存在地址
    cout << "三天的时间为：";
    travel_time trip2 = sump(&trip,&day3);
    show_timep(&trip2);
}
// 传递结构的指针
travel_time sump(const travel_time* t1,const travel_time* t2)
{
    travel_time total;
    total.mins = (t1->mins + t2->mins) % 60;
    total.hours = t1->hours + t2->hours + (t1->mins + t2->mins) / 60;
    return total;
}
void show_timep(const travel_time* t)
{
    cout << t->hours << "小时" << t->mins << "分钟" << endl;
}

// 结构体返回类型函数
travel_time sum(travel_time t1,travel_time t2)
{
    travel_time total;
    total.mins = (t1.mins + t2.mins) % 60;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / 60;
    return total;
}
void show_time(travel_time t)
{
    cout << t.hours << "小时" << t.mins << "分钟" << endl;
}