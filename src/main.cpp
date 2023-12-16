#include <iostream>
#include "Hello.h"
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
    Hello hi;
    hi.print();

    #ifdef EX3
    std::cout << "Compile flag EX3" << std::endl;
    #endif

    boost::shared_ptr<int> isp(new int(4));
    boost::filesystem::path path = "usr/share/cmake/modules";
    if(path.is_relative())
    {
        std::cout << "path is relative" << std::endl;
    }
    else
    {
        std::cout << "path is not a relative" << std::endl;
    }

    return 0;
}