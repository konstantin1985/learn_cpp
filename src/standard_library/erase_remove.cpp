
#include "erase_remove.h"

//http://stackoverflow.com/questions/16013545/how-do-i-erase-elements-from-stl-containers

template<typename T>
void PrintVector(std::vector<T> v){

	typename std::vector<T>::const_iterator it;

	for(it = v.begin(); it != v.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void EraseRemoveTest(){

	std::vector<int> v;
	v.reserve(10);
	for(int i = 1; i <= 10; ++i){
		v.push_back(i);
	}

	std::cout << v.size() << std::endl;   //10
	PrintVector(v);                       //1 2 3 4 5 6 7 8 9 10

	v[3] = v[5] = v[9] = 99;
	PrintVector(v);                       //1 2 3 99 5 99 7 8 9 99

	std::remove(v.begin(), v.end(), 99);
	std::cout << v.size() << std::endl;   //10
	PrintVector(v);                       //1 2 3 5 7 8 9 8 9 99=


	std::cout << std::string(100, '*') << std::endl;

	std::vector<int> w;
	w.reserve(10);
	for(int i = 1; i <= 10; ++i){
		w.push_back(i);
	}
	w[3] = w[5] = w[9] = 99;
	PrintVector(w);                        //1 2 3 99 5 99 7 8 9 99
	std::vector<int>::const_iterator newEnd(std::remove(w.begin(), w.end(), 99));
	std::cout << *newEnd << std::endl;     //8
	PrintVector(w);                        //1 2 3 5 7 8 9 8 9 99


	std::cout << std::string(100, '*') << std::endl;
	/*
	Remove doesn't eliminate any elements from a container, because it can't.
	Only container member functions can eliminate container elements,
	and that's the whole point of this Item: You should follow remove by erase if you
	really want to remove something.
	*/

	std::vector<int> x;
	x.reserve(10);
	for(int i = 1; i <= 10; ++i){
		x.push_back(i);
	}

	x[3] = x[5] = x[9] = 99;
	PrintVector(x);                       //1 2 3 99 5 99 7 8 9 99
	x.erase(remove(x.begin(), x.end(), 99), x.end());
	PrintVector(x);                       //1 2 3 5 7 8 9


	std::cout << std::string(100, '*') << std::endl;
	/*
	In fact, remove and erase are so closely allied, the two are
	merged in the list member function remove. This is the only function in the STL
	named remove that eliminates elements from a container:
	*/
	std::list<int> l;
	l.push_back(99);
	for(int i = 1; i <= 10; ++i){
		l.push_back(i);
	}
	l.push_back(99);
	std::cout << l.size() << std::endl;   //12
	l.remove(99);
	std::cout << l.size() << std::endl;   //10

}




