
#include <ctime>
#include <vector>
#include <iostream>

void __MeasuredFunctionNoReserve(){
	std::vector<int> v;
	int x = 10000000;
	for(int i = 0; i < x; i++)
		v.push_back(i);
}

void __MeasuredFunctionReserve(){
	std::vector<int> v;
	int x = 10000000;
	v.reserve(x);
	for(int i = 0; i < x; i++)
		v.push_back(i);
}


void f() {

	using namespace std;
    clock_t begin = clock();
    __MeasuredFunctionNoReserve();
    clock_t end = clock();
    double elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
    cout << elapsed_secs << " s" << endl; //0.22 s

    begin = clock();
    __MeasuredFunctionReserve();
    end = clock();
    elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
    cout << elapsed_secs << " s" << endl; //0.16 s

}

