#pragma once

class MaleMember;
class FemaleMember;
// ��Ϊ��Ӧ�Ļ���
class AbstractAction
{
public:
    // �����˷���
    virtual void maleDoing(MaleMember* male) = 0;
    // ��Ů�˷���
    virtual void femaleDoing(FemaleMember* female) = 0;
    virtual ~AbstractAction() {}
};

class Anger : public AbstractAction
{
public:
    // �����˷���
    void maleDoing(MaleMember* male) override;
    // ��Ů�˷���
    void femaleDoing(FemaleMember* female) override;
    void fight();
    void warning();
};

class Horror : public AbstractAction
{
public:
    // �����˷���
    void maleDoing(MaleMember* male) override;
    // ��Ů�˷���
    void femaleDoing(FemaleMember* female) override;
    void help();
    void thinking();
};