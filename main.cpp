//
//  main.cpp
//  trees
//
//  Created by Vinay Kalia on 9/4/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#include <iostream>
#include "binarySearchTree.h"
#include "trie.h"
#include "sll.h"
#include "dll.h"

int main(int argc, const char * argv[]) {
    class testable *t = new sll<int>();
    t->test();
    t = new dll<int>();
    t->test();
    t = new trie<char>();
    t->test();
    t = new binarySearchTree<int>();
    t->test();
}
