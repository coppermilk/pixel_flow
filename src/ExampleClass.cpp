#include "ExampleClass.h"
#include <iostream>

using namespace std;

int ExampleClass::doSomething() {
    cout << "Did something" << endl;
    return 1;
}
int ExampleClass::sum(int a, int b) {
	return a + b;
}
