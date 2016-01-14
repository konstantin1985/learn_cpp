/*
 * enum.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: konstantin
 */

#include <iostream>

enum Kozel{
	aaa = 5,
	bbb = 7,
	ccc
};

class C{

public:
	enum Osel{
		a1,
		b1,
		c1
	};

};



void EnumTest(){
	std::cout << "EnumTest" <<std::endl;
	Kozel k = aaa;
	k = Kozel(7);
	//k = Kozel(777); //undefined
	std::cout << k << std::endl;

	C c = C();
	//Osel is a CLASS SCOPE constant (read Prata C++ Primer Plus)
	C::Osel q = C::b1;
	std::cout << q << std::endl;


}



