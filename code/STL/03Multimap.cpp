#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SALE_DEPATMENT 1
#define DEVELOP_DEPATMENT 2
#define FINACIAL_DEPATMENT 3

/*
 * 5名员工需要指派员工在哪个部门工作
 * 人员信息：姓名 年龄 电话 工资
 * 通过Multimap进行信息的插入 保存 信息
 * 分部门显示员工信息 显示全部员工信息
 */

class Worker{
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

// 创建员工
void Create_Worker(vector<Worker> &vWorker){
    string seedName = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        Worker worker;
        worker.mName = "员工";
        worker.mName += seedName[i];
        worker.mAge = rand() % 10 + 20;
        worker.mTele = "11111111";
        worker.mSalary = rand() % 10000 + 10000;

        // 保存员工信息
        vWorker.push_back(worker);
    }
}
// 员工分组
void WorkerByGroup(vector<Worker> &vWorker, multimap<int,Worker> &workerGroup){
    // 员工随机分配部门
    srand(time(NULL));
    for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++){
        int departID = rand() % 3 + 1;  // [1,3]
        switch (departID) {
            case SALE_DEPATMENT:
                workerGroup.insert(make_pair(SALE_DEPATMENT,*it));
                break;
            case DEVELOP_DEPATMENT:
                workerGroup.insert(make_pair(DEVELOP_DEPATMENT,*it));
                break;
            case FINACIAL_DEPATMENT:
                workerGroup.insert(make_pair(FINACIAL_DEPATMENT,*it));
                break;
            default:
                break;
        }
    }
}
// 打印每一部分员工信息
void ShowGroupWorkers(multimap<int,Worker>& workerGroup,int departID){

    multimap<int,Worker>::iterator it = workerGroup.find(departID);
    // 找到当前部门总人数
    int DepartCount = workerGroup.count(departID);
    int num = 0;
    for (multimap<int,Worker>::iterator pos=it;it!=workerGroup.end()&&num<DepartCount;pos++,num++) {
        cout << "姓名：" << pos->second.mName << " " << "年龄：" << pos->second.mAge << " " << "工资:" << pos->second.mSalary << endl;
    }
}
void PrintWorkerByGroup(multimap<int,Worker> &workerGroup){
    cout << "SALE_DEPATMENT" << endl;
    ShowGroupWorkers(workerGroup,SALE_DEPATMENT);
    cout << "DEVELOP_DEPATMENT" << endl;
    ShowGroupWorkers(workerGroup,DEVELOP_DEPATMENT);
    cout << "FINACIAL_DEPATMENT" << endl;
    ShowGroupWorkers(workerGroup,FINACIAL_DEPATMENT);
}

void test01(){

    // 存放员工信息
    vector<Worker> vWorker;
    // multimap保存分组信息
    multimap<int,Worker> workerGroup;
    // 创建员工
    Create_Worker(vWorker);
    // 员工分组
    WorkerByGroup(vWorker,workerGroup);
    // 打印每一部分员工信息
    PrintWorkerByGroup(workerGroup);

}

int main(){
    test01();
}
