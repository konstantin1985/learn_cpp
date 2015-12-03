#include "slicing.h"

void SlicingTestFirst(){

    Dog dog;
    Pet pet;

    dog.name = "Tommy";
    dog.breed = "Kangal Dog";
    pet = dog;
    //std::cout << pet.breed; //src/classes/slicing.cpp:11:22: error: 'class Pet' has no member named 'breed'

}


void SlicingTestSecond(){

	Pet *ptrP;
	Dog *ptrD;
	ptrD = new Dog;
	ptrD->name = "Tommy";
	ptrD->breed = "Kangal Dog";
	ptrP = ptrD;
	std::cout << ((Dog *)ptrP)->breed;
	//std::cout << ptrP->breed; //src/classes/slicing.cpp:25:21: error: 'class Pet' has no member named 'breed'

}
