#include <iostream>
using namespace std;
// till now we were using ths namespace only
// today we will see we can even change it

namespace ayush {
    void sayName() {
        cout << "Ayush" << endl;
    }
}

namespace raina {
    void sayName2() {
        cout << "Raina" << endl;
    }
}

// -> write which namespace want to use
using namespace raina;
void temp_func() {
    sayName2();
    return;
}

// -> here just write which name space you want to include
using namespace ayush;
int main() {

    sayName();
    temp_func();

    // another way to print 
    ayush::sayName();
    raina::sayName2();
}