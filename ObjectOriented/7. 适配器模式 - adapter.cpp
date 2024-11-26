#include <iostream>
using namespace std;

#if 0
// �����������è���ǹ�����ϵ
// �����
class Foreigner
{
public:
    virtual string confession() = 0;
    void setResult(string res)
    {
        cout << "Panda say: " << res << endl;
    }
    virtual ~Foreigner() {}
};

// ������
class American : public Foreigner
{
public:
    string confession() override
    {
        return "������, �Ҳ�Ҫ��!!!";
    }
};

// ������
class French : public Foreigner
{
public:
    string confession() override
    {
        return "����ǿ��, �Ҹ���!!!";
    }
};

// ��è
class Panda
{
public:
    void recvMessage(string msg)
    {
        cout << msg << endl;
    }
    string sendMessage()
    {
        return string("ǿ�������֡������ǲ����ܱ���ˡ��ԭ�µģ�");
    }
};

// ��������
class AbstractChopper
{
public:
    AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Panda m_panda;
    Foreigner* m_foreigner;
};

class EnglishChopper: public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda()
    {
        string msg = m_foreigner->confession();
        // ������è������, �������ݴ��ݸ���è
        m_panda.recvMessage("������˵: " + msg);
    }
    void translateToHuman()
    {
        string msg = m_panda.sendMessage();
        // ����è����ת��ΪӢ��, �ڴ��ݸ������
        m_foreigner->setResult("������: " + msg);
    }
};

class FrechChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda()
    {
        string msg = m_foreigner->confession();
        // ������è������, �������ݴ��ݸ���è
        m_panda.recvMessage("������˵: " + msg);
    }
    void translateToHuman()
    {
        string msg = m_panda.sendMessage();
        // ����è����ת��ΪӢ��, �ڴ��ݸ������
        m_foreigner->setResult("������: " + msg);
    }
};
#endif

#if 1
// �����������è���Ǽ̳й�ϵ
// �����
class Foreigner
{
public:
    virtual string confession() = 0;
    void setResult(string res)
    {
        cout << "Panda say: " << res << endl;
    }
    virtual ~Foreigner() {}
};

// ������
class American : public Foreigner
{
public:
    string confession() override
    {
        return "������, �Ҳ�Ҫ��!!!";
    }
};

// ������
class French : public Foreigner
{
public:
    string confession() override
    {
        return "����ǿ��, �Ҹ���!!!";
    }
};

// ��è
class Panda
{
public:
    void recvMessage(string msg)
    {
        cout << msg << endl;
    }
    string sendMessage()
    {
        return string("ǿ�������֡������ǲ����ܱ���ˡ��ԭ�µģ�");
    }
};

// ��������
class AbstractChopper : public Panda
{
public:
    AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Foreigner* m_foreigner;
};

class EnglishChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda()
    {
        string msg = m_foreigner->confession();
        // ������è������, �������ݴ��ݸ���è
        recvMessage("������˵: " + msg);
    }
    void translateToHuman()
    {
        string msg = sendMessage();
        // ����è����ת��ΪӢ��, �ڴ��ݸ������
        m_foreigner->setResult("������: " + msg);
    }
};

class FrechChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda()
    {
        string msg = m_foreigner->confession();
        // ������è������, �������ݴ��ݸ���è
        recvMessage("������˵: " + msg);
    }
    void translateToHuman()
    {
        string msg = sendMessage();
        // ����è����ת��ΪӢ��, �ڴ��ݸ������
        m_foreigner->setResult("������: " + msg);
    }
};
#endif

#if 0
int main()
{
    Foreigner* foreigner = new American;
    AbstractChopper* adapter = new EnglishChopper(foreigner);
    adapter->translateToPanda();
    adapter->translateToHuman();
    delete foreigner;
    delete adapter;
    cout << "=========================" << endl;
    foreigner = new French;
    adapter = new FrechChopper(foreigner);
    adapter->translateToPanda();
    adapter->translateToHuman();
    delete foreigner;
    delete adapter;

    return 0;
}
#endif