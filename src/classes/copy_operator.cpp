#include "copy_operator.h"

void TestCopyOperator(){
	TestClass a;                                        //TestClass constructor
	std::cout << std::string(100, '*') << std::endl;
	TestClass * b = new TestClass;                      //TestClass constructor
	std::cout << std::string(100, '*') << std::endl;
	TestClass c;                                        //TestClass constructor
	TestClass d;                                        //TestClass constructor
	c = d;                                              //Assignment Operator
	std::cout << std::string(100, '*') << std::endl;
	TestClass * e;                                      //nothing, it's just a creation of a pointer. No instance is created
	TestClass * f;                                      //nothing, it's just a creation of a pointer. No instance is created
	std::cout << std::string(100, '*') << std::endl;
	TestClass g("kozel");                                //Integer TestClass constructor
	TestClass h("osel");                                 //Integer TestClass constructor
	std::cout << "g: " << g.TestClassName << std::endl;  //g: kozel
	std::cout << "h: " << h.TestClassName << std::endl;  //h: osel
	g = h;                                               //Assignment Operator
	std::cout << "g: " << g.TestClassName << std::endl;  //g: osel
	std::cout << "h: " << h.TestClassName << std::endl;  //h: osel
}


