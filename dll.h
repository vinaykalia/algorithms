//
//  dllNode.h
//  trees
//
//  Created by Vinay Kalia on 9/5/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_dllNode_h
#define trees_dllNode_h

#include <stdio.h>
#include <iostream>
#include "testable.h"

template <typename T>
class dllNode {
    T mData;
    dllNode<T>* mNext;
    dllNode<T>* mPrev;
public:
    dllNode(T data):mData(data), mNext(nullptr), mPrev(nullptr){}
    template <typename U> friend class dll;
};

template <typename T>
class dll : public testable {
    dllNode<T> *mHead;
public:
    dll();
    dll(T data);
    ~dll();
    void addTail(T data);
    int test();
};

template <typename T>
dll<T>::dll() {
    mHead = nullptr;
}

template <typename T>
dll<T>::dll(T data) {
    mHead = new dllNode<T>(data);
}

template <typename T>
dll<T>::~dll() {
    dllNode<T> *iter = mHead;
    dllNode<T> *tmp;
    while (iter) {
        tmp = iter->mNext;
        delete iter;
        iter = tmp;
    }
    mHead = nullptr;
}

template <typename T>
void dll<T>::addTail(T data) {
    dllNode<T> *iter = mHead;
    while (iter->mNext) {
        iter = iter->mNext;
    }
    dllNode<T> *node = new dllNode<T>(data);
    iter->mNext = node;
    node->mPrev = iter;
}

template <typename T>
int dll<T>::test() {
    cout<<"Testing Double Linked List...\n";
    cout<<"Testing Double Linked List done.\n";
    return 0;
}

#endif
