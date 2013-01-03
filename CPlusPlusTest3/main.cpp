//
//  main.cpp
//  CPlusPlusTest3
//
//  Created by Vivek Seth on 12/17/12.
//  Copyright (c) 2012 Vivek Seth. All rights reserved.
//

#include "common.h"
#include "Person.h"
#include "Node.h"
#include "TSP_Iterative.h"
#include "TSPAlgorithm.h"

using namespace std;

Person* createPerson() {
    Person * a = new Person (77, "old man");
    return (a);
}

int main()
{
    
    Person * a = createPerson();
    release(a);
    Person * p = new Person (5, "kid");
    cout << p->toString() << endl;
    release(p);
    
    string string1 = "string";
    string string2 = "string";
    
    string * b = new string("");
    string * c = &string2;
    
    release(b);
    
    if ((b)==(c)) {
        cout << "both null now!" << endl;
    }
    
    std::cout << "";
    
    Person * person1 = new Person (0, "name0");
    Node<Person> * node1 = new Node<Person>(person1, 0);
    
    Person * person2 = new Person (1, "name1");
    Node<Person> * node2 = new Node<Person>(person2, 0);
    
    Person * person3 = new Person (2, "name2");
    Node<Person> * node3 = new Node<Person>(person3, 0);
    
    Person * person4 = new Person (3, "name3");
    Node<Person> * node4 = new Node<Person>(person4, 0);
    
    Person * person5 = new Person (4, "name4");
    Node<Person> * node5 = new Node<Person>(person5, 0);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = 0;
    
    node1->printAll();
    
    release(node1);
    //cout << node5->data->toString() << endl;
    
}

