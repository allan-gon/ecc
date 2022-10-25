#include <iostream>
#include <cassert>
#include "smart_ptr.h"
using namespace std;

int main(){
    // TODO: check for ailiasing

    // checks that default constructor works as intended
    smart_ptr<int> empty;
    try{
        assert(*empty);
    }
    catch(null_ptr_exception){
        assert(true); // checks that when pointer instatiated but not initialized ptr_ is nullptr
    }
    
    // checks that explicit constructor works as intended
    int* k { new int {42} };
    smart_ptr<int> sp1 {k};
    assert(*sp1.get_count() == 1); // checks that ref_ is set to 1 when instantiated from raw ptr 
    assert(sp1.get_val() == k); // checks that ptr_ instantiated by raw ptr points to same location as raw ptr
    
    // checks that copy constructor works as intended
    smart_ptr<int> sp2 = sp1;
    assert((sp1.get_count() == sp2.get_count()) && (*sp2.get_count() == 2)); // checks that ref_ for sp1 and sp2 are equal and point to the same location
    assert((sp1.get_val() == sp2.get_val()) && (*sp2.get_val() == 42)); // checks that ptr_ for sp1 and sp2 are equal and point to the same location

    // checks that move copy constructor works as intended
    // taking from a ptr with 1 ref
    int* l { new int {20} };
    smart_ptr<int> sp3 {l};
    const int* val_loc = sp3.get_val();
    const int* val_count = sp3.get_count();
    smart_ptr<int> sp4(std::move(sp3));

    assert((sp4.get_val() == val_loc) && (*sp4.get_val() == 20)); // check that sp4 ptr_ points to same location as sp3 pointed to and that ref_ is the same
    assert((sp4.get_count() == val_count) && (*sp4.get_count() == 1)); // checks that sp4 ref_ points to the same location as sp3 pointed to and that ref_ is the same
    // check that sp3 is now nullptr
    // taking from ptr with > 1 ref

    // checks that assignment operator works as intended
    int* m { new int {18}};
    smart_ptr<int>sp6 {m};
    val_loc = sp6.get_val();
    val_count = sp6.get_count();
    sp6 = sp2;
    // checks that when move self assignment, value stays the same
    // checks that when move self assignment, count stays the same
    assert(val_loc != sp6.get_val()); // checks that when var is re-assigned, var ptr_ points to a different location 
    assert(val_count != sp6.get_count()); // checks that when var is re-assigned, var red_
    assert((sp6.get_count() == sp2.get_count()) && (*sp2.get_count() == 3)); // checks that when var is re-assigned to var2, var and var2 share ptr_
    assert((sp6.get_val() == sp2.get_val()) && (*sp2.get_val() == 42)); // checks that when var is re-assigned to var2, var and var2 share ref_

    // checks that move assignment operator works
    int* n { new int {37}};
    smart_ptr<int>sp7 {n};
    sp7 = std::move(sp7);
    // assert(sp7 val not nullptr, same with count); // checks that move self assignmnent does not cause deletion  
    assert(*sp7.get_count() == 1); // checks that count is unchanged
    assert(*sp7.get_val() == 37); // checks thta value remain unchanged
    // should test when not self assignment

    // tests clone
    smart_ptr<int> sp8;
    assert(sp8.clone() == false); // checks that when val is nullptr clone works
    assert(sp7.clone() == false); // since sp7 only has 1 reference it should return false
    smart_ptr<int>sp9{new int {22}};
    auto sp10 = sp9;
    assert(sp10.clone() == true); // checks that clone returns true when possible
    assert(*sp9.get_count() == 1); // checks that cloning decremented the count
    assert(*sp10.get_count() == 1); // checks that count for clone is correctly initialized
    assert((sp9.get_count() != sp10.get_count()) && (sp10.get_val() != sp9.get_val())); // checks that the clone does not point to the same location
    assert(*sp10.get_val() == *sp9.get_val()); // checks that the values are the same but different pointer

    cout << "All tests passed\n";

    // your test code
    smart_ptr<double> dsp1 { new double {3.14} };
    smart_ptr<double> dsp2, dsp3;

    
    dsp3 = dsp2 = dsp1;
    
    cout << "got this far\n";
    
    cout << dsp1.ref_count() << " " << dsp2.ref_count() << " "
    << dsp3.ref_count() << endl; // prints 3 3 3
    // prints 3.14 3.14 3.14
    cout << *dsp1 << " " << *dsp2 << " " << *dsp3 << endl;
    dsp1.clone(); // returns true
    cout << dsp1.ref_count() << " " << dsp2.ref_count() << " "
    << dsp3.ref_count() << endl; // prints 1 2 2
    // prints 3.14 3.14 3.14
    cout << *dsp1 << " " << *dsp2 << " " << *dsp3 << endl;
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
