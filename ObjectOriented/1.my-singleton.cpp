#include <iostream>
#include <mutex>
#include <atomic>
#include <queue>
#include <thread>
using namespace std;

#if 0
// 饿汉模式 -> 定义类的时候创建单例对象
// 定义一个单例模式的任务队列
class TaskQueue
{
public:
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator = (const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        return m_taskq;
    }
private:
   TaskQueue() = default;
   //TaskQueue(const TaskQueue& obj) = default;
   static TaskQueue* m_taskq;
};

TaskQueue* TaskQueue::m_taskq = new TaskQueue();

#endif

#if 0
// 懒汉模式 -> 什么时候使用这个单例对象, 在使用的时候再去创建对应的实例
// 使用双重检查锁定 + 原子变量解决线程安全问题
class TaskQueue
{
public:
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator = (const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        TaskQueue* task = m_taskq.load();
        if(task == nullptr)
        {
            m_mutex.lock();
            task = m_taskq.load();
            if(task  == nullptr)
                task  = new TaskQueue();  
            m_mutex.unlock();
        }
        return task ;
    }
private:
   TaskQueue() = default;
   static mutex m_mutex;
   //TaskQueue(const TaskQueue& obj) = default;
   static atomic<TaskQueue*> m_taskq;
};

atomic<TaskQueue*> TaskQueue::m_taskq = nullptr;
mutex TaskQueue::m_mutex;

#endif

#if 0
// 懒汉模式 -> 什么时候使用这个单例对象, 在使用的时候再去创建对应的实例
// 使用双重检查锁定 + 原子变量解决线程安全问题
class TaskQueue
{
public:
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator = (const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        static TaskQueue taskQ;
        return &taskQ;         //取地址
    }
private:
   TaskQueue() = default;
};
#endif

#if 1
// 饿汉模式 -> 巴基的本本
// 定义一个单例模式的任务队列
class TaskQueue
{
public:
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator = (const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        return m_taskq;
    }

    //判断是否为空
    bool isempty()
    {
        lock_guard<mutex> locker(m_mutex);
        return m_data.empty();
    }
    //添加任务
    void addtask(int val)
    {
        lock_guard<mutex> locker(m_mutex);
        m_data.push(val);
    }
    //删除元素
    bool poptask()
    {
        lock_guard<mutex> locker(m_mutex);
        if(m_data.empty()) return false;
        m_data.pop();
        return true;
    }
    //取出一个任务
    int taketask()
    {
        lock_guard<mutex> locker(m_mutex);
        if(m_data.empty()) return -1;
        int data = m_data.front();
        return data;
    }

private:
   TaskQueue() = default;
   //TaskQueue(const TaskQueue& obj) = default;
   static TaskQueue* m_taskq;
   queue<int> m_data;
   mutex m_mutex;
};

TaskQueue* TaskQueue::m_taskq = new TaskQueue();

#endif



int main()
{
    TaskQueue* taskQ = TaskQueue::getInstance();
    //生产者
    thread t1([=]()
    {
        for(int i=0;i<10;++i)
        {
            taskQ->addtask(i+100);
            cout<<"++push data:"<<i+100<<",threadID:"<<
                this_thread::get_id()<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });
    //消费者
    thread t2([=]()
    {
        this_thread::sleep_for(chrono::milliseconds(100));
        while(!taskQ->isempty())
        {
            int num = taskQ->taketask();
            cout<<"++take data:"<<num<<",threadID:"<<
                this_thread::get_id()<<endl;
            taskQ->poptask();
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    });
    t1.join();
    t2.join();

    return 0;
}