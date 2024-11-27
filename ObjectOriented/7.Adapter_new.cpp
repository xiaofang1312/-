#include <iostream>
using namespace::std;

class Foreigner
{
public:
    virtual string confess() = 0;
    void setResult(string msg)
    {
        cout<<"panda say:"<<msg<<endl;
    }
    virtual ~Foreigner() {}
protected:
    //Adapter* m_adapter;
};

class American : public Foreigner
{
public:
    virtual string confess() override
    {
        return "美国人的道歉";
    }   
};

class Panda 
{
public:
    void getmsg(string msg)
    {
        cout<<msg<<endl;
    }
    string sendmsg()
    {
        return "不可原谅";
    }
};

class Adapter
{
public:
    Adapter(Foreigner* foreigner,Panda* panda):m_foreigner(foreigner),m_panda(panda)  {} 
    virtual void translatetopanda() = 0;
    virtual void translatetoforeigner() = 0;
    virtual ~Adapter() {}
protected:
    Foreigner* m_foreigner;
    Panda* m_panda;
};

class Englishadapter : public Adapter
{
public:
    using Adapter::Adapter;
    void translatetopanda() override 
    {
        string str("英语转熊猫"+m_foreigner->confess());
        m_panda->getmsg(str);
    }
    void translatetoforeigner() override 
    {
        string str("熊猫转英语"+m_panda->sendmsg());
        m_foreigner->setResult(str);
    }
};

int main()
{
    Foreigner* american_ass = new American();
    Panda* panda = new Panda();
    Adapter* adapter = new Englishadapter(american_ass,panda);
    adapter->translatetoforeigner();
    adapter->translatetopanda();
}