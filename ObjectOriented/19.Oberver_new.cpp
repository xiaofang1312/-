#include <iostream>
#include <list>
using namespace::std;

class Oberver;
class Newsagency
{
public:
    void attch(Oberver* observe)
    {
        m_subscriber.push_back(observe);
    }
    void detach(Oberver* observe)
    {
        m_subscriber.remove(observe);
    }
    virtual void notify() = 0;
    virtual ~Newsagency() 
    {
        m_subscriber.clear();
    }
protected:
    list<Oberver*> m_subscriber;
};

class Oberver
{
public:
    Oberver() = default;
    Oberver(Newsagency* newsagentcy):m_newsagentcy(newsagentcy) 
    {
        if(m_newsagentcy)
            m_newsagentcy->attch(this);
    }
    void attch(Newsagency* newsagency)
    {
        m_newsagentcy = newsagency;                             //订阅
        m_newsagentcy->attch(this);
    }
    void detch()
    {
        m_newsagentcy->detach(this);
        m_newsagentcy = nullptr;                                  //取消订阅
    }
    virtual void update(string msg) = 0;
    virtual ~Oberver() 
    {
        if(m_newsagentcy)
        {
            m_newsagentcy->detach(this);
        }
    }
protected:
    Newsagency* m_newsagentcy = nullptr;                        //订阅的新闻机构
};

class Agency1 : public Newsagency
{
public:
    using Newsagency::Newsagency;
    string news()
    {
        return "agnet1的独家新闻";
    }
    void notify() override
    {
        string msg = news();
        for(auto item:m_subscriber)
        {
            item->update(msg);
        }
    }
};

class Dragon : public Oberver
{
public:
    using Oberver::Oberver;
    void update(string msg) override 
    {
        cout<<"Dragon接受到新闻"<<msg<<endl;
    }
};

class Shanks : public Oberver
{
public:
    using Oberver::Oberver;
    void update(string msg) override 
    {
        cout<<"Shanks接受到新闻"<<msg<<endl;
    }
};

int main()
{
    Newsagency* agent1 = new Agency1();
    Oberver* observer1 = new Dragon(agent1);
    Shanks* observer2 = new Shanks(agent1);
    agent1->notify();
    observer1->detch();
    observer2->detch();
    delete agent1;
    delete observer1;
    delete observer2;
}