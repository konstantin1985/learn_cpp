#include "slicing.h"


void __FunctionReference(const B & b){
    b.Run();
}

//The most important point here is that B copy constructor is invoked
//Even if we pass instance of D to this function
void __FunctionValue(const B b){
    b.Run();
}

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
	std::cout << ((Dog *)ptrP)->breed << std::endl; //Kangal Dog
	//std::cout << ptrP->breed; //src/classes/slicing.cpp:25:21: error: 'class Pet' has no member named 'breed'

}


//Difference in passing by reference and by value
void SlicingTestThird(){
    std::cout << "Call by reference" << std::endl;
    __FunctionReference(D());
    //"D run"
    std::cout << "Call by copy" << std::endl;
    __FunctionValue(D());
    //"B copy constructor", because we pass by value to the function that expects B
    //"B run"

}
