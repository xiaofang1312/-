#include <iostream>
#include <mutex>
#include <atomic>
using namespace::std;

#if 0
//饿汉模式
class Sigleleton
{
public:
    Sigleleton(const Sigleleton& sig) = delete;
    Sigleleton&  operator=(const Sigleleton& sig) = delete;
    static Sigleleton* creatsig()
    {
        return m_sig;
    }
    void show()
    {
        cout<<"创建成功"<<endl;
    }
private:
    Sigleleton() = default;
    static Sigleleton* m_sig;
};

Sigleleton* Sigleleton::m_sig = new Sigleleton();
#endif

#if 0
//懒汉模式,多线程（拥挤）
class Sigleleton
{
public:
    Sigleleton(const Sigleleton& sig) = delete;
    Sigleleton&  operator=(const Sigleleton& sig) = delete;
    static Sigleleton* creatsig()
    {
        m_mutex.lock();
        if(m_sig = nullptr)
        {
            m_sig = new Sigleleton();
        }
        m_mutex.unlock();
        return m_sig;
    }
    void show()
    {
        cout<<"创建成功"<<endl;
    }
private:
    Sigleleton() = default;
    static Sigleleton* m_sig;
    static mutex m_mutex;
};

Sigleleton* Sigleleton::m_sig = nullptr;
#endif

#if 0
//懒汉模式,多线程（双重检查锁定）
class Sigleleton
{
public:
    Sigleleton(const Sigleleton& sig) = delete;
    Sigleleton&  operator=(const Sigleleton& sig) = delete;
    static Sigleleton* creatsig()
    {
        if(m_sig = nullptr)
        {
            m_mutex.lock();
            if(m_sig = nullptr)
            {
                m_sig = new Sigleleton();
            }
            m_mutex.unlock();
        }
        return m_sig;
    }
    void show()
    {
        cout<<"创建成功"<<endl;
    }
private:
    Sigleleton() = default;
    static Sigleleton* m_sig;
    static mutex m_mutex;
};

Sigleleton* Sigleleton::m_sig = nullptr;
mutex Sigleleton::m_mutex;
#endif

#if 0
//懒汉模式,多线程（双重检查锁定）
class Sigleleton
{
public:
    Sigleleton(const Sigleleton& sig) = delete;
    Sigleleton&  operator=(const Sigleleton& sig) = delete;
    static Sigleleton* creatsig()
    {
        Sigleleton* task = m_sig.load();
        if(task  = nullptr)
        {
            lock_guard<mutex> locker(m_mutex);
            task = m_sig.load();
            if(task= nullptr)
            {
                task= new Sigleleton();
                m_sig.store(task);
            }            
        }
        return task;
    }
    void show()
    {
        cout<<"创建成功"<<endl;
    }
private:
    Sigleleton() = default;
    static atomic<Sigleleton*> m_sig;
    static mutex m_mutex;
};

atomic<Sigleleton*>  Sigleleton::m_sig = nullptr;
mutex Sigleleton::m_mutex;
#endif

#if 1
//懒汉模式,多线程（双重检查锁定）
class Sigleleton
{
public:
    Sigleleton(const Sigleleton& sig) = delete;
    Sigleleton&  operator=(const Sigleleton& sig) = delete;
    static Sigleleton* creatsig()
    {
        static Sigleleton* m_sig = new Sigleleton();
        return m_sig;
    }
    void show()
    {
        cout<<"创建成功"<<endl;
    }
private:
    Sigleleton() = default;
};

#endif
int main()
{
    Sigleleton* sig = Sigleleton::creatsig();
    sig->show();
    return 0;
}