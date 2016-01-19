/*
 * pointers.h
 *
 *  Created on: Jan 19, 2016
 *      Author: konstantin
 */

#ifndef POINTERS_H_
#define POINTERS_H_

#include <iostream>

class ClassForNullPointer{

	int a;

public:
	ClassForNullPointer(){std::cout << "ClassForNullPointer constructor" << std::endl; a = 5;}
	~ClassForNullPointer(){std::cout << "ClassForNullPointer destructor" << std::endl; a = 0;}

};

void NullPointerTest();



#endif /* POINTERS_H_ */
