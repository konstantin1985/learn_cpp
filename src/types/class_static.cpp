/*
 * class_static.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: konstantin
 */

#include "class_static.h"
#include <iostream>

int ClassWithStaticMembers::x = 777;
void ClassWithStaticMembers::DoStuff(){
	std::cout << "ClassWithStaticMembers::DoStuff()" << std::endl;
}

void ClassStaticTest(){
	std::cout << "ClassStaticTest Start" << std::endl;
	ClassWithStaticMembers a = ClassWithStaticMembers();
	ClassWithStaticMembers b = ClassWithStaticMembers();

	std::cout << "Deal with x" << std::endl;
	std::cout << a.x << std::endl;
	a.x = 555;
	std::cout << a.x << std::endl;
	std::cout << b.x << std::endl;

	std::cout << "Deal with y" << std::endl;
	std::cout << a.y << std::endl;
	std::cout << b.y << std::endl;

	std::cout << "ClassStaticTest Stop" << std::endl;

	std::cout << "Deal with DoStuff" << std::endl;
	ClassWithStaticMembers::DoStuff();
	a.DoStuff();
	b.DoStuff();

}


