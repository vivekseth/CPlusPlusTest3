//
//  Animal.h
//  CPlusPlusTest3
//
//  Created by Vivek Seth on 12/17/12.
//  Copyright (c) 2012 Vivek Seth. All rights reserved.
//

#ifndef __CPlusPlusTest3__Animal__
#define __CPlusPlusTest3__Animal__

#include "common.h"

using namespace std;

class Person  {
    
public:
    int age;
    string name;
    Person(int age, string name);
    void incrementAge(int increase);
    string toString();
    
private:
    
};


#endif /* defined(__CPlusPlusTest3__Animal__) */
