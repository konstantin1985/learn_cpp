/*
 * copy_constructor.h
 *
 *  Created on: Feb 12, 2016
 *      Author: konstantin
 */

#ifndef COPY_CONSTRUCTOR_H_
#define COPY_CONSTRUCTOR_H_

#include <iostream>

class A {

public:

    int v;

    A() {
        std::cout << "A()" << std::endl;
        v = 0;
    }

    A(const A &) {
        std::cout << "A(const A &)" << std::endl;
        v = 0;
    }

};

class B {

public:

    int *n;
    int v;

};

class D {

public:

    int *n;

    D(int val) {
        n = new int(val);
    }

    ~D() {
        delete n;
    }
};

void TestCopyConstructor();



#endif /* COPY_CONSTRUCTOR_H_ */
