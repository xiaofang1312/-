#include <iostream>
using namespace::std;

class Sodier
{
public:
    Sodier() = default;
    Sodier(string name):m_name(name) {}
    string getname()
    {
        return m_name;
    }
    virtual void ability() = 0;
    virtual ~Sodier() {}
protected:
    string m_name;
};

class Normal : public Sodier  //这个函数必须 1.不干扰之前的结构 2.可以加强原有对象的属性 
{
public:
    using Sodier::Sodier;
    void ability() override
    {
        cout<<"基础加成"<<endl;
    }
};

class AbstractPlus : public Sodier  //怎么给normal加成上Plus啊？
{
public:
    void enchantment(Sodier* sodier)
    {
        m_update = sodier;
        m_name = m_update->getname();
    }
    virtual ~AbstractPlus() {} 
protected:
    Sodier* m_update = nullptr;
};

class Plus1 : public AbstractPlus  
{
public:
    void ability() override 
    {
        m_update->ability();
        cout<<"额外增加能力plus1"<<endl;
    }
};

class Plus2 : public AbstractPlus  
{
public:
    void ability() override 
    {
        m_update->ability();
        cout<<"额外增加能力plus2"<<endl;
    }
};

class Plus3 : public AbstractPlus  
{
public:
    void ability() override 
    {
        m_update->ability();
        cout<<"额外增加能力plus3"<<endl;
    }
};
//不知道怎么实现装饰着模式
int main()
{
    Normal* sodier = new Normal("normal");
    Plus1* sodier1 = new Plus1;
    Plus2* sodier2 = new Plus2;
    Plus3* sodier3 = new Plus3;
    sodier1->enchantment(sodier);
    sodier2->enchantment(sodier1);
    sodier3->enchantment(sodier2);
    sodier3->ability();
}
/*
这个错误是因为 C++ 中，当你继承一个类时，如果基类（如 Sodier）没有默认构造函数（即无参数构造函数），那么派生类的默认构造函数也会被标记为已删除。

在你的代码中，Sodier 类只有一个接受参数的构造函数 Sodier(string name)，而没有无参数的默认构造函数。因此，派生类 Plus1、Plus2 和 Plus3 的默认构造函数被隐式删除了。
*/