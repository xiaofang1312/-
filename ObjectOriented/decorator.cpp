#include <iostream>

using namespace::std;

// 战士的抽象类
class Soldier
{
public:
    Soldier() {}
    Soldier(string name) : m_name(name) {}
    string getName() 
    { 
        return m_name;
    };
    virtual void fight() = 0;
    virtual ~Soldier() {}
protected:
    string m_name = string();
};

// 黑胡子(Marshall·D·Teach)
class Teach : public Soldier
{
public:
    using Soldier::Soldier;
    void fight() override
    {
        cout << m_name << "依靠惊人的力量和高超的体术战斗..." << endl;
    }
};

// 抽象的恶魔果实
class DevilFruit : public Soldier
{
public:
    // 指定要给哪个人吃恶魔果实 -- 附魔
    void enchantment(Soldier* soldier)                        //类的作用是给某个Soldier的子类对象附魔  
    {
        m_human = soldier;
        m_name = m_human->getName();
    }
    virtual ~DevilFruit() {}
protected:
    Soldier* m_human = nullptr;
};

// 暗暗果实
class DarkFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        // 使用当前恶魔果实的能力
        cout << m_human->getName() 
            << "吃了暗暗果实, 可以拥有黑洞一样的无限吸引力..." << endl;
        warning();
    }
private:
    void warning()
    {
        cout << m_human->getName() 
            << "你要注意: 吃了暗暗果实, 身体元素化之后不能躲避攻击，会吸收所有伤害!" << endl;
    }
};

// 震震果实
class QuakeFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        cout << m_human->getName() 
            << "吃了震震果实, 可以在任意空间引发震动, 摧毁目标...!" << endl;
    }
};

// 大饼果实
class PieFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        cout << m_human->getName()
            << "吃了大饼果实, 获得大饼铠甲...!" << endl;
        ability();
    }

    void ability()
    {
        cout << "最强辅助 -- 大饼果实可以将身边事物变成大饼, 帮助自己和队友回血..." << endl;
    }
};

int main()
{
    Teach* teach = new Teach("马歇尔·D·蒂奇");
    DarkFruit* dark = new DarkFruit();
    QuakeFruit* quake = new QuakeFruit();
    PieFruit* pie = new PieFruit();
    dark->enchantment(teach);
    quake->enchantment(dark);
    pie->enchantment(quake);
    pie->fight();
    return 0;
}
