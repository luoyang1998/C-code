//
// Created by ASUS on 2023/7/21.
//

#include <iostream>
#include <mutex>
#include <atomic>
#include <queue>
#include <thread>
using namespace std;

// 定义一个单例模式的任务队列
// 饿汉模式->初始化时创建单例模式对像
class TaskQueue1 {
public:
    TaskQueue1(const TaskQueue1 &t) = delete;

    TaskQueue1 &operator=(const TaskQueue1 &t) = delete;

    static TaskQueue1 *getInstance() {
        return m_taskQ;
    }

    void print() {
        cout << "单例对象的一个成员函数。。。" << endl;
    }

private:
    TaskQueue1() = default;

//    TaskQueue1(const TaskQueue &t) = default;
//    TaskQueue1& operator=(const TaskQueue1 &t) = default;
    // 只能通过类名访问静态属性或方法
    static TaskQueue1 *m_taskQ;
};

TaskQueue1 *TaskQueue1::m_taskQ = new TaskQueue1;


// 懒汉模式->在使用的时候再去创建对应的实例，节省内存空间，多线程线程安全问题
class TaskQueue2 {
public:
    TaskQueue2(const TaskQueue2 &t) = delete;

    TaskQueue2 &operator=(const TaskQueue2 &t) = delete;

    static TaskQueue2 *getInstance() {
        TaskQueue2 *task = m_taskQ.load(); // 从原子中加载任务对象的实例
        // 双重检查锁定
        if (task == nullptr) {
            // 多线程安全问题，加锁
            m_mutex.lock();
            task = m_taskQ.load();
            if (task == nullptr) {
                task = new TaskQueue2;
                m_taskQ.store(task); // 存储在原子变量中
            }
            m_mutex.unlock();
        }
        return task;
    }

    void print() {
        cout << "单例对象的一个成员函数。。。" << endl;
    }

private:
    TaskQueue2() = default;

//    TaskQueue2(const TaskQueue &t) = default;
//    TaskQueue2& operator=(const TaskQueue2 &t) = default;
    // 只能通过类名访问静态属性或方法
//    static TaskQueue2* m_taskQ;
    static mutex m_mutex;
    static atomic<TaskQueue2 *> m_taskQ;
};

// 使用静态的局部对象解决线程安全问题->编译器必须支持c++11
class TaskQueue3 {
public:
    TaskQueue3(const TaskQueue3 &t) = delete;

    TaskQueue3 &operator=(const TaskQueue3 &t) = delete;

    static TaskQueue3 *getInstance() {
        static TaskQueue3 task;
        return &task;
    }

    void print() {
        cout << "单例对象的一个成员函数。。。" << endl;
    }

private:
    TaskQueue3() = default;
//    TaskQueue3(const TaskQueue &t) = default;
//    TaskQueue3& operator=(const TaskQueue3 &t) = default;
};

// 任务队列
class TaskQueue4 {
public:
    TaskQueue4(const TaskQueue4 &t) = delete;

    TaskQueue4 &operator=(const TaskQueue4 &t) = delete;

    static TaskQueue4 *getInstance() {
        return m_taskQ;
    }

    void print() {
        cout << "单例对象的一个成员函数。。。" << endl;
    }

    // 判断队列是否为空
    bool isEmpty() {
        lock_guard<mutex> locker(m_mutex); // locker对象管理锁，对象析构时解锁
        return m_data.empty();
    }

    // 添加任务
    void addTask(int node) {
        lock_guard<mutex> locker(m_mutex);
        m_data.push(node);
    }

    // 删除任务
    bool delTask() {
        lock_guard<mutex> locker(m_mutex);
        if (m_data.empty()) {
            return false;
        }
        m_data.pop();
        return true;
    }
    // 取出一个任务
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

    // 只能通过类名访问静态属性或方法
    static TaskQueue4 *m_taskQ;
    queue<int> m_data;
    mutex m_mutex;
};

TaskQueue4* TaskQueue4::m_taskQ = new TaskQueue4;


int main() {
//    TaskQueue2 *taskQ = TaskQueue2::getInstance();
//    taskQ->print();
    TaskQueue4 *taskQ = TaskQueue4::getInstance();
    // 生产者
    thread t1([=](){ // taskQ外部命令无法获得，[=]
        for (int i = 0; i < 10; ++i) {
            taskQ->addTask(i+10);
            cout << "+++ push data:" << i+10 << ", threadID:" << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });
    // 消费者
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