
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

template<typename T>
void PrintList(std::list<T> v){
	typename std::list<T>::const_iterator it;

	for(it = v.begin(); it != v.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T, typename R>
void PrintMap(std::map<T, R> v){
	typename std::map<T, R>::const_iterator it;

	for(it = v.begin(); it != v.end(); ++it){
		std::cout << it->first << ": " << it->second << " |";
	}
	std::cout << std::endl;
}




bool ReturnIntTrue(const int & a){
	return true;
}

bool ReturnIntFalse(const int & a){
	return false;
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
	PrintVector(v);                       //1 2 3 5 7 8 9 8 9 99


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


void EraseRemoveIfTest(){

	std::vector<int> v;
	v.reserve(10);
	for(int i = 1; i <= 10; ++i){
		v.push_back(i);
	}

	v[3] = v[5] = v[9] = 99;
	PrintVector(v); //1 2 3 99 5 99 7 8 9 99
	v.erase(remove_if(v.begin(), v.end(), ReturnIntTrue), v.end());
	PrintVector(v); //nothing

	std::cout << std::string(100, '*') << std::endl;

	std::vector<int> w;
	w.reserve(10);
	for(int i = 1; i <= 10; ++i){
		w.push_back(i);
	}

	w[3] = w[5] = w[9] = 99;
	PrintVector(w); //1 2 3 99 5 99 7 8 9 99
	w.erase(remove_if(w.begin(), w.end(), ReturnIntFalse), w.end());
	PrintVector(w); //1 2 3 99 5 99 7 8 9 99

}

bool __BadValue(int x){
	if(x == 0 || x == 1 || x == 2)
		return true;
	return false;
}

void EraseRemoveContiguousMemory(){
	std::vector<int> v(10);
	//http://stackoverflow.com/questions/6032638/default-variable-value
	int i = 0;
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it, i++)
		*it = i;
	PrintVector(v); //0 1 2 3 4 5 6 7 8 9

	std::vector<int> w;
	w.assign(v.begin(), v.end());
	PrintVector(w); //0 1 2 3 4 5 6 7 8 9

	v.erase(std::remove(v.begin(), v.end(), 8), v.end());
	PrintVector(v); //0 1 2 3 4 5 6 7 9

	v.erase(std::remove_if(v.begin(), v.end(), __BadValue), v.end());
	PrintVector(v); //3 4 5 6 7 9

	/*
	Recall that for such containers, invoking erase not only invalidates all iterators pointing to the erased
	element, it also invalidates all iterators beyond the erased element. In our case, that
	includes all iterators beyond i. It doesn't matter if we write i++, ++I, or anything else
	you can think of, because none of the resulting iterators is valid.
	*/

	for(std::vector<int>::iterator it = w.begin(); it != w.end();){
		if(__BadValue(*it)){
			std::cout << "log message" << std::endl;
			it = w.erase(it);
		}
		else ++it;
	}
	PrintVector(w); //3 4 5 6 7 8 9
}

void EraseRemoveList(){
	std::list<int> v(10);
	int i = 0;

	for(std::list<int>::iterator it = v.begin(); it != v.end(); ++it, i++)
		*it = i;
	PrintList(v); //0 1 2 3 4 5 6 7 8 9

	std::list<int> w;
	w.assign(v.begin(), v.end());
	PrintList(w); //0 1 2 3 4 5 6 7 8 9

	v.remove(7);
	PrintList(v); //0 1 2 3 4 5 6 8 9
	v.remove_if(__BadValue);
	PrintList(v); //3 4 5 6 8 9

	for(std::list<int>::iterator it = w.begin(); it != w.end();){
		if(__BadValue(*it)){
			std::cout << "log message" << std::endl;
			it = w.erase(it);
		}
		else ++it;
	}
	PrintList(w);  //3 4 5 6 7 8 9
}



void EraseRemoveAssociative(){

	std::map<int, char> m;
	m[1] = 'a';
	m[2] = 'b';
	m[4] = 'd';
	PrintMap(m); //1: a |2: b |4: d |

	std::map<int, char> w;
	w.insert(m.begin(), m.end());
	PrintMap(w); //1: a |2: b |4: d |

	m.erase(1);  //first, not second
	PrintMap(m); //2: b |4: d |

	for(std::map<int, char>::iterator it = w.begin(); it != w.end(); ){
		if(__BadValue(it->first))
			w.erase(it++);
		else
			++it;
	}
	PrintMap(w); //4: d |

}














