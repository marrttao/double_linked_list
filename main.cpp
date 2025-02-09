#include <iostream>
#include "linked_list/single_linked_list.h"
using namespace std;

// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON
// DOUBLE LINKED LIST WILL BE SOON

class Test
{
public:
    int number;
    Test(int number) : number(number) {}
};

ostream& operator<<(ostream& os, Test* test)
{
    os << test->number;
    return os;
}


class LinkedListProvider
{
public:
    static void print(SingleLinkedList *list)
    {
        //get node->get_value() as Value<int> and call get_value() on it
        INode* temp = list->return_head();
        while (temp != nullptr)
        {
            Value<Test*>* val = dynamic_cast<Value<Test*>*>(&temp->get_value());
            cout << *val << " ";
            temp = temp->get_next();
        }
    }
};

int main()
{
    SingleLinkedList * list = new SingleLinkedList();
    list->push_back(new Value<Test*>(new Test(1)));
    list->push_back(new Value<Test*>(new Test(2)));
    list->push_back(new Value<Test*>(new Test(3)));
    list->push_back(new Value<Test*>(new Test(4)));

    LinkedListProvider::print(list);

    delete list;
    
    return 0;
}
