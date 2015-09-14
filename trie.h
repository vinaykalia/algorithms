//
//  trie.h
//  trees
//
//  Created by Vinay Kalia on 9/5/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_trie_h
#define trees_trie_h

#include <stdio.h>
#include <iostream>
#include "testable.h"

using namespace std;

template <typename T>
class trieNode {
    template <typename U> friend class trie;
private:
    T mData;
    trieNode<T> *mParent;
    trieNode<T> *mNext;
    trieNode<T> *mChildren;
public:
    trieNode(T data, trieNode<T> *parent, trieNode<T> *next, trieNode<T> *children);
    ~trieNode();
    trieNode<T>* insertChild(T data);
};

template <typename T>
class trie : public testable {
    trieNode<T> *mRoot;
    void traverse(trieNode<T> *root);
    void destroy(trieNode<T> *node);
public:
    trie();
    ~trie();
    void insert(T arr[], size_t length);
    void traverse();
    int test();
};

template <typename T>
trieNode<T>::trieNode(T data, trieNode<T> *parent, trieNode<T> *next, trieNode<T> *children):mData(data), mParent(parent),mNext(nullptr),mChildren(nullptr) {};

template <typename T>
trieNode<T>::~trieNode() {
    mParent = nullptr;
    mNext = nullptr;
    mChildren = nullptr;
};

template <typename T>
trieNode<T>* trieNode<T>::insertChild(T data) {
    trieNode<T> *iter = mChildren;
    trieNode<T> *prev = nullptr;
    if (!iter) {
        trieNode<T> *node = new trieNode<T>(data, this, nullptr, nullptr);
        mChildren = node;
        return node;
    }
    while (iter) {
        if (iter->mData == data) {
            return iter;
        }
        prev = iter;
        iter = iter->mNext;
    }
    trieNode<T> *node = new trieNode<T>(data, this, nullptr, nullptr);
    prev->mNext = node;
    return node;
}

template <typename T>
trie<T>::trie() {
    mRoot = new trieNode<T>('*', nullptr, nullptr, nullptr);
}

template <typename T>
void trie<T>::destroy(trieNode<T> *node) {
    if (!node)
        return;
    if (!node->mChildren) {
        destroy(node->mNext);
    } else {
        destroy(node->mChildren);
    }
    delete node;
}

template <typename T>
trie<T>::~trie() {
    trieNode<T> *iter = mRoot;
    destroy(iter);
}

template <typename T>
void trie<T>::insert(T data[], size_t length) {
    trieNode<T> *iter = mRoot;
    for (size_t i = 0; i < length; i++) {
        iter = iter->insertChild(data[i]);
    }
}

template <typename T>
void trie<T>::traverse(trieNode<T> *root) {
    if (!root)
        return;
    cout<<root->mData<<", ";
    traverse(root->mChildren);
    cout<<endl;
    traverse(root->mNext);
}

template <typename T>
void trie<T>::traverse() {
    traverse(mRoot);
}

template <typename T>
int trie<T>::test() {
    cout<<"Testing Trie...\n";
    insert("beauty", strlen("beauty"));
    insert("beautification", strlen("beautification"));
    insert("beast", strlen("beast"));
    traverse();
    cout<<"Testing Trie done\n";
    return 0;
}

#endif