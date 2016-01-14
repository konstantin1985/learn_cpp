
#include "callback.h"
#include <iostream>

std::cout << "FUNCTION CALLBACK:" << std::endl;


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

void CallBackTest(){

	std::cout << "UseCallback(): " << UseCallback(1, Foo) << std::endl;                   //UseCallback(): 13
	std::cout << "UseCallback(): " << UseCallback(1, &Foo) << std::endl;                  //same meaning, UseCallback(): 13

	std::cout << "UseCallback_typedef(): " << UseCallback_typedef(5, Foo) << std::endl;   //UseCallback_typedef(): 1007
	std::cout << "UseCallback_typedef(): " << UseCallback_typedef(5, &Foo) << std::endl;  //same meaning, UseCallback_typedef(): 1007

}


