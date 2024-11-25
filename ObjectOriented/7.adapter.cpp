#include<iostream>
using namespace::std;

class Foreigner
{
public:
    virtual string confession() = 0;
    virtual ~Foreigner() {}
    void setResult(string msg)
    {
        cout << "Panda Say: " << msg << endl;
    }
};

class American : public Foreigner
{
public:
    string confession() override
    {
        return string("人：美国人的忏悔");
    }
};

class Franch : public Foreigner
{
public:
    string confession()
    {
        return "人：法国人的忏悔";
    }
};

class Panda
{
public:
    void recvMessage(string msg)
    {
        cout<<"大熊猫接收到"+msg<<endl;
    }
    string sendMessage()
    {
        return "熊猫说不能原谅";
    }
};
class AbstractChopper : public Panda
{
public:
    AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Foreigner* m_foreigner = nullptr;
};

class EnglishChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // 翻译并将信息传递给熊猫对象
        recvMessage("美国人说: " + msg);
    }
    void translateToHuman() override
    {
        // 接收熊猫的信息
        string msg = sendMessage();
        // 翻译并将熊猫的话转发给美国人
        m_foreigner->setResult("美国佬, " + msg);
    }
};

class FrenchChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // 翻译并将信息传递给熊猫对象
        recvMessage("法国人说: " + msg);
    }
    void translateToHuman() override
    {
        // 接收熊猫的信息
        string msg = sendMessage();
        // 翻译并将熊猫的话转发给法国人
        m_foreigner->setResult("法国佬, " + msg);
    }
};

int main()
{
    Foreigner* foreigner = new  American;
    AbstractChopper* adapter = new EnglishChopper(foreigner);
    adapter->translateToPanda();
    adapter->translateToHuman();
    delete foreigner;
    delete adapter;
    cout<<"++++++++++++++++++++++++++++++"<<endl;
    foreigner = new Franch;
    adapter = new FrenchChopper(foreigner);
    adapter->translateToPanda();
    adapter->translateToHuman();
    delete foreigner;
    delete adapter;
    return 0;
}