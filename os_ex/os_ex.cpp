#include <iostream>
#include <string>

std::string say_os()
{
#ifdef IS_WINDOWS
    return std::string("This is Windows");
#elif IS_LINUX
    return std::string("This is Linux");
#elif IS_MACOS
    return std::string("This is Mac");
#else
    return std::string("This is Unknown");
#endif
}
int main()
{
    std::cout<< say_os() << std::endl;
    return 0;
}