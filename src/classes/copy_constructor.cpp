/*
 * copy_constructor.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: konstantin
 */

#include "copy_constructor.h"

void PassByValue(A a) {

    a.v = 5;

}

void PassByReference(A& a) {

    a.v = 5;

}

A ReturnByValue(A& a) {

    a.v = 5;
    return a;
}

A ReturnByValue() {

    A a;
    a.v = 123;

    // Copy constructor is here, but compiler may optimi it out
    return a;
}

void InvokeCopyConstructor() {

    using namespace std;

    cout << "InvokeCopyConstructor()" << endl;

    //Situation where copy constructor is invoked

    A a1;               // A()
    A a2(a1);           // A(const A &)
    A a3 = a1;          // A(const A &)
    A a4 = A(a1);       // A(const A &)
    A * a5 = new A(a1); // A(const A &)


    //If copy constructor is done incorrectly, strange behavior may happen
    cout << "-------" << endl;

    A aa1;
    aa1.v = 777;
    cout << "aa1.v: " << aa1.v << endl;  // 777
    A aa2(aa1);
    std::cout << "aa2.v: " << aa2.v << std::endl;  // 0


    //Copy constructors are used when passing to/from functions by value
    /*
    By the way, the fact that passing an object by value involves invoking a copy construc-
    tor is a good reason for passing by reference instead.That saves the time of invoking the
    constructor and the space for storing the new object.
    */
    cout << "-------" << endl;

    A aaa1;                                // A()
    PassByValue(aaa1);                     // A(const A &) - because we are passing by value
    PassByReference(aaa1);                 // nothing, we are passing by value
    A aaa2 = ReturnByValue(aaa1);          // A(const A &)
    A aaa3 = ReturnByValue();              // A()
    cout << aaa3.v << endl;                // 123

}

void DefaultCopyConstructor() {

    using namespace std;

    cout << "DefaultCopyConstructor()" << endl;

    B b1;
    b1.v = 5;
    int i = 2000;
    b1.n = &i;

    cout << "b1.v: " << b1.v << endl;                    // 5
    cout << "*(b1.n): " << *(b1.n) << endl;              // 2000
    B b2(b1);
    cout << "b2.v: " << b2.v << endl;                    // 5
    cout << "*(b2.n): " << *(b2.n) << endl;              // 2000 (points to the same memory location)

    *(b1.n) = 3000; //Change value of a pointed variable in b1
    cout << "*(b2.n): " << *(b2.n) << endl;              // 3000 changes as well, because default constructor isn't a deep copy

    //We can delete only pointers, for non-pointers delete doesn't work

}

void DefaultCopyConstructorPointer() {

    using namespace std;

    cout << "DefaultCopyConstructorPointer()" << endl;

    D* d1 = new D(555);
    cout << "d1->n: " << d1->n << endl;                    // 0x9e97118
    cout << "*(d1->n): " << *(d1->n) << endl;              // 555

    D* d2 = new D(*d1);
    cout << "d2->n: " << d2->n << endl;                    // 0x9e97118 same address
    cout << "*(d2->n): " << *(d2->n) << endl;              // 555

    delete d1;
    D* d3 = new D(777); // to occupy freed memory and see garbage in d2 later on, note that we delete n in destructor

    cout << "d2->n: " << d2->n << endl;                    // 167989560 garbage
    cout << "*(d2->n): " << *(d2->n) << endl;              // 0xa035118

}

void TestCopyConstructor() {

    InvokeCopyConstructor();

    DefaultCopyConstructor();

    DefaultCopyConstructorPointer();
}

