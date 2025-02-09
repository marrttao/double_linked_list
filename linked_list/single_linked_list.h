#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include "node.h"
#include "value.h"
#include "linked_list_abstraction.h"

class SingleLinkedList : BaseLinkedList
{
public:
    void push_back(IElement *value) override
    {
        Node * new_node = new Node(value);
        is_head_null() ? set_head_and_tail_both(new_node) : set_tail_next(new_node);
        increment_size();
    }

    void push_front(IElement* value) override
    {
        Node * new_node = new Node(value);
        is_head_null() ? set_head_and_tail_both(new_node) : set_head_next(new_node);
        increment_size();
    }

    void pop_back() override
    {
        if (is_head_null()) return;
        if (head_equals_tail())
        {
            delete_head();
            set_head_and_tail_null();
        }
        else
        {
            INode * node = get_head();
            while (node->get_next() != get_tail()) {
                node = node->get_next();
            }
            delete_tail();
            set_tail(node);
            set_tail_next(nullptr);
        }
        decrement_size();  
    }

    void pop_front() override
    {
        if (is_head_null()) return;
        if (head_equals_tail())
        {
            delete_head();
            set_head_and_tail_null();
        }
        else
        {
            INode * node = get_head();
            set_head(node->get_next());
            delete node;
        }
        decrement_size();
    }

    void insert(size_t index, IElement *value) override
    {
        if (index < 0 || index > size_) return;
        if (index == 0) push_front(value);
        else if (index == size_) push_back(value);
        else {
            INode * node = get_head();
            for (size_t i = 0; i < index - 1; i++) {
                node = node->get_next();
            }
            INode *new_elem = new Node(value);
            new_elem->set_next(new_elem->get_next());
        }
        increment_size();
    }

    void remove(size_t index) override
    {
        if (index < 0 || index > size_) return;
        if (index == 0) pop_front();
        else if (index == size_ - 1) pop_back();
        else {
            INode * node = get_head();
            for (size_t i = 0; i < index - 1; i++) {
                node = node->get_next();
            }
            INode * delete_elem = node->get_next();
            node->set_next(node->get_next()->get_next());
            delete delete_elem;
           decrement_size();
        }
    }
    void remove(IElement* value, bool (*equil)(IElement first, IElement second)) override
    {
        INode * node_value = new Node(value);
        INode * node = get_head();
        int index = 0;
        while (node != nullptr) {
            if (equil(node_value->get_value(),
                node->get_value())) {
                remove(index);
                return;
            }
            node = node->get_next();
            index++;
        }
    }

    INode * return_head()
    {
        return this->get_head();
    }
    
    SingleLinkedList() : BaseLinkedList() {}
    SingleLinkedList(size_t size, Node* list_nodes)
    {
        this->size_ = size;
    }
    ~SingleLinkedList() override
    {
        delete head_;
        delete tail_;
    }
};


#endif // SINGLE_LINKED_LIST_H
