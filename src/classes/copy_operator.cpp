#include "copy_operator.h"

void WorkWithClassTestClass() {

    using namespace std;

    cout << endl << "WorkWithClassTestClass()" << endl << endl;

    TestClass a;                                        //TestClass constructor
    std::cout << std::string(20, '*') << std::endl;
    TestClass * b = new TestClass;                      //TestClass constructor
    std::cout << std::string(20, '*') << std::endl;
    TestClass c;                                        //TestClass constructor
    TestClass d;                                        //TestClass constructor
    c = d;                                              //Assignment Operator
    std::cout << std::string(20, '*') << std::endl;
    TestClass * e;                                      //nothing, it's just a creation of a pointer. No instance is created
    TestClass * f;                                      //nothing, it's just a creation of a pointer. No instance is created
    std::cout << std::string(20, '*') << std::endl;
    TestClass g("kozel");                                //Integer TestClass constructor
    TestClass h("osel");                                 //Integer TestClass constructor
    std::cout << "g: " << g.TestClassName << std::endl;  //g: kozel
    std::cout << "h: " << h.TestClassName << std::endl;  //h: osel
    g = h;                                               //Assignment Operator
    std::cout << "g: " << g.TestClassName << std::endl;  //g: osel
    std::cout << "h: " << h.TestClassName << std::endl;  //h: osel
    std::cout << std::string(20, '*') << std::endl;
    TestClass i("kozel");                                //Integer TestClass constructor
    TestClass j = i;                                     //Copy constructor
}


void WorkWithClassPointer() {

    using namespace std;

    cout << endl << "WorkWithClassPointer()" << endl << endl;

    ClassPointer nao1(777);
    ClassPointer nao2(555);

    cout << "*(nao1.n): " << *(nao1.n) << endl;   //777
    cout << "nao1.n: " << nao1.n << endl;         //0x972c130
    cout << "*(nao2.n): " << *(nao2.n) << endl;   //555
    cout << "nao2.n: " << nao2.n << endl;         //0x972c150

    nao2 = nao1;

    cout << "*(nao1.n): " << *(nao1.n) << endl;   //777
    cout << "nao1.n: " << nao1.n << endl;         //0x972c130
    cout << "*(nao2.n): " << *(nao2.n) << endl;   //777
    cout << "nao2.n: " << nao2.n << endl;         //0x972c150 another address

    delete nao1.n;

    cout << "*(nao1.n): " << *(nao1.n) << endl;   //0
    cout << "nao1.n: " << nao1.n << endl;         //0x972c130
    cout << "*(nao2.n): " << *(nao2.n) << endl;   //777
    cout << "nao2.n: " << nao2.n << endl;         //0x972c150

}


void WorkWithClassPointerNoAssignmentOperator() {

    using namespace std;

    cout << endl << "WorkWithClassPointerNoAssignmentOperator()" << endl << endl;

    ClassPointerNoAssignmentOperator nao1(777);
    ClassPointerNoAssignmentOperator nao2(555);

    cout << "*(nao1.n): " << *(nao1.n) << endl;   //777
    cout << "nao1.n: " << nao1.n << endl;         //0x88a6130
    cout << "*(nao2.n): " << *(nao2.n) << endl;   //555
    cout << "nao2.n: " << nao2.n << endl;         //0x88a6140

    nao2 = nao1;

    cout << "*(nao1.n): " << *(nao1.n) << endl;   //777
    cout << "nao1.n: " << nao1.n << endl;         //0x88a6130
    cout << "*(nao2.n): " << *(nao2.n) << endl;   //777
    cout << "nao2.n: " << nao2.n << endl;         //0x88a6130 same address

    delete nao1.n;

    cout << "*(nao1.n): " << *(nao1.n) << endl;   //0
    cout << "nao1.n: " << nao1.n << endl;         //0x88a6130
    cout << "*(nao2.n): " << *(nao2.n) << endl;   //0
    cout << "nao2.n: " << nao2.n << endl;         //0x88a6130

}

void TestCopyOperator(){

    WorkWithClassTestClass();

    WorkWithClassPointerNoAssignmentOperator();

    WorkWithClassPointer();

}


