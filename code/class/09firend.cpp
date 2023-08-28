#include <iostream>
#include <string>
/* 友元
 * 1.全局函数做友元
 * 2.类做友元
 * 3.成员函数做友元 */
using namespace std;

class Building;
// 2.类
class GoodFriend
{
public:
    GoodFriend(); // 类外是实现
    void visit(); // 访问BUilding属性

    Building *building;
};
// 3.成员函数
class GoodFriend02
{
public:
    GoodFriend02(); // 类外是实现
    void visit01(); // 访问BUilding属性
    void visit02(); // 访问不到属性

    Building *building;
};

class Building
{
    // 友元声明
    friend void goodFriend(Building *building);
    friend class GoodFriend;
    friend void GoodFriend02::visit01(); // 这里声明visit01 visit所在类需要在Building之前，且类外实现
public:
    Building() // 构造函数
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;
};
// 类内声明 类外实现
GoodFriend::GoodFriend() {
    building = new Building;
}
void GoodFriend::visit() {
    cout << "类 正在访问：" << building->m_SittingRoom << endl;
    cout << "类 正在访问：" << building->m_BedRoom << endl;
}

// 3.成员函数
// 类内声明 类外实现
GoodFriend02::GoodFriend02() {
    building = new Building;
}
void GoodFriend02::visit01() {
    cout << "成员函数 正在访问：" << building->m_SittingRoom << endl;
    cout << "成员函数 正在访问：" << building->m_BedRoom << endl;
}
void GoodFriend02::visit02() {
    cout << "成员函数 正在访问：" << building->m_SittingRoom << endl;
//    cout << "成员函数 正在访问：" << building->m_BedRoom << endl;
}

// 1.全局函数
// 全局函数
void goodFriend(Building *building)
{
    cout << "全局函数 正在访问：" << building->m_SittingRoom << endl;
    cout << "全局函数 正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
    Building building;
    goodFriend(&building);
}
void test02()
{
    GoodFriend gf;
    gf.visit();
}
void test03()
{
    GoodFriend02 gf;
    gf.visit01();
    gf.visit02();
}
int main()
{
//    test01();
//    test02();
    test03();
}