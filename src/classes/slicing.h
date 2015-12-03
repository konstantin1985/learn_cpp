/*
 * slicing.h
 *
 *  Created on: Dec 3, 2015
 *      Author: konstantin
 */

#ifndef SLICING_H_
#define SLICING_H_

//http://stackoverflow.com/questions/274626/what-is-object-slicing

#include <iostream>
#include <string>

class Pet
{
 public:
    std::string name;
};

class Dog : public Pet
{
public:
    std::string breed;
};

class B{
public:
	B(){}
	//Important to have const here, won't work otherwise
	B(const B &b){
		std::cout << "B copy constructor" << std::endl;
	}
	virtual void Run() const{
		std::cout << "B run" << std::endl;
	}
};

class D : public B{
public:
	D() : B(){}
	D(const D &d) : B(d){
		std::cout << "D copy constructor" << std::endl;
	}
	virtual void Run() const{
		std::cout << "D run" << std::endl;
	}
};

void __FunctionReference(const B & b);
void __FunctionValue(const B b);

void SlicingTestFirst();
void SlicingTestSecond();
void SlicingTestThird();




#endif /* SLICING_H_ */
