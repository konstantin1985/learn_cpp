
#ifndef COPY_OPERATOR_H_
#define COPY_OPERATOR_H_

#include <iostream>
#include <string.h>

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


	TestClass& operator=(const TestClass& Other){
		std::cout << "Assignment Operator" << std::endl;
		TestClassName = Other.TestClassName;
		return *this; //because "this" is a pointer we need to dereference it
	}

};

void TestCopyOperator();


#endif /* COPY_OPERATOR_H_ */
