#include <iostream>
#include <map>
#include <vector>
using namespace std;

// ��Ԫ��Ļ���
class FlyWeightBody
{
public:
    FlyWeightBody(string sprite) : m_sprite(sprite) {}
    virtual void move(int x, int y, int speed) = 0;
    virtual void draw(int x, int y) = 0;
    virtual ~FlyWeightBody() {}
protected:
    string m_sprite;
    string m_color;
};

// ��Ԫ������� - �ڵ�
class SharedBombBody : public FlyWeightBody
{
public:
    using FlyWeightBody::FlyWeightBody;
    void move(int x, int y, int speed)
    {
        cout << "ը����ÿСʱ" << speed << "�ٶȷɵ���("
            << x << ", " << y << ") ��λ��..." << endl;
    }
    void draw(int x, int y)
    {
        cout << "�� (" << x << ", " << y << ") ��λ���ػ�ը������..." << endl;
    }
};

// ��Ԫ������� - �ʵ�
class UniqueBombBody : public FlyWeightBody
{
public:
    using FlyWeightBody::FlyWeightBody;
    void move(int x, int y, int speed)
    {
        // �˴�ʡ�ԶԲ��� x, y, speed�Ĵ���
        cout << "�ʵ�����ָ��λ���ƶ�, ׼����ը���Ž���..." << endl;
    }
    void draw(int x, int y)
    {
        cout << "�� (" << x << ", " << y << ") ��λ���ػ�ʵ��˶��켣..." << endl;
    }
};

// �����ڵ�
class LaunchBomb
{
public:
    LaunchBomb(FlyWeightBody* body) : m_body(body) {}
    void setSpeed(int speed)
    {
        m_speed = speed;
    }
    void move(int x, int y)
    {
        m_x = x;
        m_y = y;
        m_body->move(m_x, m_y, m_speed);
        draw();
    }
    void draw()
    {
        m_body->draw(m_x, m_y);
    }
private:
    FlyWeightBody* m_body;
    int m_speed = 100;
    int m_x = 0;
    int m_y = 0;
};

// ��Ԫ������
class BombBodyFactory
{
public:
    // ��������ը�����ͺ�
    FlyWeightBody* getSharedData(string name)
    {
        FlyWeightBody* data = nullptr;
        // ��������
        for (auto item : m_bodyMap)
        {
            if (item.first == name)
            {
                // �ҵ���
                data = item.second;
                cout << "���ڸ��� <" << name << ">..." << endl;
                break;
            }
        }
        if (data == nullptr)
        {
            data = new SharedBombBody(name);
            cout << "���ڴ��� <" << name << ">..." << endl;
            m_bodyMap.insert(make_pair(name, data));
        }
        return data;
    }

    ~BombBodyFactory()
    {
        for (auto item : m_bodyMap)
        {
            delete item.second;
        }
    }
private:
    map<string, FlyWeightBody*> m_bodyMap;
};

#if 0
int main()
{
    BombBodyFactory* factory = new BombBodyFactory;
    vector<LaunchBomb*> bombList;
    vector<string> namelist = { "����-1", "����-1", "����-2", "����-2", "����-2", "����-3", "����-3", "����-3" };
    for (auto name : namelist)
    {
        int x = 0; int y = 0;
        LaunchBomb* launch = new LaunchBomb(factory->getSharedData(name));
        for (int i = 0; i < 3; ++i)
        {
            x += rand() % 100;
            y += rand() % 50;
            launch->move(x, y);
        }
        bombList.push_back(launch);
    }
    // �ʵ�
    UniqueBombBody* unique = new UniqueBombBody("��ʵ�");
    LaunchBomb* bomb = new LaunchBomb(unique);
    int x = 0; int y = 0;
    for (int i = 0; i < 3; ++i)
    {
        x += rand() % 100;
        y += rand() % 50;
        bomb->move(x, y);
    }

    for (auto bomb : bombList)
    {
        delete bomb;
    }
    delete factory;
    delete bomb;
    delete unique;
    return 0;
}
#endif