#include <iostream>
#include <cassert>
#include "smart_ptr.h"
using namespace std;

int main(){
    // checks that default constructor works as intended
    // smart_ptr<int> empty;
    // for thesethrow errors and catch them
    // assert(empty.ref_count() == 0); //  when the default const is called, ref count should be nullptr
    // assert(empty.get_val() == nullptr); // when default const is called, val is nullptr
    
    int* p { new int {42} };
    smart_ptr<int> sp1 {p};
    // checks that explicit constructor works as intended
    assert(sp1.ref_count() == 1); // when const from raw ptr, ref_count is 1
    assert(sp1.get_val() == p); // points to same value
    
    smart_ptr<int> sp2 = sp1;
    // checks that copy constructor works as intended
    assert(sp1.ref_count() == sp2.ref_count()); // checks that the count for sp1 and sp2 point to the same location
    assert(sp1.get_val() == sp2.get_val()); // checks that sp2 and sp1 data point to the same location

    int* n { new int {18}};
    smart_ptr<int>sp3 {n};
    sp3 = sp2;
    
    // checks that assignment operator works as intended
    // when assignment operator called on object with 1 ref_count, check that mem is released

    // HOW CAN I CHECK THAT VALUE IS DELETED WHEN COPY CONST CALLED

    cout << "All tests passed\n";
    return 0;
}

// for null_ptr_exception class, inherit from runtime error
// constructctor is necessary, other funcs are optional
// clone, smart_ptr<int> sp1 = 36;
// smart_ptr2<int> = sp1;
// smart_ptr3<int> = sp1;
// smart_ptr3.clone();
// now ref count for 1 an 2 is decremented and 3 points to
// a new piece of memory but same value and 3's count = 1
