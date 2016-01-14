/*
 * class_static.h
 *
 *  Created on: Jan 11, 2016
 *      Author: konstantin
 */

#ifndef CLASS_STATIC_H_
#define CLASS_STATIC_H_

class ClassWithStaticMembers{

public:
	static int x;
	const static int y = 1; //only const static [simple type] can be defined in a class

	static void DoStuff();

};

void ClassStaticTest();


#endif /* CLASS_STATIC_H_ */
