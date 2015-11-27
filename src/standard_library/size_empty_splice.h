/*
 * size_empty.h
 *
 *  Created on: Nov 27, 2015
 *      Author: konstantin
 */

#ifndef SIZE_EMPTY_H_
#define SIZE_EMPTY_H_

//Item 4. Call empty instead of checking size() against zero.

/*
You should prefer the construct using empty, and the reason is simple: empty isconstant-time operation for all standard containers, but for some list implementations,
size takes linear time.
*/

/*
No matter how you look at it, something — size or splice — has to give.
One or the other can be a constant-time operation, but not both.
 */

/*
If you happen to be using a list implementation where a constant-time splice was given
higher priority than a constant-time size, you'll be better off calling empty than size,
because empty is always a constant-time operation.
*/

//http://stackoverflow.com/questions/10134836/complexity-of-stdlistsplice-and-other-list-containers

/*
Before C++11, many implementations made size linear time and splice between different lists
constant time. C++11 now requires that size be constant and splice be linear.
*/

#include <list>
#include <iostream>
#include <string.h>

void TestSizeEmpty1();


#endif /* SIZE_EMPTY_H_ */
