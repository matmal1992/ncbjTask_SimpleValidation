#include <iostream>
#include <exception>
#include "code.h"

using namespace std;

int Derived::getValue() const{
    return value;
}

void Derived::setValue(int value) const{
    this -> value = value;
    counter++;
}

int Derived::getCounter() const{
    return counter;
}

int getRandomNumber(){
    int number{};
    srand(time(NULL));

    number = rand()% 4 + 1;
    return number; 
}

void caseValidation(const isimple &a, int b){
    test_1(a, b);
    test_2(a, b);
    test_3(a, b);
    test_4(a, b);
    test_5(a, b);
    test_6(a, b);
}

void test_1(const isimple &a, int b){
    cout << "T1: If a.getValue() == 10, throw std::runtime_error" << endl;

    if(a.getValue() == 10)
        cout << "T1:-PASSED-| a.getValue() == 10 | std::runtime_error should be thrown" << endl << endl;
    else
        cout << "T1: FAILED | a.getValue() != 10" << endl << endl;
}

void test_2(const isimple &a, int b){
    cout << "T2: If b == 34, throw std::runtime_error" << endl;

    if(b == 34)
        cout << "T2:-PASSED-| b == 34 | std::runtime_error should be thrown" << endl << endl;
    else
        cout << "T2: FAILED | b != 34" << endl << endl;
}

void test_3(const isimple &a, int b){
    cout << "T3: If b < 10, call a.setValue(b) exactly one time" << endl;

    if(b < 10){
        if(a.getValue() == b && a.getCounter() == 1)
            cout << "T3:-PASSED-| b < 10 and a.getValue() == b" << endl << endl;
        else
            cout << "T3: FAILED | b < 10, but a.getValue() != b or a.set(b) has been called more than once" << endl << endl;
    }
    else
        cout << "T3: FAILED | b >= 10" << endl << endl;
}

void test_4(const isimple &a, int b){
    cout << "T4: If b >= 10, call a.setValue(2 * b) at least one time" << endl;

    if(b >= 10){
        if(a.getValue() == (2 * b)  &&  a.getCounter() > 0)
            cout << "T4:-PASSED-| b >= 10 and a.getValue() == 2 * b" << endl << endl;
        else
            cout << "T4: FAILED | b >= 10, but a.getValue() != 2*b or a.set(b) has never been called" << endl << endl;
    }
    else
        cout << "T4: FAILED | b >= 10" << endl << endl;
}

void test_5(const isimple &a, int b){
    cout << "T5: If b == 10, return b" << endl;

    if(b == 10){
        if(ncbj_function(a, b) == b)
            cout << "T5:-PASSED-| b == 10 and ncbj_function() returns b" << endl << endl;
        else
            cout << "T5: FAILED | b == 10 but ncbj_function() doesn't return b" << endl << endl;
    }
    else
        cout << "T5: FAILED | b != 10" << endl << endl;
}

void test_6(const isimple &a, int b){
    cout << "T6: If b != 10, return a.getValue()" << endl;

    if(b != 10){
        if(ncbj_function(a, b) == a.getValue() )
            cout << "T6:-PASSED-| b != 10 and ncbj_function() returns a.getValue()" << endl << endl;
        else
            cout << "T6: FAILED | b != 10 but ncbj_function() doesn't return a.getValue()" << endl << endl;
    }
    else
        cout << "T6: FAILED | b == 10" << endl << endl;
}
