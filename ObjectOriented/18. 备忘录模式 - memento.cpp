#include <iostream>
#include <map>
#include <vector>
using namespace std;

// ������
class History
{
public:
    History(string msg) : m_msg(msg) {}
    string getHistory()
    {
        return m_msg;
    }
private:
    string m_msg;
};

// �¼��������� - ���輦
class JiaoPenJi
{
public:
    // ���輦��������
    void setState(string msg)
    {
        m_msg = msg;
    }
    // ��¼��ʷ - ��װ����
    History* saveHistory()
    {
        return new History(m_msg);
    }
    // �õ���ʷ��Ϣ -> �����������ʷ��Ϣ, ����ļ��ض������м�¼�߶�����ɵ�
    void getStateFromHistory(History* history)
    {
        m_msg = history->getHistory();
    }
    string getState()
    {
        return m_msg;
    }
    // ����
    void beiDaddyDa()
    {
        cout << "���輦�����Ӻݺݵ���������, ���ڳ���������֮ǰ�����ϵ���Щ����: " << endl;
    }
private:
    string m_msg;
};

// �¼�(����)�ļ�¼��
class Recorder
{
public:
    void addHistory(int index, History* history)
    {
        m_history.insert(make_pair(index, history));
    }
    History* getHistory(int index)
    {
        if (m_history.find(index) != m_history.end())
        {
            return m_history[index];
        }
        return nullptr;
    }
private:
    map<int, History*> m_history;
};

#if 0
int main()
{
    vector<string> msg{
        "������͵���й�����ҽ!!!",
        "�����Ϸ������ֻ�ս��!!!",
        "�������Ͼ�����ɱ!!!!",
        "����������Ⱥ���͵��㵺���й�������!!!",
        "������731���ӵ�ϸ������������!!!",
        "�����϶��ҹ���Ů����������Ϊ!!!",
        "�����ϴ��й��Ӷ�������ڼƵ���Դ��������Ƶ�����!!!",
        "�Ҹɵ������¶���������, ���ǲ�����......"
    };
    JiaoPenJi* jiaopen = new JiaoPenJi;
    Recorder* recorder = new Recorder;
    for (int i = 0; i < msg.size(); ++i)
    {
        jiaopen->setState(msg.at(i));
        recorder->addHistory(i, jiaopen->saveHistory());
    }
    jiaopen->beiDaddyDa();
    for (int i = 0; i < msg.size(); ++i)
    {
        jiaopen->getStateFromHistory(recorder->getHistory(i));
        cout << "   --  " << jiaopen->getState() << endl;
    }
    return 0;
}
#endif