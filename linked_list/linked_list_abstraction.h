#ifndef SINGLE_LINKED_LIST_ABSTRACTION_H
#define SINGLE_LINKED_LIST_ABSTRACTION_H

#include "node_abstraction.h"

class ILinkedList
{
protected:
    INode *head_ = nullptr;
    INode *tail_ = nullptr;
    size_t size_ = 0;
public:
    ILinkedList() = default;
    virtual ~ILinkedList() = default;
    virtual void push_back(IElement *value) = 0;
    virtual void push_front(IElement *value) = 0;
    virtual void pop_back() = 0;
    virtual void pop_front() = 0;
    virtual void insert(size_t index, IElement *value) = 0;
    virtual void remove(size_t index) = 0;
    virtual void remove(IElement *value, bool (*equil)(IElement first, IElement second)) = 0;
};

class BaseLinkedList : public ILinkedList
{
public:
    BaseLinkedList() = default;
    virtual ~BaseLinkedList() = default;
    
    
    virtual bool is_head_null() { return head_ == nullptr; }
    virtual bool is_tail_null() { return tail_ == nullptr; }
    virtual bool head_equals_tail() { return head_ == tail_; }

    virtual size_t size() { return size_; }
    virtual void set_head(INode *head) { head_ = head; }
    virtual void set_head_next(INode *node)
    {
        node->set_next(head_);
        head_ = node;
    }
    virtual void set_tail(INode *tail) { tail_ = tail; }
    virtual void set_tail_next(INode *node)
    {
        tail_->set_next(node);
        tail_ = node;
    }
    virtual INode *get_head() { return head_; }
    virtual INode *get_tail() { return tail_; }
    
    virtual void delete_head() { delete head_; }
    virtual void delete_tail() { delete tail_; }
    
    virtual void set_head_null() { head_ = nullptr; }
    virtual void set_tail_null() { tail_ = nullptr; }
    virtual void set_head_and_tail_null() { head_ = nullptr; tail_ = nullptr; }
    virtual void set_head_and_tail_both(INode *node) { head_ = node; tail_ = node; }
    
    virtual void increment_size() { size_++; }
    virtual void decrement_size() { size_--; }
    
};

#endif // SINGLE_LINKED_LIST_ABSTRACTION_H
