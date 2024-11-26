#pragma once

class SanJi;
// ״̬��Ļ���
class AbstractState
{
public:
    virtual void working(SanJi* sanji) = 0;
    virtual ~AbstractState() {}
};

// ����״̬
class ForenoonState : public AbstractState
{
public:
    void working(SanJi* sanji) override;
};

// ����״̬
class NoonState : public AbstractState
{
public:
    void working(SanJi* sanji) override;
};

//����״̬
class AfternoonState : public AbstractState
{
public:
    void working(SanJi* sanji) override;
};

// ����״̬
class EveningState : public AbstractState
{
public:
    void working(SanJi* sanji) override;
};