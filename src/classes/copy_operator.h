
#ifndef COPY_OPERATOR_H_
#define COPY_OPERATOR_H_

#include <iostream>
#include <string.h>

/*
My_Array first;           // initialization by default constructor
My_Array second(first);   // initialization by copy constructor
My_Array third = first;   // Also initialization by copy constructor
second = third;           // assignment by copy assignment operator
*/

class TestClass{

public:

	std::string TestClassName;

	TestClass(){
		std::cout << "TestClass constructor" << std::endl;
	}

	TestClass(std::string s){
		std::cout << "Integer TestClass constructor" << std::endl;
		TestClassName = s;
	}

	//Assignment operator
	TestClass& operator=(const TestClass& Other){
		std::cout << "Assignment Operator" << std::endl;
		TestClassName = Other.TestClassName;
		return *this; //because "this" is a pointer we need to dereference it
	}

    //Copy constructor
	TestClass(const TestClass& rhs) : TestClassName(rhs.TestClassName){
		std::cout << "Copy constructor" << std::endl;
	}

};

class ClassPointer {

public:

    int * n;

    ClassPointer(int val) {

        n = new int(val);

    }

    ClassPointer & operator=(const ClassPointer & tco) {

        if (this == &tco) // object assigned to itself, we'll fail without this return on delete step
            return *this;

        delete n; //because our object may already have allocated n, we need to free memory to prevent leakage

        n = new int(*(tco.n));

        return *this;

    }

};

class ClassPointerNoAssignmentOperator {

public:

    ClassPointerNoAssignmentOperator(int val) {

        n = new int(val);

    }

    int * n;

};

void TestCopyOperator();

#endif /* COPY_OPERATOR_H_ */




//http://stackoverflow.com/questions/11706040/whats-the-difference-between-assignment-operator-and-copy-constructor

/*
If a new object has to be created before the copying can occur, the copy constructor is used.
If a new object does not have to be created before the copying can occur, the assignment operator is used.
*/

//http://stackoverflow.com/questions/4172722/what-is-the-rule-of-three

/*
If you need to explicitly declare either the destructor, copy constructor or copy assignment operator yourself,
you probably need to explicitly declare all three of them.

Most of the time, you do not need to manage a resource yourself, because an existing class such as std::string already does it for you.
Just compare the simple code using a std::string member to the convoluted and error-prone alternative using a char* and you should be convinced.
As long as you stay away from raw pointer members, the rule of three is unlikely to concern your own code.
*/



