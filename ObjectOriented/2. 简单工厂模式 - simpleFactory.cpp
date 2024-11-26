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

// ���幤����
enum class Type:char{Sheep, Lion, Bat};
class SmileFactory
{
public:
    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;
        switch (type)
        {
        case Type::Sheep:
            ptr = new SheepSmile;
            break;
        case Type::Lion:
            ptr = new LionSmile;
            break;
        case Type::Bat:
            ptr = new BatSmile;
            break;
        default:
            break;
        }
        return ptr;
    }
};

#if 0
int main()
{
    SmileFactory* factory = new SmileFactory;
    AbstractSmile* obj = factory->createSmile(Type::Lion);
    obj->transform();
    obj->ability();

    delete obj;
    delete factory;

    return 0;
}
#endif