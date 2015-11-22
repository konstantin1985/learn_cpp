/*
 * singleton.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: konstantin
 */

#include "singleton.h"

/*
void TestSingleton(){
	Number num();


}
*/
//http://www.learncpp.com/cpp-tutorial/811-static-member-variables/
Number *Number::instance = 0;
