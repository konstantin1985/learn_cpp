/*
 * factory_method.h
 *
 *  Created on: Nov 25, 2015
 *      Author: konstantin
 */

#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

class Root{

public:
	Root(){
		std::cout << "Root constructor" << std::endl;
	}

	virtual void DoStuff() = 0;

};

class Derivative1 : public Root{

	Derivative1(){
		std::cout << "Derivative1 constructor" << std::endl;
	}

	void DoStuff(){
		std::cout << "Derivative1 DoStuff" << std::endl;
	}

};

class Derivative2 : public Root{

	Derivative2(){
		std::cout << "Derivative2 constructor" << std::endl;
	}

	void DoStuff(){
		std::cout << "Derivative2 DoStuff" << std::endl;
	}
};

class TestFactoryMethod{

	Root *FactoryMethod(int a);
};



#endif /* FACTORY_METHOD_H_ */
