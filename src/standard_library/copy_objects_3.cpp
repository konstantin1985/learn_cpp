#include "copy_objects_3.h"

void CopyObjects3Test(){

	CopyClass w[5];              //5xCopyClass constructor

	std::cout << std::string(100, '*') << std::endl;

	std::vector<CopyClass> vwx; //nothing is constructed
	vwx.reserve(5);             //nothing is constructed
	CopyClass c;                //CopyClass constructor
	vwx.push_back(c);           //CopyClass copy constructor


	std::cout << std::string(100, '*') << std::endl;

	std::vector<CopyClass *> vw; //nothing is constructed
	vw.reserve(5);               //nothing is constructed

	std::cout << std::string(100, '*') << std::endl;

	CopyClass cc;                //CopyClass constructor
	vw.push_back(&cc);           //nothing, copy pointer

}
