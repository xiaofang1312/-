#include <iostream>
using namespace std;

enum class RequestType :char {QingJia, ZhangXin, CiZhi};
// ����Ĺ����߽ڵ�
class AbstractManager
{
public:
    void setNext(AbstractManager* next)
    {
        m_next = next;
    }
    virtual void handleRequest(RequestType type) = 0;
    virtual ~AbstractManager() {}
protected:
    AbstractManager* m_next = nullptr;
};

// �ײ������
class Manager : public AbstractManager
{
public:
    void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "���: ͬ����٣��ú���Ϣ~~~" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "��н: ����ҵ���ʾһ������CEO..." << " ====> ";
            m_next->handleRequest(type);
            break;
        case RequestType::CiZhi:
            cout << "��ְ: �Ҹ������ϼ���Ӧһ��..." << " ====> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

// CEO
class CEO : public AbstractManager
{
public:
    void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "���: ͬ�����, �²�Ϊ��..." << endl;
            break;
        case RequestType::ZhangXin:
            cout << "��н: �㹤�ʲ�����, ���������ȯ��..." << endl;
            break;
        case RequestType::CiZhi:
            cout << "��ְ: ����ҵ����������ϰ�..." << " ====> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

// BOSS
class Boss : public AbstractManager
{
public:
    void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout << "���: ֻ�й�������ʵ��������ֵ����ȥ�úü��ظ�λ������" << endl;
            break;
        case RequestType::ZhangXin:
            cout << "��н: Ǯ��������֮��, Ҫ���������!!!" << endl;
            break;
        case RequestType::CiZhi:
            cout << "��ְ: ����˹����������ļ�, ��ΰ�������, �´α�������!!!" << endl;
            break;
        default:
            break;
        }
    }
};

// �ύ�������
class DaCongMing
{
public:
    void request(RequestType type, AbstractManager* manager)
    {
        manager->handleRequest(type);
    }
};

#if 0
int main()
{
    Manager* manager = new Manager;
    CEO* ceo = new CEO;
    Boss* boss = new Boss;
    manager->setNext(ceo);
    ceo->setNext(boss);

    // ����Ա����ʵ��
    DaCongMing* boy = new DaCongMing;
    cout << "�����ֱ�ӽ������ύ����ͷ��˾" << endl;
    boy->request(RequestType::CiZhi, manager);
    boy->request(RequestType::ZhangXin, manager);
    boy->request(RequestType::QingJia, manager);

    cout << "�����ֱ�ӽ������ύ��CEO" << endl;
    boy->request(RequestType::CiZhi, ceo);
    boy->request(RequestType::ZhangXin, ceo);
    boy->request(RequestType::QingJia, ceo);

    cout << "�����ֱ�ӽ������ύ��boss" << endl;
    boy->request(RequestType::CiZhi, boss);
    boy->request(RequestType::ZhangXin, boss);
    boy->request(RequestType::QingJia, boss);

    delete boy;
    delete manager;
    delete ceo;
    delete boss;

    return 0;
}
#endif