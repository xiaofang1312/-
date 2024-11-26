#include <iostream>
#include <map>
#include <list>
using namespace std;

// ��ʦ -> �����ִ����, �ղ��������ǲ��Ṥ����
class CookerZeff
{
public:
    void makeDSX()
    {
        cout << "��ʼ��⿵�����...";
    }
    void makeYXRS()
    {
        cout << "��ʼ���������˿...";
    }
    void makeGBJD()
    {
        cout << "��ʼ��⿹�������...";
    }
    void makeHSPG()
    {
        cout << "��ʼ��⿺����Ź�...";
    }
};

// ����
class AbstractCommand
{
public:
    AbstractCommand(CookerZeff* zeff) :m_cooker(zeff) {}
    virtual void excute() = 0;
    virtual string name() = 0;
    virtual ~AbstractCommand() {}
protected:
    CookerZeff* m_cooker = nullptr;
};

class DSXCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeDSX();
    }
    string name() override
    {
        return "������";
    }
};

class GBJDCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeGBJD();
    }
    string name() override
    {
        return "��������";
    }
};

class YXRSCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeYXRS();
    }
    string name() override
    {
        return "������˿";
    }
};

class HSPGCommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    void excute() override
    {
        m_cooker->makeHSPG();
    }
    string name() override
    {
        return "�����Ź�";
    }
};

// ����Ա
class WaiterLuffy
{
public:
    // �µ�
    void setOrder(int index, AbstractCommand* command)
    {
        cout << index << "��������" << command->name() << endl;
        if (command->name() == "������˿")
        {
            cout << "û������, ������������˿, �����Ĳ˰�..." << endl;
            return;
        }
        if (m_cmdList.find(index) == m_cmdList.end())
        {
            list<AbstractCommand*> mylist{ command };
            m_cmdList.insert(make_pair(index, mylist));
        }
        else
        {
            m_cmdList[index].push_back(command);
        }
    }
    // ��������
    void cancelOrder(int index, AbstractCommand* command)
    {
        if (m_cmdList.find(index) != m_cmdList.end())
        {
            m_cmdList[index].remove(command);
            cout << index << "����, ������" << command->name() << endl;
        }
    }
    // ����
    void checkOut(int index)
    {
        cout << "��[" << index << "]�����Ĺ˿͵�Ĳ���: ��";
        for (const auto& item : m_cmdList[index])
        {
            cout << item->name();
            if (item != m_cmdList[index].back())
            {
                cout << ",";
            }
        }
        cout << "��" << endl;
    }
    // ����֪ͨ -> Ҫ���ʦִ��ĳЩ����
    void notify(int index)
    {
        for (const auto& item : m_cmdList[index])
        {
            item->excute();
            cout << index << "����" << endl;
        }
    }
private:
    map<int, list<AbstractCommand*>> m_cmdList;
};

#if 0
int main()
{
    CookerZeff* zeff = new CookerZeff;
    WaiterLuffy* luffy = new WaiterLuffy;

    YXRSCommand* yxrs = new YXRSCommand(zeff);
    DSXCommand* dsx = new DSXCommand(zeff);
    GBJDCommand* gbjd = new GBJDCommand(zeff);
    HSPGCommand* hspg = new HSPGCommand(zeff);

    cout << "�˿Ϳ�ʼ���" << endl;
    luffy->setOrder(1, yxrs);
    luffy->setOrder(1, dsx);
    luffy->setOrder(1, gbjd);
    luffy->setOrder(1, hspg);

    luffy->setOrder(2, hspg);
    luffy->setOrder(2, dsx);
    luffy->setOrder(2, gbjd);

    cout << "��������=============" << endl;
    luffy->cancelOrder(1, dsx);
    cout << "��ʼ�µ� ++++++++++++++++" << endl;
    luffy->notify(1);
    luffy->notify(2);
    cout << "����*******************" << endl;
    luffy->checkOut(1);
    luffy->checkOut(2);

    delete luffy;
    delete zeff;
    delete yxrs;
    delete dsx;
    delete gbjd;
    delete hspg;

    return 0;
}
#endif