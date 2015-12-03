/*
 * slicing.h
 *
 *  Created on: Dec 3, 2015
 *      Author: konstantin
 */

#ifndef SLICING_H_
#define SLICING_H_

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



void SlicingTestFirst();
void SlicingTestSecond();



#endif /* SLICING_H_ */
