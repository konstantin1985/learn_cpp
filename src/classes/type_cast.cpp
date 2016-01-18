/*
 * type_cast.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: konstantin
 */


#include <iostream>
#include "type_cast.h"

void TypeCastTestFirst(){
	std::cout << "TypeCastTest" << std::endl;
	Grand * pg;
	Superb * ps;

	pg = GetOne(1);
	pg->Speak();                            //I'm a grand class!
	if(ps = dynamic_cast<Superb *>(pg))     //pg is of type Grand, inside pg is Grand (see GetOne()), can't be converted to Superb
		ps->Say();                          //can't be here

	pg = GetOne(2);
	pg->Speak();                            //I'm a superb class (virtual method works), inside pg is Superb, so when we invoke virtual Speak() of pg, Speak() of Superb is invoked
	//pg->Say();                            //pg is of type Grand, inside pg is Superb. But pg doesn't know about Say() method
	if(ps = dynamic_cast<Superb *>(pg))     //inside pg is Superb
		ps->Say();                          //I hold the superb value of 20!

	pg = GetOne(3);
	pg->Speak();                            //I'm a magnificent class! (virtual method works), inside pg is Magnificent, so when we invoke virtual Speak() of pg, Speak() of Magnificent is invoked
	if(ps = dynamic_cast<Superb *>(pg))     //pg is of type Grand, inside pg is Magnificent, it's cast to Superb
		ps->Say();                          //I hold the character A and the integer 30! - answer of Magnificent, because Say() is a virtual method
}

//http://stackoverflow.com/questions/6322949/downcasting-using-the-static-cast-in-c

Grand * GetOne(int t){
	Grand *p;
	switch(t){
	case 1: p = new Grand(10); break;
	case 2: p = new Superb(20); break;
	case 3: p = new Magnificent(30); break;
	}
	return p;
}


/*
On dynamic_cast:

In general, the following expression converts the pointer pt to a pointer of type Type * if the
pointed-to object (*pt) is of type Type or else derived directly or indirectly from type Type:
dynamic_cast<Type *>(pt)
Otherwise, the expression evaluates to 0, the null pointer.

The purpose of this operator is to allow upcasts within a class hierarchy (such type
casts being safe because of the is-a relationship) and to disallow other casts.
*/
