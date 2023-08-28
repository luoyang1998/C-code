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
 * 5��Ա����Ҫָ��Ա�����ĸ����Ź���
 * ��Ա��Ϣ������ ���� �绰 ����
 * ͨ��Multimap������Ϣ�Ĳ��� ���� ��Ϣ
 * �ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
 */

class Worker{
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

// ����Ա��
void Create_Worker(vector<Worker> &vWorker){
    string seedName = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        Worker worker;
        worker.mName = "Ա��";
        worker.mName += seedName[i];
        worker.mAge = rand() % 10 + 20;
        worker.mTele = "11111111";
        worker.mSalary = rand() % 10000 + 10000;

        // ����Ա����Ϣ
        vWorker.push_back(worker);
    }
}
// Ա������
void WorkerByGroup(vector<Worker> &vWorker, multimap<int,Worker> &workerGroup){
    // Ա��������䲿��
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
// ��ӡÿһ����Ա����Ϣ
void ShowGroupWorkers(multimap<int,Worker>& workerGroup,int departID){

    multimap<int,Worker>::iterator it = workerGroup.find(departID);
    // �ҵ���ǰ����������
    int DepartCount = workerGroup.count(departID);
    int num = 0;
    for (multimap<int,Worker>::iterator pos=it;it!=workerGroup.end()&&num<DepartCount;pos++,num++) {
        cout << "������" << pos->second.mName << " " << "���䣺" << pos->second.mAge << " " << "����:" << pos->second.mSalary << endl;
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

    // ���Ա����Ϣ
    vector<Worker> vWorker;
    // multimap���������Ϣ
    multimap<int,Worker> workerGroup;
    // ����Ա��
    Create_Worker(vWorker);
    // Ա������
    WorkerByGroup(vWorker,workerGroup);
    // ��ӡÿһ����Ա����Ϣ
    PrintWorkerByGroup(workerGroup);

}

int main(){
    test01();
}
