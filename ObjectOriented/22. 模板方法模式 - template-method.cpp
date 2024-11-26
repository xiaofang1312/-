#include <iostream>
using namespace std;

// �����������
class AbstractRobot
{
public:
    // ����
    virtual void weapon() = 0;
    // ���
    virtual void appearance() = 0;
    // ս������
    virtual void fightAbility() = 0;
    // ����
    virtual string getName() = 0;
    // ��������
    virtual void selfHealing() {}
    // �Ƿ��ܷ�
    virtual bool canFlying()
    {
        return false;
    }
    // �Ƿ�����Զ�����
    virtual bool isAuto()
    {
        return true;
    }
    // �õ���ǰ�����˵�����
    virtual void getProperty()
    {
        cout << "�����ӿ������" << getName() << "����������: " << endl;
        if (canFlying())
        {
            cout << "�з�������..." << endl;
        }
        else
        {
            cout << "û�з�������..." << endl;
        }
        if (isAuto())
        {
            cout << "�����Զ�����, ��ȫ�������!" << endl;
        }
        else
        {
            cout << "�����Զ�����, ���Զ�������!" << endl;
        }
        weapon();
        appearance();
        fightAbility();
        selfHealing();
    }
};

// ����������1 - ��ƽ������
class Pacifist : public AbstractRobot
{
public:
    // ����
    void weapon() override
    {
        cout << "���Է��������..." << endl;
    }
    // ���
    void appearance() override
    {
        cout << "�ⲿ�Ͱ������ס���һ��, �����Ӵ�ӵ�гʰ�Բ�εĶ��䣬�ڲ��ƺ�������" << endl;
    }
    // ս������
    void fightAbility() override
    {
        cout << "��ʵ����, ����ͨ���ֲ������첿�������伤��, �����ڻ�����!!!" << endl;
    }
    // ����
    string getName() override
    {
        return "��ƽ������";
    }
};

// ����������2 - ����ʹ
class Angel : public AbstractRobot
{
public:
    // ����
    void weapon() override
    {
        cout << "���Է������伤��, ӥ�����εĳ���ʹЯ����һ�Ѿ޽�, ����ն��һ��!!!" << endl;
    }
    // ���
    void appearance() override
    {
        cout << "��ۺ����亣Сʱ�������һ��, ����ӵ��һ�Ժͽ�һ���ĳ��!!!" << endl;
    }
    // ս������
    void fightAbility() override
    {
        cout << "�������Է������伤��, ��ӵ�����亣������, ţ��plus, �޵���!!!!" << endl;
    }
    // ����
    string getName() override
    {
        return "����ʹ";
    }
    // ��������
    void selfHealing() override
    {
        cout << "�ǳ���ʵ����, ����ӵ�зǳ�ǿ����������, ������!!!" << endl;
    }
    bool canFlying() override
    {
        return true;
    }
};

#if 0
int main()
{
    AbstractRobot* robot = new Pacifist;
    robot->getProperty();
    delete robot;
    cout << "================" << endl;
    robot = new Angel;
    robot->getProperty();
    delete robot;
    return 0;
}
#endif