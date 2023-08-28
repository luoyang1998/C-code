#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

/*
 * ��ί��֣�
 * 1. ����5��ѡ�֣��������÷֣���10����ί��5��ѡ�ֽ��д��
 * 2. �÷ֹ���ȥ����߷֣�ȥ����ͷ֣�ȡ��ƽ����
 * 3. ���÷ֶ�5��ѡ�ֽ�������
 */

using namespace std;

// ѡ����
class Player{
public:
    Player(){}
    Player(string name,int score):mName(name),mScore(score){}
public:
    string mName;
    int mScore;
};

void PrintScore(int val){
    cout << val << " ";
}

// ����ѡ��
void Create_Player(vector<Player>& v){
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {

        Player p; // ���캯��
        p.mName = "ѡ��";
        p.mName += nameSeed[i];
        p.mScore = 0;

        v.push_back(p);
    }
}

// ���
void Set_Score(vector<Player>& v){
    // ��ǰѧ�����
    for (vector<Player>::iterator it = v.begin(); it != v.end(); ++it) {
        deque<int> dScore;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60; // ��������[a,b]֮�������rand()%(b-a+1)+a
            dScore.push_back(score);
        }
        // �Է������� Ĭ�ϴ�С����
        sort(dScore.begin(),dScore.end());
//        for_each(dScore.begin(), dScore.end(), PrintScore);
//        cout << endl;
        // ȥ��������
        dScore.pop_front();
        dScore.pop_back();

        // ��ƽ����
        int totalScore = 0;
        for (deque<int>::iterator dit = dScore.begin();dit!=dScore.end();dit++) {
            totalScore += (*dit);
        }

        int avgScore = totalScore / dScore.size();
        // �������
        (*it).mScore = avgScore;
    }

}

// �������
bool mycompare(Player& p1,Player& p2){
    return p1.mScore > p2.mScore;
}
// ���ݷ�������
void Print_Rank(vector<Player>& v){
    // ����
    sort(v.begin(),v.end(), mycompare);
    for (vector<Player>::iterator it=v.begin(); it!=v.end() ; ++it) {
        cout << "������" << (*it).mName << " " << "������" << (*it).mScore << endl;
    }
}

void test01(){
    // ����vector����������ѡ����Ϣ
    vector<Player> vPlist;
    Create_Player(vPlist);
    Set_Score(vPlist);
    Print_Rank(vPlist);
}

int main(){
    test01();
}
