#include <iostream>
#include <cassert>
#include "smart_ptr.h"
using namespace std;

int main(){
    smart_ptr<int> empty;

    assert(empty.ref_count() == 0); //  when the default const is called, ref count should be nullptr


    cout << "All tests passed\n";
    return 0;
}