//
//  queue.h
//
//  Created by Vinay Kalia on 9/16/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_queue_h
#define trees_queue_h

#include <stdio.h>
#include <iostream>
#include "testable.h"
#include "sll.h"

using namespace std;

template <typename T>
class queue : public testable {
    sll<T> *mList;
    
public:
    queue();
    ~queue();
    void enqueue(T data);
    T dequeue();
    bool isEmpty();
    int test();
};

template <typename T>
queue<T>::queue() {
    mList = new sll<T>;
}

template <typename T>
queue<T>::~queue() {
    delete mList;
    mList = nullptr;
}

template <typename T>
void queue<T>::enqueue(T data) {
    mList->addTail(data);
}

template <typename T>
T queue<T>::dequeue() {
    return mList->getHead();
}

template <typename T>
bool queue<T>::isEmpty() {
    return mList->isEmpty();
}

template <typename T>
int queue<T>::test() {
    cout<<"Testing queue...\n";
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    cout<<"Queue input: 1, 2, 3, 4, 5, 6, 7\n";
    cout<<"Queue output: "<<dequeue()<<", "<<dequeue()<<", "<<dequeue()<<", "<<dequeue()<<", "<<dequeue()<<", "<<dequeue()<<", "<<dequeue()<<"\n";
    cout<<"Testing queue done.\n";
    return 0;
}
#endif
