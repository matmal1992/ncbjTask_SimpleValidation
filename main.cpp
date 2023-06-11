#include "code.h"
using namespace std;

int main(){
    
    Derived d1;
    isimple *ptr = &d1;

    int b = 10;
    ncbj_function(*ptr, b);
    caseValidation(*ptr, b);

    return 0;
}
