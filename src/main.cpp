#include <iostream>
#include "Hello.h"

int main(int argc, char *argv[])
{
    Hello hi;
    hi.print();

    #ifdef EX2
    std::cout << "Compile flag EX2" << std::endl;
    #endif

    #ifdef EX3
    std::cout << "Compile flag EX3" << std::endl;
    #endif
    return 0;
}