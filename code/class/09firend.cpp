#include <iostream>
#include <string>
/* ��Ԫ
 * 1.ȫ�ֺ�������Ԫ
 * 2.������Ԫ
 * 3.��Ա��������Ԫ */
using namespace std;

class Building;
// 2.��
class GoodFriend
{
public:
    GoodFriend(); // ������ʵ��
    void visit(); // ����BUilding����

    Building *building;
};
// 3.��Ա����
class GoodFriend02
{
public:
    GoodFriend02(); // ������ʵ��
    void visit01(); // ����BUilding����
    void visit02(); // ���ʲ�������

    Building *building;
};

class Building
{
    // ��Ԫ����
    friend void goodFriend(Building *building);
    friend class GoodFriend;
    friend void GoodFriend02::visit01(); // ��������visit01 visit��������Ҫ��Building֮ǰ��������ʵ��
public:
    Building() // ���캯��
    {
        m_SittingRoom = "����";
        m_BedRoom = "����";
    }
public:
    string m_SittingRoom; //����
private:
    string m_BedRoom;
};
// �������� ����ʵ��
GoodFriend::GoodFriend() {
    building = new Building;
}
void GoodFriend::visit() {
    cout << "�� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
    cout << "�� ���ڷ��ʣ�" << building->m_BedRoom << endl;
}

// 3.��Ա����
// �������� ����ʵ��
GoodFriend02::GoodFriend02() {
    building = new Building;
}
void GoodFriend02::visit01() {
    cout << "��Ա���� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
    cout << "��Ա���� ���ڷ��ʣ�" << building->m_BedRoom << endl;
}
void GoodFriend02::visit02() {
    cout << "��Ա���� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
//    cout << "��Ա���� ���ڷ��ʣ�" << building->m_BedRoom << endl;
}

// 1.ȫ�ֺ���
// ȫ�ֺ���
void goodFriend(Building *building)
{
    cout << "ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
    cout << "ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;
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