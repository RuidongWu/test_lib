#include <iostream>
using namespace std;

#include "Top.h"

void hello::print() {
    cout << "Hello, World, every body!" << endl;
}

void add(int a, int b) {
    cout << a + b << endl;
}

int main(int argc, char *argv[]) {
    add(1, 2);
    cout << "Hello, World, every body!" << endl;
    return 0;
}