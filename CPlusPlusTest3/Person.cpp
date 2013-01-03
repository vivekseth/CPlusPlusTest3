//
//  Animal.cpp
//  CPlusPlusTest3
//
//  Created by Vivek Seth on 12/17/12.
//  Copyright (c) 2012 Vivek Seth. All rights reserved.
//

#include "Person.h"

Person::Person(int age, string name) {
    this->age = age;
    this->name = name;
};

void Person::incrementAge(int increase) {
    this->age+= increase;
}

string Person::toString() {
    string result;
    stringstream sstm;
    sstm << "name: " << name << ", age: " << age;
    result = sstm.str();
    return result;
}

