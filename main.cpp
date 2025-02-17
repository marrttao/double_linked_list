#include <iostream>
#include "linked_list/double_linked_list.h"
using namespace std;

class Test
{
public:
    int number;
    Test(int number) : number(number) {}
};

ostream& operator<<(ostream& os, const Test& test)
{
    os << test.number;
    return os;
}

class LinkedListProvider
{
public:
    static void print(DoubleLinkedList* list)
    {
        if (list == nullptr) return;

        INode* temp = list->return_head();
        while (temp != nullptr)
        {
            Value<Test*>* val = dynamic_cast<Value<Test*>*>(&temp->get_value());
            if (val != nullptr && val->get_value() != nullptr)
            {
                cout << *(val->get_value()) << " ";
            }
            temp = temp->get_next();
        }
        cout << endl;
    }
};

int main()
{
    DoubleLinkedList* list = new DoubleLinkedList();
    list->push_back(new Value<Test*>(new Test(1)));
    list->push_back(new Value<Test*>(new Test(2)));
    list->push_back(new Value<Test*>(new Test(3)));
    list->push_back(new Value<Test*>(new Test(4)));

    LinkedListProvider::print(list);

    INode* temp = list->return_head();
    while (temp != nullptr)
    {
        INode* next = temp->get_next();
        Value<Test*>* val = dynamic_cast<Value<Test*>*>(&temp->get_value());
        if (val != nullptr)
        {
            delete val->get_value();
            delete val;
        }
        delete temp;
        temp = next;
    }
    delete list;

    return 0;
}
