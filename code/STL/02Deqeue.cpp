#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

/*
 * 评委打分：
 * 1. 创建5个选手（姓名，得分），10个评委对5个选手进行打分
 * 2. 得分规则：去除最高分，去除最低分，取出平均分
 * 3. 按得分对5名选手进行排名
 */

using namespace std;

// 选手类
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

// 创建选手
void Create_Player(vector<Player>& v){
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {

        Player p; // 构造函数
        p.mName = "选手";
        p.mName += nameSeed[i];
        p.mScore = 0;

        v.push_back(p);
    }
}

// 打分
void Set_Score(vector<Player>& v){
    // 当前学生打分
    for (vector<Player>::iterator it = v.begin(); it != v.end(); ++it) {
        deque<int> dScore;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60; // 生成区间[a,b]之间的数，rand()%(b-a+1)+a
            dScore.push_back(score);
        }
        // 对分数排序 默认从小到大
        sort(dScore.begin(),dScore.end());
//        for_each(dScore.begin(), dScore.end(), PrintScore);
//        cout << endl;
        // 去除最高最低
        dScore.pop_front();
        dScore.pop_back();

        // 求平均分
        int totalScore = 0;
        for (deque<int>::iterator dit = dScore.begin();dit!=dScore.end();dit++) {
            totalScore += (*dit);
        }

        int avgScore = totalScore / dScore.size();
        // 保存分数
        (*it).mScore = avgScore;
    }

}

// 排序规则
bool mycompare(Player& p1,Player& p2){
    return p1.mScore > p2.mScore;
}
// 根据分数排序
void Print_Rank(vector<Player>& v){
    // 排序
    sort(v.begin(),v.end(), mycompare);
    for (vector<Player>::iterator it=v.begin(); it!=v.end() ; ++it) {
        cout << "姓名：" << (*it).mName << " " << "分数：" << (*it).mScore << endl;
    }
}

void test01(){
    // 定义vector容器，保存选手信息
    vector<Player> vPlist;
    Create_Player(vPlist);
    Set_Score(vPlist);
    Print_Rank(vPlist);
}

int main(){
    test01();
}
