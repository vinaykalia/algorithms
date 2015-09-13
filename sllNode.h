//
//  sllNode.h
//  trees
//
//  Created by Vinay Kalia on 9/7/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_sllNode_h
#define trees_sllNode_h

#include <stdio.h>

template <typename T>
class sllNode {
    T mData;
    sllNode<T> *mNext;
    
public:
    sllNode(T data);
    ~sllNode();
    int addTail(T data);
    int deleteNode(sllNode<T> *node);
    sllNode<T> *reverse(sllNode<T> *head, sllNode<T> **newHead);
    void print();
};

template <typename T>
sllNode<T>::sllNode(T data) {
    mData = data;
    mNext = nullptr;
}

template <typename T>
sllNode<T>::~sllNode() {
    mData= 0;
    mNext = nullptr;
}

template <typename T>
int sllNode<T>::addTail(T data) {
    sllNode<T> *iter = this;
    while (iter->mNext) {
        iter = iter->mNext;
    }
    iter->mNext = new sllNode<T>(data);
    return 0;
}

template <typename T>
int sllNode<T>::deleteNode(sllNode<T> *node) {
    sllNode<T> *iter = this;
    sllNode<T> *prev = nullptr;
    while (iter) {
        if (iter == node) {
            prev->mNext = iter->mNext;
            delete iter;
            break;
        }
        prev = iter;
        iter = iter->getNext();
    }
    if (iter)
        return 0;
    return -1;
}

template <typename T>
sllNode<T> * sllNode<T>::reverse(sllNode<T> *head, sllNode<T> **newHead) {
    sllNode<T>* tail;
    if (!head)
        return nullptr;
    tail = reverse(head->mNext, newHead);
    if (tail)
        tail->mNext = head;
    else
        *newHead = head;
    head->mNext = nullptr;
    return head;
}

template <typename T>
void sllNode<T>::print() {
    sllNode<T> *iter = this;
    while (iter) {
        cout<<"Data = "<<iter->mData<<", ";
        iter = iter->mNext;
    }
    cout<<endl;
}
#endif
