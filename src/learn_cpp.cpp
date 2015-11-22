//============================================================================
// Name        : learn_cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "singleton.h"


using namespace std;

int main() {
	cout << "!!!Hello World 1!!!" << endl; // prints !!!Hello World!!!
	//TestSingleton();

	Number::GetInstance()->PrintSomething();


	return 0;
}
