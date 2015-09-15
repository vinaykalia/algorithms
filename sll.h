//
//  sll.h
//  trees
//
//  Created by Vinay Kalia on 9/7/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_sll_h
#define trees_sll_h

#include <stdio.h>
#include <iostream>
#include "testable.h"

using namespace std;

template <typename T>
class sllNode {
    T mData;
    sllNode<T> *mNext;
public:
    sllNode(T data):mData(data),mNext(nullptr) {}
    template <typename U> friend class sll;
};

template <typename T>
class sll: public testable {
    sllNode<T> *mHead;
    sllNode<T>* reverse(sllNode<T> *head, sllNode<T> **newHead);
public:
    sll();
    sll(T data);
    ~sll();
    int addTail(T data);
    int addHead(T data);
    T getHead();
    bool isEmpty();
    void reverse();
    void print();
    int test();
};

template <typename T>
sll<T>::sll() {
    mHead = nullptr;
}

template <typename T>
sll<T>::sll(T data) {
    mHead = new sllNode<T>(data);
}

template <typename T>
sll<T>::~sll() {
    sllNode<T> *iter = mHead;
    sllNode<T> *tmp;
    while (iter) {
        tmp = iter->mNext;
        delete iter;
        iter = tmp;
    }
    mHead=nullptr;
}

template <typename T>
int sll<T>::addTail(T data) {
    if (!mHead) {
        mHead = new sllNode<T>(data);
        return 0;
    }
    sllNode<T> *iter = mHead;
    while (iter->mNext) {
        iter = iter->mNext;
    }
    iter->mNext = new sllNode<T>(data);
    return 0;
}

template <typename T>
sllNode<T>* sll<T>::reverse(sllNode<T> *head, sllNode<T> **newHead) {
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
void sll<T>::reverse() {
    sllNode<T> *newHead;
    reverse(mHead, &newHead);
    mHead = newHead;
}

template <typename T>
int sll<T>::addHead(T data) {
    sllNode<T> *node = new sllNode<T>(data);
    if (!mHead) {
        mHead = node;
    } else {
        node->mNext = mHead;
        mHead = node;
    }
    return 0;
}

template <typename T>
T sll<T>::getHead() {
    if (!mHead)
        return static_cast<T>(0);
    
    sllNode<T> *tmp = mHead;
    T data = tmp->mData;
    mHead = mHead->mNext;
    delete tmp;
    return data;
}

template <typename T>
bool sll<T>::isEmpty() {
    return mHead?false:true;
}

template <typename T>
void sll<T>::print() {
    sllNode<T> *iter = mHead;
    cout<<"List: ";
    while (iter) {
        cout<<iter->mData<<", ";
        iter = iter->mNext;
    }
    cout<<endl;
}

template <typename T>
int sll<T>::test() {
    cout<<"Testing singly linked list ...\n";
    sll<int> list;
    list.addTail(2);
    list.addTail(3);
    list.addTail(4);
    list.addTail(5);
    list.addTail(6);
    list.print();
    cout<<"Reversing the string\n";
    list.reverse();
    list.print();
    cout<<"Testing singly linked list done.\n";
    return 0;
}
#endif
