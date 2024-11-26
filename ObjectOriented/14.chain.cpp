#include <iostream>
using namespace::std;

enum class Request :char {qingjia,zhangxin,cizhi};
class AbstractManager
{
public:
    void setNext(AbstractManager* manager)
    {
        m_next = manager;
    }
    virtual void handleRequsest(Request request) = 0;
    virtual ~AbstractManager() {}
protected:
    AbstractManager* m_next = nullptr;
};

class Manager : public AbstractManager
{
public:
    void handleRequsest(Request type) override
    {
        switch (type)
        {
        case Request::qingjia:
            cout << "请假: 同意请假，好好休息~~~" << endl;
            break;
        case Request::zhangxin:
            cout << "涨薪: 这个我得请示一下咱们CEO..." << " ====> ";
            m_next->handleRequsest(type);
            break;
        case Request::cizhi:
            cout << "辞职: 我给你向上级反应一下..." << " ====> ";
            m_next->handleRequsest(type);
            break;
        default:
            break;
        }
    }
};

class CEO : public AbstractManager
{
public:
    void handleRequsest(Request request) override 
    {
        switch (request)
        {
        case Request::qingjia:
            cout << "请假: 同意请假, 下不为例..." << endl;
            break;
        case Request::zhangxin:
            cout << "涨薪: 你工资不少了, 给你个购物券吧..." << endl;
            break;
        case Request::cizhi:
            cout << "辞职: 这个我得问问咱们老板..." << " ====> ";
            m_next->handleRequsest(request);
            break;
        default:
            break;
        }
    }
};

class BOSS : public AbstractManager
{
public:
    void handleRequsest(Request request) override 
    {
        switch (request)
        {
        case Request::qingjia:
            cout << "请假: 只有工作才能实现人生价值，回去好好坚守岗位！！！" << endl;
            break;
        case Request::zhangxin:
            cout << "涨薪: 钱财乃身外之物, 要视其如粪土!!!" << endl;
            break;
        case Request::cizhi:
            cout << "辞职: 巴洛克工作社就是你的家, 这次把你留下, 下次别再提了!!!" << " ====> ";
            break;
        default:
            break;
        }
    }
};

class dacongming
{
public:
    void request(Request request,AbstractManager* Next)
    {
        Next->handleRequsest(request);
    }
};

int main()
{
    Manager* manager = new Manager();
    CEO* ceo = new CEO();
    BOSS* boss = new BOSS();

    manager->setNext(ceo);
    ceo->setNext(boss);

    dacongming* boy = new dacongming;
    cout << "========== 大聪明向顶头上司提要求 ==========" << endl;
    boy->request(Request::qingjia, manager);
    boy->request(Request::zhangxin, manager);
    boy->request(Request::cizhi, manager);
    cout << "========== 大聪明越级找CEO提要求 ==========" << endl;
    boy->request(Request::qingjia, ceo);
    boy->request(Request::zhangxin, ceo);
    boy->request(Request::cizhi, ceo);
    cout << "========== 大聪明直接找BOSS提要求 ==========" << endl;
    boy->request(Request::qingjia, boss);
    boy->request(Request::zhangxin, boss);
    boy->request(Request::cizhi, boss);

    delete boy;
    delete manager;
    delete ceo;
    delete boss;

    return 0;

}