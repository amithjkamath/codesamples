//
// Created by Amith Kamath on 3/1/17.
//

#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <class ElemType>
class List
{
public:
    List(unsigned long numElements, ElemType defaultvalue = 0);
    List(const ElemType* array, unsigned long numElements);
    List<ElemType> operator=(const List<ElemType>&);

    unsigned long size(void) const;

    ElemType elementAt(unsigned long position) const;
    void replaceAt(unsigned long position, ElemType value);
    void addElementAt(unsigned long position, ElemType value);
    bool removeElementAt(unsigned long index);

    void print(unsigned long position);
    void print(void);

    List<ElemType>* subList(unsigned long start, unsigned long end);
    ElemType operator[](unsigned long indx) const;

    ~List(void);

private:
    unsigned long _length;
    Node<ElemType>* _root;

    void deleteList(void);
};

#endif //LIST_H
