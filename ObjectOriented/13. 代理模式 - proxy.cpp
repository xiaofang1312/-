#include <iostream>
using namespace std;

// ������Ļ���
class Communication
{
public:
    virtual void communicate() = 0;
    virtual ~Communication() {}
};

// ���� - ��������
class Speaker : public Communication
{
public:
    void communicate()
    {
        cout << "��ʼ˵��..." << endl;
        cout << "ͨ��ʱ������һЩ�еı���仯..." << endl;
    }
};

// ������
class DenDenMuShi : public Communication
{
public:
    DenDenMuShi()
    {
        m_isStart = true;
        m_speaker = new Speaker;
    }

    bool isStart()
    {
        return m_isStart;
    }

    void setStart(bool flag)
    {
        m_isStart = flag;
    }
    void communicate() override
    {
        if (m_isStart)
        {
            cout << "�绰�濪ʼʵʱģ��ͨ���ߵ����Ժͱ���..." << endl;
            m_speaker->communicate();
        }
    }
    ~DenDenMuShi()
    {
        if (m_speaker != nullptr)
        {
            delete m_speaker;
        }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

#if 0
int main()
{
    // ֱ�ӽ���
    Communication* speaker = new Speaker;
    speaker->communicate();
    delete speaker;
    cout << "===================" << endl;
    // ͨ���绰�潻��
    speaker = new DenDenMuShi;
    speaker->communicate();
    delete speaker;

    return 0;
}
#endif