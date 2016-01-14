//http://stackoverflow.com/questions/2298242/callback-functions-in-c


#include "callback.h"
#include <iostream>

//FUNCTION CALLBACK:

int Foo(int x){
	return x + 2;
}

typedef int (*Foo_t)(int); //Foo_t is now a type

int UseCallback(int x, int (*f)(int)){
	return f(x) + 10;
}

int UseCallback_typedef(int x, Foo_t f){
	return f(x) + 1000;
}

//TEMPLATED CALLBACK TYPE:

template<typename F>
int UseCallback_template(int x, F f){
	return f(x) + 1000000;
}

void CallBackTest(){

	std::cout << "FUNCTION CALLBACK:" << std::endl;

	std::cout << "UseCallback(): " << UseCallback(1, Foo) << std::endl;                   //UseCallback(): 13
	std::cout << "UseCallback(): " << UseCallback(1, &Foo) << std::endl;                  //same meaning, UseCallback(): 13

	std::cout << "UseCallback_typedef(): " << UseCallback_typedef(5, Foo) << std::endl;   //UseCallback_typedef(): 1007
	std::cout << "UseCallback_typedef(): " << UseCallback_typedef(5, &Foo) << std::endl;  //same meaning, UseCallback_typedef(): 1007

	std::cout << "TEMPLATED CALLBACK TYPE:" << std::endl;

	std::cout << "UseCallback_template: " << UseCallback_template(7, Foo) << std::endl;   //UseCallback_template: 1000009


}


