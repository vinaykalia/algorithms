//
//  dllNode.h
//  trees
//
//  Created by Vinay Kalia on 9/5/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_dllNode_h
#define trees_dllNode_h

template <typename T>
class dllNode {
    T mData;
    dllNode<T> *mNext;
    dllNode<T> *mPrev;
    
public:
    dllNode(T data);
    ~dllNode();
    void addTail(dllNode<T> *node);
    void addHead(dllNode<T> *node);
    void insertAfter(dllNode<T> *node);
    void insertBefore(dllNode<T> *node);
    void deleteNode(dllNode<T> *node);
    dllNode<T> *getNext();
    dllNode<T> *getPrev();
};

template <typename T>
dllNode<T>::dllNode(T data) {
    mData(data);
    mNext(nullptr);
    mPrev(nullptr);
}

template <typename T>
dllNode<T>::~dllNode() {
    mData(0);
    mNext(nullptr);
    mPrev(nullptr);
}

template <typename T>
void dllNode<T>::addTail(dllNode<T> *node) {
    dllNode<T> *iter = this;
    while (iter->getNext()) {
        iter = getNext();
    }
    iter->mNext = node;
    node->mPrev = iter;
}

template <typename T>
void dllNode<T>::addHead(dllNode<T> *node) {
    if(!node)
        return;
    node->mNext = this;
    mPrev = node;
}

template <typename T>
void dllNode<T>::insertAfter (dllNode<T> *node) {
    dllNode<T> *tmp = mNext;
    mNext = node;
    node->mPrev = this;
}

template <typename T>
void dllNode<T>::insertBefore (dllNode<T> *node) {
    dllNode<T> *tmp = mPrev;
    tmp->mNext = node;
    mPrev = node;
}

template <typename T>
void dllNode<T>::deleteNode(dllNode<T> *node) {
    dllNode<T> *iter = this;
    dllNode<T> *prev = nullptr;
    while (iter) {
        if (iter == node) {
            if (iter->prev)
                iter->prev->mNext = iter->mNext;
            if (iter->mNext)
                iter->mNext->mPrev = iter->mPrev;
            break;
        }
        prev = iter;
        iter = iter->getNext();
    }
}

template <typename T>
dllNode<T> * dllNode<T>::getNext() {
    return mNext;
}

template <typename T>
dllNode<T> * dllNode<T>::getPrev() {
    return mPrev;
}
#endif
