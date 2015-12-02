/*
 * sort.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: konstantin
 */

#include "sort.h"

template<typename T>
void PrintVector(std::vector<T> v){

	typename std::vector<T>::const_iterator it;

	for(it = v.begin(); it != v.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

struct sort_functor_first{
	bool operator() (double i, double j){
		return (i<j);
	}
} sort_functor_first_object;

struct sort_functor_second : public std::binary_function<double,double,bool> {
  bool operator() (double a, double b){
	  std::cout << "Compare::operator()" << std::endl;
	  return (a>b);
  }
} sort_functor_second_object;


void SortTest(){

	std::vector<double> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(0.8);
	PrintVector(v);
	std::sort(v.begin(), v.end(), sort_functor_first());
	PrintVector(v); //1 3 2 0.8

    v.clear();
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(0.8);
    PrintVector(v);
	std::sort(v.begin(), v.end(), sort_functor_first_object);
	PrintVector(v); //1 3 2 0.8

	v.clear();
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(0.8);
	PrintVector(v);
	std::sort(v.begin(), v.end(), sort_functor_second());
	PrintVector(v); //3 2 1 0.8

	v.clear();
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(0.8);
	PrintVector(v);
	std::sort(v.begin(), v.end(), sort_functor_second_object);
	PrintVector(v); //3 2 1 0.8

	struct sort_functor_third{
		bool operator() (double i, double j){
			return (i<j);
		}
	} sort_functor_third_object;

	v.clear();
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(0.8);
	PrintVector(v);
	//Error in C++98, functor needs external linkage
	//http://stackoverflow.com/questions/742607/using-local-classes-with-stl-algorithms
	//std::sort(v.begin(), v.end(), sort_functor_third_object);



}

