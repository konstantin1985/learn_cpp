
#include "factory_method.h"
#include "stddef.h"

Root *TestFactoryMethod::FactoryMethod(int a){
	if(a == 1){
		return new Derivative1;
	}
	else if(a == 2){
		return new Derivative2;
	}
	else{
		std::cout << "my ERROR" << std::endl;
		return NULL;
	}
}

//what is invoked here T t = new T;

void TestFactoryMethodPattern(){

	int i;
	std::cout << "Enter object number: ";
	std::cin >> i;

	TestFactoryMethod tfm;
	Root *a = tfm.FactoryMethod(1);
	Root *b = tfm.FactoryMethod(2);
	Root *c = tfm.FactoryMethod(i);

	a->DoStuff();
	b->DoStuff();
	c->DoStuff();
}
