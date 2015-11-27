#include "size_empty_splice.h"

//http://www.cplusplus.com/reference/list/list/splice/

template<typename T>
void PrintList(std::list<T> l){

	typename std::list<T>::iterator it;
	for(it = l.begin(); it != l.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void TestSizeEmpty1(){

	std::list<int> myList1, myList2;
	std::list<int>::iterator it;

	for(int i = 1; i <= 4; ++i)
		myList1.push_back(i);       //1 2 3 4

	for(int i = 1; i <= 3; ++i)
		myList2.push_back(i*10);    //10 20 30

	it = myList1.begin();
	++it;

	myList1.splice(it, myList2);
	PrintList(myList1);                       //1 10 20 30 2 3 4
	PrintList(myList2);                       //nothing, because myList2 is emptied by slice
	if(myList2.empty())
		std::cout << "EMPTY" << std::endl;    //EMPTY
	std::cout << *it << std::endl;            //2


	std::cout << std::string(100, '*') << std::endl;

    //splice a single element
	myList2.splice(myList2.begin(), myList1, it);
	PrintList(myList1);                       //1 10 20 30 3 4
	PrintList(myList2);                       //2
	if(myList2.empty())
		std::cout << "EMPTY" << std::endl;    //nothing
	std::cout << *it << std::endl;            //2, it's said that it is invalid now


	std::cout << std::string(100, '*') << std::endl;

	it = myList1.begin();
	std::advance(it, 3);
	//Cut from one place and put in front of the list
	myList1.splice(myList1.begin(), myList1, it, myList1.end());
	PrintList(myList1);                       //30 3 4 1 10 20

}



