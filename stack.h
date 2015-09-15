//
//  stack.h
//
//  Created by Vinay Kalia on 9/15/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef __datastructures__stack__
#define __datastructures__stack__

#include <stdio.h>
#include <iostream>
#include "testable.h"
#include "sll.h"

using namespace std;

template <typename T>
class stack : public testable {
    sll<T> *mList;
public:
    stack();
    ~stack();
    int push(T data);
    T pop();
    bool isEmpty();
    int test();
};

template <typename T>
stack<T>::stack() {
    mList = nullptr;
}

template <typename T>
stack<T>::~stack() {
    delete mList;
    mList = nullptr;
}

template <typename T>
int stack<T>::push(T data) {
    if (!mList)
        mList = new sll<T>(data);
    else
        mList->addHead(data);
    return 0;
}

template <typename T>
T stack<T>::pop() {
    return mList->getHead();
}

template <typename T>
bool stack<T>::isEmpty() {
    return mList->isEmpty();
}

template <typename T>
int stack<T>::test() {
    cout<<"Testing stack...\n";
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    cout<<"Stack Input: 1, 2, 3, 4, 5\n";
    cout<<"Stack output: "<<pop()<<", "<<pop()<<", "<<pop()<<", "<<pop()<<", "<<pop()<<endl;
    cout<<"Testing stack done\n";
    return 0;
}

#endif