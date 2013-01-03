//
//  BSTNode.h
//  CPlusPlusTest3
//
//  Created by Vivek Seth on 12/17/12.
//  Copyright (c) 2012 Vivek Seth. All rights reserved.
//

#ifndef __CPlusPlusTest3__BSTNode__
#define __CPlusPlusTest3__BSTNode__

#include "common.h"

template <typename E> class Node {
    
public:
    Node<E> * next;
    E* data;
    Node<E>(E*data, Node<E> * next) {
        this->data = data;
        this->next = next;
    }
    ~Node<E>() {
        release(data);
        release(next);
    }
    void printAll() {
        Node<E> * curr = this;
        while (curr!=nullptr) {
            cout << curr->data->toString() <<endl;
            curr = curr->next;
        }
    }
};

#endif /* defined(__CPlusPlusTest3__BSTNode__) */
