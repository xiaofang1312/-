#include <iostream>
using namespace std;

// ����Ĳ�����
class AbstractStrategy
{
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

// һ��
class YiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** ����ʹ�õ���һ��: ";
        if (isfar)
        {
            cout << "�𽺻���ǹ" << endl;
        }
        else
        {
            cout << "�𽺡�������" << endl;
        }
    }
};

// 2��
class ErDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** ����ʹ�õ���2��: ";
        if (isfar)
        {
            cout << "��Jet���" << endl;
        }
        else
        {
            cout << "��Jet����Ҵ�" << endl;
        }
    }
};

// 3��
class SanDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** ����ʹ�õ���3��: ";
        if (isfar)
        {
            cout << "�𽺾��˻�����" << endl;
        }
        else
        {
            cout << "�𽺾���ս��" << endl;
        }
    }
};

// 4��
class SiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** ����ʹ�õ���4��: ";
        if (isfar)
        {
            cout << "��ʨ�ӻ����" << endl;
        }
        else
        {
            cout << "��Ϭţ����" << endl;
        }
    }
};

// 5��
class WuDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** �л����嵲: ����Ῠ��̬���԰���������, ������ı��������̬������й���!!!" << endl;
    }
};

// ·����
enum class Level:char{Easy, Normal, Hard, Experts, Professional};
class Luffy
{
public:
    void fight(Level level, bool isfar = false)
    {
        if (m_strategy != nullptr)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
        switch (level)
        {
        case Level::Easy:
            m_strategy = new YiDang;
            break;
        case Level::Normal:
            m_strategy = new ErDang;
            break;
        case Level::Hard:
            m_strategy = new SanDang;
            break;
        case Level::Experts:
            m_strategy = new SiDang;
            break;
        case Level::Professional:
            m_strategy = new WuDang;
            break;
        default:
            break;
        }
        m_strategy->fight(isfar);
    }

    ~Luffy()
    {
        if (m_strategy != nullptr)
        {
            delete m_strategy;
        }
    }
private:
    AbstractStrategy* m_strategy = nullptr;
};

#if 0
int main()
{
    Luffy* luffy = new Luffy;
    cout << "--- ���㲨��Ⱥ�������˺���ʿ��: " << endl;
    luffy->fight(Level::Easy);
    cout << "--- ��ħ���������˱�����: " << endl;
    luffy->fight(Level::Normal);
    cout << "--- ��˾�����������޲���·��: " << endl;
    luffy->fight(Level::Hard);
    cout << "--- �ڵ���˹���������˶ล������: " << endl;
    luffy->fight(Level::Experts);
    cout << "--- �ڹ������˿���: " << endl;
    luffy->fight(Level::Professional);
    delete luffy;
    return 0;
}
#endif