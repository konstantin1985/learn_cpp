/*
 * pointers.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: konstantin
 */

#include "pointers.h"

//http://stackoverflow.com/questions/1931126/is-it-good-practice-to-null-a-pointer-after-deleting-it

/* Point #1

Setting a pointer to 0 (which is "null" in standard C++, the NULL define from C is somewhat different) avoids crashes on double deletes.

Foo* foo = 0; // Sets the pointer to 0 (C++ NULL)
delete foo; // Won't do anything
Whereas:

Foo* foo = new Foo();
delete foo; // Deletes the object
delete foo; // Undefined behavior
*/


/* Point #2

For example, if p were a member variable pointing to a resource who's lifetime was not exactly the same as the class containing p,
then setting p to NULL could be a useful way of indicating the presence or absence of the resource.
*/

void NullPointerTest(){

	std::cout << "NullPointerTest()" << std::endl;

	ClassForNullPointer * c = new ClassForNullPointer();
	delete c;
	//delete c;                                                //Point #1: Undefined behavior, program crushes

	ClassForNullPointer * a = new ClassForNullPointer();
	std::cout << "a :" << a << std::endl;                      //a :0x9267078
	if (a != NULL){
		std::cout << "a != NULL" << std::endl;
		delete a;                                              //ClassForNullPointer destructor
		a = NULL;
	}

	if (a != NULL){
		std::cout << "Second a != NULL" << std::endl;		   //Won't come here
		delete a;                                              //And there will be no program crash
		a = NULL;
	}

	if (a){
		std::cout << "!a" << std::endl;		                   //Won't come here
		delete a;
		a = NULL;
	}



}

