#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
 
// ����ڵ�ĳ�����
class AbstractTeam
{
public:
    AbstractTeam(string name) : m_name(name) {}
    string getName()
    {
        return m_name;
    }
    void setParent(AbstractTeam* team)
    {
        m_parent = team;
    }
    AbstractTeam* getParent()
    {
        return m_parent;
    }
    // �麯��
    virtual bool hasChild()
    {
        return false;
    }
    virtual void addChild(AbstractTeam* node) {}
    virtual void removeChild(AbstractTeam* node) {}
    virtual void fight() = 0;
    virtual void display() = 0;
    virtual ~AbstractTeam() {}
protected:
    string m_name;
    AbstractTeam* m_parent = nullptr;
};

// Ҷ�ӽڵ���
class LeafTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight()
    {
        cout << m_parent->getName() + m_name + "��ں��ӵĴ�Ա���н������ⲫս..." << endl;
    }
    void display()
    {
        cout << "����" << m_parent->getName() << "������" << m_name << endl;
    }
    ~LeafTeam()
    {
        cout << "����" << m_parent->getName() << "������" << m_name
            << ", ս���Ѿ�����, �ݰ�..." << endl;
    }
};

// �����߽ڵ���
class ManagerTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight()
    {
        cout << m_name + "�ͺں��ӵĶ�ħ��ʵ������ս��!!!" << endl;
    }
    bool hasChild()
    {
        return true;
    }
    void addChild(AbstractTeam* node) 
    {
        node->setParent(this);
        m_children.push_back(node);
    }
    void removeChild(AbstractTeam* node) 
    {
        node->setParent(nullptr);
        m_children.remove(node);
    }

    void display()
    {
        string info;
        for (const auto& item : m_children)
        {
            if (item == m_children.back())
            {
                info += item->getName();
            }
            else
            {
                info += item->getName() + ", ";
            }
        }
        cout << m_name << "�Ĵ����ǡ�" << info << "��" << endl;
    }
    list<AbstractTeam*> getChildren()
    {
        return m_children;
    }
    ~ManagerTeam()
    {
        cout << "���ǡ� " << m_name << "��ս������, �ݰ�..." << endl;
    }
private:
    list<AbstractTeam*> m_children;
};

void gameover(AbstractTeam* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root && root->hasChild())
    {
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root);
        list<AbstractTeam*> children = team->getChildren();
        for (const auto& item : children)
        {
            gameover(item);
        }
    }
    delete root;
}
void fighting()
{
    // ���ڵ�
    ManagerTeam* root = new ManagerTeam("��ñ������");
    vector<string> nameList = {
    "����������", "���о��ֲ�", "�˱�ˮ��", "����ŷ������",
    "������������", "�ޱ�������", "Լ�������Ǵ���"
    };
    for (int i = 0; i < nameList.size(); ++i)
    {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->addChild(child);
        if (i == nameList.size() - 1)
        {
            for (int j = 0; j < 9; ++j)
            {
                LeafTeam* leaf = new LeafTeam("��" + to_string(j + 1) + "����");
                child->addChild(leaf);
                leaf->fight();
                leaf->display();
            }
        }
        child->fight();
        child->display();
    }
    root->fight();
    root->display();
    cout << "=======================" << endl;
    gameover(root);
}

#if 0
int main()
{
    fighting();
    return 0;
}
#endif