#ifndef SRC_PATTERNS_SINGLETON_SINGLETON_H_
#define SRC_PATTERNS_SINGLETON_SINGLETON_H_

#include <iostream>
using namespace std;


class Number
{
public:

	static Number *GetInstance(){
		std::cout << "GetInstance" << std::endl;
		if(!instance){
			instance = new Number();
		}
		return instance;
	}

	void PrintSomething(){
		std::cout << "PrintSomething" << std::endl;
	}

protected:
	Number(){
		std::cout << "Number Constructor" << std::endl;
	};

private:
	static Number *instance;

};

void TestSingleton();

#endif /* SRC_PATTERNS_SINGLETON_SINGLETON_H_ */
