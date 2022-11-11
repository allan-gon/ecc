#include <iostream>
#include <cassert>
#include "smart_ptr.h"
using namespace std;

struct Point { int x = 2; int y = -5; };

int main(){
    // NOTE: i dont think i can check if destruction actually happens in assignment operators
    // NOTE: for this code to work un-comment line 134-140
    // tests for default constuctor
    smart_ptr<int> sp1; // this pointer should have ptr_ and ref_ initialized to nullptr
    try{
        *sp1; // garbage code that tries to access ptr_, because it's nullptr should throw null_ptr_exception
    } catch (null_ptr_exception){
        assert(true); // garbage code that runs only if null_ptr_exception is caught
    }
    try{
        sp1.ref_count(); // garbage code that tries to access ref_
    } catch(null_ptr_exception){
        assert(true); // garbage code that only runs if null_ptr_exception is caught
    }

    // tests for explicit constructor
    int* a {new int {1}};
    smart_ptr<int> sp2(a);
    assert((*sp2 == *a) && (&*sp2 == a)); // checks that val is the same as a's value and that the adresses are also the same
    assert(sp2.ref_count() == 1); // checks that when explicitly constructed ref_ is one

    // tests for copy constructor
    int* b {new int {2}};
    smart_ptr<int> sp3(b);
    sp3 = sp3;
    // checks that when self copy constructing, nothing happens (ae. values stay nullptr)
    try{
        *sp3; // garbage code that tries to access ptr_, because it's nullptr should throw null_ptr_exception
    } catch (null_ptr_exception){
        assert(true); // garbage code that runs only if null_ptr_exception is caught
    }
    try{
        sp3.ref_count(); // garbage code that tries to access ref_
    } catch(null_ptr_exception){
        assert(true); // garbage code that only runs if null_ptr_exception is caught
    }
    int prev_ref_ = sp3.ref_count();
    auto sp4 = sp3;
    assert((*sp4 == *sp3) && (&*sp4 == &*sp3)); // checks that when copy constructing, the values and addresses of ptr_ are the same
    assert((sp4.ref_count() == sp3.ref_count()) && (sp4.ref_count() == 2)); // checks that when copy constructing, the values and addresses of ref_ are the same
    assert(sp4.ref_count() == prev_ref_ + 1); // checks that ref_ has been incremented

    // tests for move constructor
    int* c {new int {3}};
    smart_ptr<int> sp5(c);
    const int* ptr_address = sp5.get_val();
    const int* ref_address = sp5.get_count();
    smart_ptr<int> sp6 = std::move(sp5);
    assert((&*sp6 == ptr_address) && (*sp6 == 3)); // checks that when move constructing, value and address of ptr_ remain the same
    assert(sp5.get_val() != ptr_address); // checks that when move constructing, the moved pointer no longer points to where it used to
    assert((sp6.get_count() == ref_address) && (sp6.ref_count() == 1)); // checks that when move constructing, value and address of ref_ remain the same
    assert(sp5.get_count() != ref_address); // checks that when move constructing, the moved pointer no longer points to where it used to

    // tests for assignment operator
    int* d {new int {4}};
    smart_ptr<int> sp7(d);
    ptr_address = sp7.get_val();
    ref_address = sp7.get_count();
    sp7 = sp7;
    assert((sp7.get_val() == ptr_address) && (sp7.get_count() == ref_address)); // checks that when self re-assigning, addresess remain the same
    assert((*sp7.get_val() == 4) && (sp7.ref_count() == 1)); // checks that when self re-assigning, values also remain the same
    int* e {new int {5}};
    smart_ptr<int> sp8(e);
    prev_ref_ = sp7.ref_count();
    ptr_address = sp8.get_val();
    ref_address = sp8.get_count();
    sp8 = sp7;
    assert((sp8.get_val() != ptr_address) && (sp8.get_count() != ref_address)); // checks that when re-assigning, you point to a different place
    assert(sp8.ref_count() == prev_ref_ + 1); // checks that when re-assigning, ref_ in incremented
    int* f {new int {6}};
    smart_ptr<int> sp9(f);
    auto sp10 = sp9;
    prev_ref_ = sp9.ref_count();
    sp10 = sp8;
    assert(prev_ref_ == sp9.ref_count() + 1);// checks that when re-assigning, but not the last ptr, prev count is decremented

    // tests for move assignment operator
    int* g {new int {7}};
    int* h {new int {8}};
    smart_ptr<int> sp11(g);
    smart_ptr<int> sp12(h);
    ptr_address = sp11.get_val();
    ref_address = sp11.get_count();
    sp11 = std::move(sp11);
    assert((sp11.get_val() == ptr_address) && (*sp11.get_val() == 7)); // checks that when self move re-assigning, values and addresses stay the same
    assert((sp11.get_count() == ref_address) && (sp11.ref_count() == 1));
    auto sp13 = sp11;
    prev_ref_ = sp11.ref_count();
    sp13 = std::move(sp12);
    assert(sp11.ref_count() == prev_ref_ - 1); // checks that when move re-assigning and you're not the last pointer, count is decremented

    // tests for clone
    int* i {new int {9}};
    smart_ptr<int> sp14;
    assert(!sp14.clone()); // checks that cloning an empty ptr fails
    smart_ptr<int> sp15(i);
    assert(!sp15.clone()); // checks that cloning a pointer with ref_ = 1 fails
    auto sp16 = sp15;
    prev_ref_ = sp16.ref_count();
    ptr_address = sp16.get_val();
    ref_address = sp16.get_count();
    assert(sp16.clone()); // checks that when cloning a pointer with ref_ > 1 it passes
    assert(sp16.ref_count() == prev_ref_ - 1); // checks that the above line results ref_ is decremented
    assert((sp16.ref_count() == 1) && (sp16.get_val() != ptr_address) && (sp16.get_count() != ref_address) && (*sp16 == *sp15)); // check that line 107 results in a ptr with ref_ = 1 and ptr_ point to diff place but same value

    tests for ref_count
    I THINK THIS ONES PRETTY STRAIGHT FORWARD

    tests for dereference operator
    I THINK THIS ONES PRETTY STRAIGHT FORWARD

    tests for arrow operator
    YOUR CODE TESTS THIS OR I DONT KNOW HOW TO TEST THIS

    tests for destructor
    TOO LAZY BUT would check for destructing empty ptr, single, ptr and > 1 ptr

    cout << "All tests passed\n";

    // NOTE: your tests should be run individually
    // your test code 1
    int* p { new int { 42 } };
    smart_ptr<int> sp1 { p };
    // Ref Count is 1
    cout << "Ref count is " << sp1.ref_count() << endl;
    {
        smart_ptr<int> sp2 { sp1 };
        // Ref Count is 2
        cout << "Ref count is " << sp1.ref_count() << endl;
        // Ref Count is 2
        cout << "Ref count is " << sp2.ref_count() << endl;
    }
    // Ref Count is 1
    cout << "Ref count is " << sp1.ref_count() << endl;

    smart_ptr<int> sp3;
    // Ref Count is 0
    cout << "Ref count is " << sp3.ref_count() << endl;

    sp3 = sp1;
    // Ref Count is 2
    cout << "Ref count is " << sp1.ref_count() << endl;
    // Ref Count is 2
    cout << "Ref count is " << sp3.ref_count() << endl;
    smart_ptr<int> sp4 = std::move(sp1);
    try{
        cout << *sp4 << " " << *sp3 << endl; // prints 42 42
        cout << *sp1 << endl; // throws null_ptr_exception
    }
    catch (null_ptr_exception){
        cout << "Exception caught\n";
    }

    // your test code 2
    smart_ptr<Point> sp { new Point };
    cout << sp->x << " " << sp->y << endl; // prints 2 -5

    // your test code 3
    smart_ptr<double> dsp1 { new double {3.14} };
    smart_ptr<double> dsp2, dsp3;

    dsp3 = dsp2 = dsp1;
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
