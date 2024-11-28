#include <iostream>
using namespace::std;

enum class RequestType :char{shengzhi,jiaqin,cizhi};
class AbstractManager
{
public:
    virtual void handlerequest(RequestType obj) = 0;
    void sendtonext(RequestType obj)
    {
        m_next->handlerequest(obj);
    }
    virtual ~AbstractManager() {}
private:
    AbstractManager* m_next = nullptr;
};

class Mnager : public AbstractManager
{
public:
    virtual void handlerequest(RequestType obj)
    {
        //m_obj = obj;
        switch(obj)
        {
            case RequestType::shengzhi:
                cout<<"上级反映"<<endl;
                m_next->handlerequest(obj);
                break;
            case RequestType::qingjia:
                cout<<"ok"<<endl;
                break;
            default:
                break;
        }
    }
    void setnext(AbstractManager* next)
    {
        m_next = next;
        //m_next->handlerequest(m_obj);
    }
private:
    AbstractManager* m_next = nullptr;
    //RequestType m_obj;
};

class dacongming
{
public:
    RequestType request(RequestType obj)
    {
        return obj;
    }
};

int main()
{

}