#ifndef _CODE_H_
#define _CODE_H_

#include <iostream>
#include <exception>

using namespace std;

struct isimple{
    virtual int getValue() const = 0;
    virtual void setValue(int) const = 0;
    virtual int getCounter() const = 0;
};

class Derived : public isimple{
    
    mutable int value;
    mutable int counter;

public:
    Derived() : value(0) , counter(0) {}

    virtual int getValue() const override;
    virtual void setValue(int value) const override;
    virtual int getCounter() const override;
};

int getRandomNumber();

constexpr int ncbj_function(const isimple &a, int b){
    
    if (a.getValue() == 10)
        throw runtime_error("a.getValue() = 10");

    if ( b == 34)
        throw runtime_error("b = 34");

    if (b < 10)
        a.setValue(b);

    if (b >= 10)
        for(int i = 0; i <= getRandomNumber(); ++i)
            a.setValue(2 * b);

    if (b == 10)
        return b;
    else
        return a.getValue();
}


void caseValidation(const isimple &a, int b);

void test_1(const isimple &a, int b);
void test_2(const isimple &a, int b);
void test_3(const isimple &a, int b);
void test_4(const isimple &a, int b);
void test_5(const isimple &a, int b);
void test_6(const isimple &a, int b);

#endif
        
       