#include <iostream>
using namespace std;

class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;
    virtual string whoAmI() = 0;
    virtual void setnum(int num) = 0;
    virtual ~GermaSoldier() {}
};

class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override
    {
        return new Soldier66(*this);
    }
    string whoAmI() override
    {
        cout<<"编号"<<m_num<<endl;
        return string("我是杰尔马66的超级士兵!!!");
    }
    void setnum(int num)
    {
        m_num = num;
    }
private:
    int m_num = 8 ;
};

class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier* clone()
    {
        return new Soldier67(*this);
    }
    string whoAmI() override
    {
        cout<<"编号"<<m_num<<endl;
        return string("我是杰尔马67的超级士兵!!!");
    }
    void setnum(int num)
    {
        m_num = num;
    }
private:
    int m_num = 9;
};

int main()
{
    //GermaSoldier* soldier = new GermaSoldier();
    GermaSoldier* soldier66 = new Soldier66;
    soldier66->setnum(12);
    GermaSoldier* s = soldier66->clone();
    cout<<s->whoAmI()<<endl;
}