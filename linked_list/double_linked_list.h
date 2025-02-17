#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "node.h"
#include "value.h"
#include "linked_list_abstraction.h"

class DoubleLinkedList : public BaseLinkedList
{
public:
    void push_back(IElement* value) override
    {
        Node* new_node = new Node(value);
        if (is_head_null()) {
            set_head_and_tail_both(new_node);
        }
        else {
            new_node->set_prev(get_tail());
            get_tail()->set_next(new_node);
            set_tail(new_node);
        }
        increment_size();
    }

    void push_front(IElement* value) override
    {
        Node* new_node = new Node(value);
        if (is_head_null()) {
            set_head_and_tail_both(new_node);
        }
        else {
            new_node->set_next(get_head());
            get_head()->set_prev(new_node);
            set_head(new_node);
        }
        increment_size();
    }

    void pop_back() override
    {
        if (is_head_null()) return;
        if (head_equals_tail()) {
            delete_head();
            set_head_and_tail_null();
        }
        else {
            INode* new_tail = get_tail()->get_prev();
            delete_tail();
            set_tail(new_tail);
            new_tail->set_next(nullptr);
        }
        decrement_size();
    }

    void pop_front() override
    {
        if (is_head_null()) return;
        if (head_equals_tail()) {
            delete_head();
            set_head_and_tail_null();
        }
        else {
            INode* new_head = get_head()->get_next();
            new_head->set_prev(nullptr);
            delete_head();
            set_head(new_head);
        }
        decrement_size();
    }

    void insert(size_t index, IElement* value) override
    {
        if (index > size_) return;
        if (index == 0) {
            push_front(value);
            return;
        }
        else if (index == size_) {
            push_back(value);
            return;
        }

        INode* current = get_head();
        for (size_t i = 0; i < index; ++i) {
            current = current->get_next();
        }

        Node* new_node = new Node(value);
        new_node->set_prev(current->get_prev());
        new_node->set_next(current);
        current->get_prev()->set_next(new_node);
        current->set_prev(new_node);
        increment_size();
    }

    void remove(size_t index) override
    {
        if (index >= size_) return;
        if (index == 0) {
            pop_front();
            return;
        }
        else if (index == size_ - 1) {
            pop_back();
            return;
        }

        INode* target = get_head();
        for (size_t i = 0; i < index; ++i) {
            target = target->get_next();
        }

        target->get_prev()->set_next(target->get_next());
        target->get_next()->set_prev(target->get_prev());
        delete target;
        decrement_size();
    }

    void remove(IElement* value, bool (*equal)(IElement first, IElement second)) override
    {
        INode* node_value = new Node(value);
        INode* node = get_head();
        int index = 0;
        while (node != nullptr) {
            if (equal(node_value->get_value(), node->get_value())) {
                remove(index);
                delete node_value; 
                return;
            }
            node = node->get_next();
            index++;
        }
        delete node_value; 
    }

    INode* return_head()
    {
        return this->get_head();
    }

    DoubleLinkedList() : BaseLinkedList() {}
    ~DoubleLinkedList() override
    {
        INode* current = get_head();
        while (current != nullptr) {
            INode* next = current->get_next();
            delete current;
            current = next;
        }
    }
};

#endif // DOUBLE_LINKED_LIST_H
