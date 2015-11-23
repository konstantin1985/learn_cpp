/*
 * singleton.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: konstantin
 */

#include "singleton.h"
#include <stdio.h>

void TestSingleton(){

	//http://stackoverflow.com/questions/620137/do-the-parentheses-after-the-type-name-make-a-difference-with-new
	//Number num(); // declare a function called num which returns Number
	//Number num; //error: 'Number::Number()' is protected
	Number::GetInstance()->PrintSomething();
	std::cout << std::string(100, '*') << std::endl;
	Number *num = Number::GetInstance();
	num->PrintSomething();
}

//KS: VERY IMPORTANT POINT
//http://www.learncpp.com/cpp-tutorial/811-static-member-variables/
Number *Number::instance = 0;
