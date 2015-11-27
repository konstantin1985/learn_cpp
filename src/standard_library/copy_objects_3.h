/*
 * copy_objects.h
 *
 *  Created on: Nov 26, 2015
 *      Author: konstantin
 */

#ifndef SRC_STANDARD_LIBRARY_COPY_OBJECTS_3_H_
#define SRC_STANDARD_LIBRARY_COPY_OBJECTS_3_H_

/*
when you add an object to a container (via. e.g.. insert or push_back. etc.),
what goes into the container is a copy of the object you specify. When you get an
object from a container (via. e.g.. front or back), what you set is a copy of what was
contained. Copy in, copy out. That's the STL way.
*/


/*
With all this copying taking place, the motivation for this Item should now be clear. If
you fill a container with objects where copying is expensive, the simple act of putting
the objects into the container could prove to be a performance bottleneck.
*/

/*
In the presence of inheritance, of course, copying leads to slicing. That is, if you create
a container of base class objects and you try to insert derived class objects into it, the
derivedness of the objects will be removed as the objects are copied (via the base class
copy constructor) into the container
*/

/*
The slicing problem suggests that inserting a derived class object into a container of
base class objects is almost always an error. If you want the resulting object to act like
a derived class object, e.g., invoke derived class virtual functions, etc., it is always an
error.
*/

/*
An easy way to make copying efficient, correct, and immune to the slicing problem is
to create containers of pointers instead of containers of objects. That is, instead of
creating a container of Widget, create a container of Widget*.
*/

/*
Copying pointers is fast,
it always does exactly what you expect (it copies the bits making up the pointer), and
nothing gets sliced when a pointer is copied.
*/

#include <vector>
#include <string>
#include <iostream>

class CopyClass{

public:
	CopyClass(){
		std::cout << "CopyClass constructor" << std::endl;
	};

	CopyClass(const CopyClass& other){
		std::cout << "CopyClass copy constructor" << std::endl;
	};

};





void CopyObjects3Test();












#endif /* SRC_STANDARD_LIBRARY_COPY_OBJECTS_3_H_ */
