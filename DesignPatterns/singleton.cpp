//
// Created by ASUS on 2023/7/21.
//

#include <iostream>
#include <mutex>
#include <atomic>
#include <queue>
#include <thread>
using namespace std;

// ����һ������ģʽ���������
// ����ģʽ->��ʼ��ʱ��������ģʽ����
class TaskQueue1 {
public:
    TaskQueue1(const TaskQueue1 &t) = delete;

    TaskQueue1 &operator=(const TaskQueue1 &t) = delete;

    static TaskQueue1 *getInstance() {
        return m_taskQ;
    }

    void print() {
        cout << "���������һ����Ա����������" << endl;
    }

private:
    TaskQueue1() = default;

//    TaskQueue1(const TaskQueue &t) = default;
//    TaskQueue1& operator=(const TaskQueue1 &t) = default;
    // ֻ��ͨ���������ʾ�̬���Ի򷽷�
    static TaskQueue1 *m_taskQ;
};

TaskQueue1 *TaskQueue1::m_taskQ = new TaskQueue1;


// ����ģʽ->��ʹ�õ�ʱ����ȥ������Ӧ��ʵ������ʡ�ڴ�ռ䣬���߳��̰߳�ȫ����
class TaskQueue2 {
public:
    TaskQueue2(const TaskQueue2 &t) = delete;

    TaskQueue2 &operator=(const TaskQueue2 &t) = delete;

    static TaskQueue2 *getInstance() {
        TaskQueue2 *task = m_taskQ.load(); // ��ԭ���м�����������ʵ��
        // ˫�ؼ������
        if (task == nullptr) {
            // ���̰߳�ȫ���⣬����
            m_mutex.lock();
            task = m_taskQ.load();
            if (task == nullptr) {
                task = new TaskQueue2;
                m_taskQ.store(task); // �洢��ԭ�ӱ�����
            }
            m_mutex.unlock();
        }
        return task;
    }

    void print() {
        cout << "���������һ����Ա����������" << endl;
    }

private:
    TaskQueue2() = default;

//    TaskQueue2(const TaskQueue &t) = default;
//    TaskQueue2& operator=(const TaskQueue2 &t) = default;
    // ֻ��ͨ���������ʾ�̬���Ի򷽷�
//    static TaskQueue2* m_taskQ;
    static mutex m_mutex;
    static atomic<TaskQueue2 *> m_taskQ;
};

// ʹ�þ�̬�ľֲ��������̰߳�ȫ����->����������֧��c++11
class TaskQueue3 {
public:
    TaskQueue3(const TaskQueue3 &t) = delete;

    TaskQueue3 &operator=(const TaskQueue3 &t) = delete;

    static TaskQueue3 *getInstance() {
        static TaskQueue3 task;
        return &task;
    }

    void print() {
        cout << "���������һ����Ա����������" << endl;
    }

private:
    TaskQueue3() = default;
//    TaskQueue3(const TaskQueue &t) = default;
//    TaskQueue3& operator=(const TaskQueue3 &t) = default;
};

// �������
class TaskQueue4 {
public:
    TaskQueue4(const TaskQueue4 &t) = delete;

    TaskQueue4 &operator=(const TaskQueue4 &t) = delete;

    static TaskQueue4 *getInstance() {
        return m_taskQ;
    }

    void print() {
        cout << "���������һ����Ա����������" << endl;
    }

    // �ж϶����Ƿ�Ϊ��
    bool isEmpty() {
        lock_guard<mutex> locker(m_mutex); // locker�������������������ʱ����
        return m_data.empty();
    }

    // �������
    void addTask(int node) {
        lock_guard<mutex> locker(m_mutex);
        m_data.push(node);
    }

    // ɾ������
    bool delTask() {
        lock_guard<mutex> locker(m_mutex);
        if (m_data.empty()) {
            return false;
        }
        m_data.pop();
        return true;
    }
    // ȡ��һ������
    int takeTask(){
        lock_guard<mutex> locker(m_mutex);
        if (m_data.empty()) {
            return -1;
        }
        int data = m_data.front();
        return data;
    }
private:
    TaskQueue4() = default;

    // ֻ��ͨ���������ʾ�̬���Ի򷽷�
    static TaskQueue4 *m_taskQ;
    queue<int> m_data;
    mutex m_mutex;
};

TaskQueue4* TaskQueue4::m_taskQ = new TaskQueue4;


int main() {
//    TaskQueue2 *taskQ = TaskQueue2::getInstance();
//    taskQ->print();
    TaskQueue4 *taskQ = TaskQueue4::getInstance();
    // ������
    thread t1([=](){ // taskQ�ⲿ�����޷���ã�[=]
        for (int i = 0; i < 10; ++i) {
            taskQ->addTask(i+10);
            cout << "+++ push data:" << i+10 << ", threadID:" << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });
    // ������
    thread t2([=](){
        this_thread::sleep_for(chrono::milliseconds(100));
        while (!taskQ->isEmpty()) {
            int num = taskQ->takeTask();
            cout << "+++ take data:" << num << ", threadID:" << this_thread::get_id() << endl;
            taskQ->delTask();
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    });
    t1.join();
    t2.join();
}