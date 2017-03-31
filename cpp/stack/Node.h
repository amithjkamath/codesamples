//
// Created by Amith Kamath on 3/1/17.
//

#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:

    Node() {_value = 0; _next = 0;};
    T getValue(void) {return _value; };
    Node* getNext(void) {return _next; };

    void setValue(T value) { _value = value; };
    void setNext(Node* next) { _next = next; };

    void print(void);
private:
    T _value;
    Node* _next;
};


#endif //NODE_H
