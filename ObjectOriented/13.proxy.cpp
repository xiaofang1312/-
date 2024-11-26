#include <iostream>
using namespace std;

// 抽象通信类
class Communication
{
public:
    virtual void communicate() = 0; // 通话
    virtual ~Communication() {}
};

// 讲话的人
class Speaker : public Communication
{
public:
    void communicate() override
    {
        cout << "开始说话..." << endl;
        cout << "通话时发生了一些列的表情变化..." << endl;
    }
};

// 电话虫
class DenDenMushi : public Communication
{
public:
    DenDenMushi(Communication* speaker)  //这里做了改动，和原代码不同
    {
        m_isStart = true;
        m_speaker = speaker;                  /////
    }

    bool isStart()
    {
        return m_isStart;
    }
    void communicate() override
    {
        if (isStart())
        {
            // 得到通话者语言和表情信息, 并加以模仿
            cout << "电话虫开始实时模仿通话者的语言和表情..." << endl;
            m_speaker->communicate();
       }
    }
private:
    bool m_isStart = false;
    Communication* m_speaker = nullptr;
};

int main()
{
    // 直接交流
    Communication* comm = new Speaker;
    comm->communicate();
    //delete comm;
    cout << "===================================" << endl;
    // 使用电话虫
    Communication* denden = new DenDenMushi(comm);
    denden->communicate();
    delete denden;
    delete comm;

    return 0;
}
