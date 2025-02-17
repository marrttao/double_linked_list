#ifndef NODE_ABSTRACTION_H
#define NODE_ABSTRACTION_H

class IElement
{
public:
    virtual ~IElement() {}
};

class INode
{
public:
    virtual ~INode() = default;
    virtual void set_next(INode* node) = 0;
    virtual INode* get_next() = 0;
    virtual void set_prev(INode* node) = 0;
    virtual INode* get_prev() = 0;
    virtual IElement& get_value() = 0;
};

#endif // NODE_ABSTRACTION_H