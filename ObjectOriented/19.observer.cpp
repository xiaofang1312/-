#include <iostream>
#include <list>
using namespace::std;

class Observer;
class NewAgency
{
public:
    void detach(Observer* custom)
    {
        m_list.remove(custom);
        //custom->
    }
    void attch(Observer* custom)
    {
        m_list.push_back(custom);
    }
    virtual void notify(string msg) = 0;
    virtual ~NewAgency() {}
protected:
    list<Observer*> m_list;
};

class Observer
{
public:
    Observer(NewAgency* agent,string name):m_news(agent),m_name(name) {}
    void unsubscribe()
    {
        m_news->detach(this);
    }
    virtual void update(string msg) = 0;
private:
    NewAgency* m_news = nullptr;
    string m_name;
};

class Dragon : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout<<"Dragon接收到信号："+msg<<endl;
    }
};

class Shanks : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout<<"Shanks接收到信号："+msg<<endl;
    }
};

class Bart : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout<<"Bart接收到信号："+msg<<endl;
    }
};



class Morgans : public NewAgency
{
public:
    void notify(string msg) override
    {
        for(auto item:m_list)
        {
            item->update("Morgans新闻报道："+msg);
        }
    }
};

class Gossip : public NewAgency
{
public:
    void notify(string msg)
    {
        for(auto item:m_list)
        {
            item->update("Gossip新闻报道："+msg);
        }
    }
};

int main()
{
    NewAgency* newag1 = new Morgans();
    Observer* dra = new Dragon(newag1,"dra");
    Observer* shanks = new Shanks(newag1,"shanks");
    Observer* bart = new Bart(newag1,"bart");
    // newag1->attch(dra);
    // newag1->attch(shanks);
    // newag1->attch(bart);
    string msg = "这是一个新闻";
    newag1->notify(msg);
    delete newag1;
    delete dra;
    delete shanks;
    delete bart;
    return 0;
}