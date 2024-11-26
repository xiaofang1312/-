#include <iostream>
using namespace std;

// ��Ʒ��ĸ��� - �����ħ��ʵ
class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile() {}
};

class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "������� -- ɽ������̬..." << endl;
    }
    void ability() override
    {
        cout << "���ֱ۱������ǵ���ʽ -- �����" << endl;
    }
};

class LionSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "������� -- ʨ������̬..." << endl;
    }
    void ability() override
    {
        cout << "��ݡ� ������֮��..." << endl;
    }
};

class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "������� -- ��������̬..." << endl;
    }
    void ability() override
    {
        cout << "��������֮�򽣹���..." << endl;
    }
};

// ���幤���� - ����
class AbstractFactory
{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() {}
};

// ����ɽ��Ķ�ħ��ʵ
class SheepFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile()
    {
        return new SheepSmile;
    }
    ~SheepFactory() 
    {
        cout << "SheepFactory ��������..." << endl;
    }
};

// ����ʨ�ӵĶ�ħ��ʵ
class LionFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile()
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        cout << "LionFactory ��������..." << endl;
    }
};

// ��������Ķ�ħ��ʵ
class BatFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile()
    {
        return new BatSmile;
    }
    ~BatFactory()
    {
        cout << "BatFactory ��������..." << endl;
    }
};

#if 0
int main()
{
    AbstractFactory* factory = new LionFactory;
    AbstractSmile* obj = factory->createSmile();
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;

    return 0;
}
#endif