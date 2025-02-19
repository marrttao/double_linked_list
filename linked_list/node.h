#ifndef NODE_H
#define NODE_H

#include "node_abstraction.h"

class Node : public INode
{
private:
    IElement* value_ = nullptr;
    INode* next_ = nullptr;
    INode* prev_ = nullptr;

public:
    void set_next(INode* node) override
    {
        this->next_ = node;
    }
    INode* get_next() override
    {
        return this->next_;
    }
    void set_prev(INode* node) override
    {
        this->prev_ = node;
    }
    INode* get_prev() override
    {
        return this->prev_;
    }
    IElement& get_value() override
    {
        return *this->value_;
    }
    Node() = default;
    Node(IElement* value) : value_(value) {}
    ~Node() override
    {
        delete value_;
    }
};

#endif // NODE_H
