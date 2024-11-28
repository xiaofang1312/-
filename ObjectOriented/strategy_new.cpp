#include <iostream>
#include <list>
using namespace::std;

enum class level : char{easy,normal,hard,experts,professional};
class strategy
{
public:
    virtual void fight() = 0;
    virtual ~strategy() {}
};

class yidang : public strategy
{
public:
    void fight() override 
    {
        cout<<"shiyongyidang"<<endl;
    }
};

class erdang : public strategy
{
public:
    void fight() override 
    {
        cout<<"shiyongerdang"<<endl;
    }
};

class sandang : public strategy
{
public:
    void fight() override 
    {
        cout<<"shiyongsandang"<<endl;
    }
};

class sidang : public strategy
{
public:
    void fight() override 
    {
        cout<<"shiyongsidang"<<endl;
    }
};

class wudang : public strategy
{
public:
    void fight() override 
    {
        cout<<"shiyongwudang"<<endl;
    }
};

class luffy
{
public:
    void fight(level obj)
    {
        if (m_strategy)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
        switch (obj)
        {
        case level::easy:
            m_strategy = new yidang;
            break;
        case level::normal:
            m_strategy = new erdang;
            break;
        case level::hard:
            m_strategy = new sandang;
            break;
        case level::experts:
            m_strategy = new sidang;
            break;
        case level::professional:
            m_strategy = new wudang;
            break;
        default:
            break;
        }
        m_strategy->fight();
    }
private:
    strategy* m_strategy = nullptr;
};

int main()
{
    luffy* lf = new luffy;
    lf->fight(level::hard);
}