/*
 * equal_equivalent.h
 *
 *  Created on: Dec 2, 2015
 *      Author: konstantin
 */

#ifndef EQUAL_EQUIVALENT_H_
#define EQUAL_EQUIVALENT_H_

/*
Every standard associative container makes its sorting predicate
available through its key_comp member function, so two objects x and y have
equivalent values with respect to an associative container c's sorting criterion if the
following evaluates to true:
!c.key_comp()(x, y) && !c.key_comp()(y, x)
// it's not true that x precedes
// y in c's sort order and it's
// also not true that y precedes
// x in c's sort order
*/

//http://www.sgi.com/tech/stl/functors.html

//http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/

/*
A predicate class is a functor class whose operator() function is a predicate, i.e.,
its operator() returns true or false. As you might expect, any place the STL
expects a predicate, it will accept either a real predicate or an object of a
predicate class.
*/

#endif /* EQUAL_EQUIVALENT_H_ */
