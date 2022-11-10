#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <exception>

class null_ptr_exception : public std::runtime_error
{
public:
    null_ptr_exception(const char *x) : runtime_error(x) {}
};

template <typename T>
class smart_ptr
{
public:
    smart_ptr() noexcept
    {
        // initialize ptr_ and ref_ to nullptr
        this->ptr_ = nullptr;
        this->ref_ = nullptr;
    }

    explicit smart_ptr(T *raw_ptr) noexcept
    {
        // initialize ptr_ to raw_ptr and ref_ to 1
        this->ptr_ = raw_ptr;
        this->ref_ = new int{1};
    }

    smart_ptr(const smart_ptr &rhs) noexcept
    {
        // if not self copy constructing
        if (this != &rhs)
        {
            // shallow copy the values and increment ref_
            this->ptr_ = rhs.ptr_;
            this->ref_ = rhs.ref_;
            (*this->ref_)++;
        }
        // otherwise do nothing
    }

    smart_ptr(smart_ptr &&rhs) noexcept
    {
        // Move construct a pointer from rhs.
        if (this != &rhs)
        { // if not aliased
            // take ownership from rhs and fix dangling pointer
            this->ptr_ = rhs.ptr_;
            this->ref_ = rhs.ref_;
            rhs.ptr_ = nullptr;
            rhs.ref_ = nullptr;
        }
    }

    smart_ptr &operator=(const smart_ptr &rhs) noexcept
    {
        // creates a shallow copy and decrements count before copying
        if (this == &rhs)
        { // handles aliasing
            return *this;
        }
        else if (this->ref_ == nullptr)
        { // if empty pointer
          // no need to delete anything or decrement the count
        }
        else if (*this->ref_ == 1)
        { // if this is the only shared ptr
            // de-alloc memory and fix dangling pointer
            delete this->ptr_;
            delete this->ref_;
            this->ptr_ = nullptr; // i think i dont need these 2 lines
            this->ref_ = nullptr;
        }
        else if (*this->ref_ > 0)
        {                    // if not the only shared ptr
            (*this->ref_)--; // decrement the count is sufficient
        }
        // shallow copy values and increment ref_
        this->ptr_ = rhs.ptr_;
        this->ref_ = rhs.ref_;
        if (this->ref_ != nullptr)
        { // if copying from a non empty pointer, increment
            (*this->ref_)++;
        }
        return *this;
    }

    smart_ptr &operator=(smart_ptr &&rhs) noexcept
    {
        // steal the right-hand side's pointer data.
        if (this == &rhs)
        { // handles aliasing
            return *this;
        }
        else if (this->ref_ == nullptr)
        { // if empty
            // do nothing
        }
        else if (*this->ref_ == 1)
        { // if final ptr
            // de-alloc memory and fix dangling pointer
            delete this->ptr_;
            delete this->ref_;
            this->ptr_ = nullptr;
            this->ref_ = nullptr;
        }
        else
        {
            (*this->ref_)--; // if not the only ptr then decrement the count
        }
        // steal the values and reset the stolen from ptr
        this->ptr_ = rhs.ptr_;
        this->ref_ = rhs.ref_;
        rhs.ptr_ = nullptr;
        rhs.ref_ = nullptr;
        return *this;
    }

    bool clone()
    {
        // for an existing pointer, create new pointer which has a deep copy of
        // the value.
        if ((this->ptr_ == nullptr) || (*this->ref_ == 1))
        { // dont clone if empty or only ptr
            return false;
        }
        // if full and more than one ptr
        (*this->ref_)--;                 // decrement the count
        // strong exception bit
        T* temp_val;
        int* temp_count;
        try{
            temp_val = new T{*this->ptr_};
            temp_count = new int{1};
        } catch (std::bad_alloc){
            // delete temp_count;
            // delete temp_val;
            std::cout << "bad aloc caught\n";
            throw;
            }
        this->ptr_ = temp_val; // make a deep copy of the value
        this->ref_ = temp_count; // set new count to 1
        return true;
    }

    int ref_count() const noexcept
    {
        // Returns the reference count of the pointed to data.
        if (this->ref_ == nullptr)
        { // if empty
            return 0;
        }
        return *this->ref_;
    }

    T &operator*()
    {
        // return a reference to the value
        if (this->ptr_ == nullptr)
        { // if empty
            throw null_ptr_exception("Pointer is nullptr");
        }
        return *this->ptr_;
    }

    T *operator->()
    {
        // return the pointer ptr_
        if (this->ptr_ == nullptr)
        { // if empty
            std::cout << this->ptr_ << std::endl;
            throw null_ptr_exception("Pointer was nullptr");
        }
        return this->ptr_;
    }

    // const T* get_val(){
    //     return this->ptr_;
    // }

    // const int* get_count(){
    //     return this->ref_;
    // }

    ~smart_ptr()
    {
        if ((this->ptr_ == nullptr) && (this->ref_ == nullptr))
        { // destroyed but not hanging
          // do nothing. neccessary cond so decrem doesn't happen. would cause undefined behavior
        }
        else if (*this->ref_ == 1)
        { // the final ptr
            // de-alloc + fix dangling
            delete this->ptr_;
            delete this->ref_;
            this->ptr_ = nullptr;
            this->ref_ = nullptr;
        }
        else
        { // not final ptr
            // dont really do anything just reflect it in count
            (*this->ref_)--;
        }
    }

private:
    T *ptr_;   // pointer to the referred object
    int *ref_; // pointer to a reference count
};

#include <stdexcept>
#include <new>
#include <set>
#include <iostream>
#include <cassert>
using namespace std;
struct OurType
{
    explicit OurType(int v = 0) : m_value(v) { m_count++; }
    OurType(const OurType &other) : m_value(other.m_value)
    {
        m_count++;
        m_asstcopycount++;
    }
    ~OurType() { m_count--; }
    OurType &operator=(const OurType &rhs)
    {
        m_value = rhs.m_value;
        m_asstcopycount++;
        return *this;
    }
    int m_value;
    static int m_count;
    static int m_asstcopycount;
};
inline bool operator==(const OurType &lhs, const OurType &rhs)
{
    return lhs.m_value == rhs.m_value;
}
inline bool operator<(const OurType &lhs, const OurType &rhs)
{
    return lhs.m_value < rhs.m_value;
}
inline bool operator!=(const OurType &lhs, const OurType &rhs)
{
    return !(lhs == rhs);
}
inline bool operator<=(const OurType &lhs, const OurType &rhs)
{
    return !(rhs < lhs);
}
inline bool operator>=(const OurType &lhs, const OurType &rhs)
{
    return !(lhs < rhs);
}
inline bool operator>(const OurType &lhs, const OurType &rhs)
{
    return rhs < lhs;
}
inline bool operator==(const OurType &lhs, int rhs)
{
    return lhs.m_value == rhs;
}
inline bool operator!=(const OurType &lhs, int rhs)
{
    return !(lhs == rhs);
}
#include <iostream>
inline std::ostream &operator<<(std::ostream &lhs, const OurType &rhs)
{
    return lhs << rhs.m_value;
}
int OurType::m_count = 0;
int OurType::m_asstcopycount = 0;
inline int itemcount()
{
    return OurType::m_count;
}
inline int nasstcopys()
{
    return OurType::m_asstcopycount;
}
std::set<void *> addrs;
bool recordaddrs = false;
int throwBadAlloc = 0;
// value of 0 means allocations don't throw
// value of 1 means 1st allocation throws
// value of 2 means 2nd allocation throws
// value of n means nth allocation throws
void *operator new(size_t n)
{
    std::cout << "Called new\n";
    if (recordaddrs)
    {
        if (throwBadAlloc == 1)
            throw std::bad_alloc();
        else if (throwBadAlloc > 1)
            throwBadAlloc--;
    }
    void *p = malloc(n);
    if (recordaddrs)
    {
        recordaddrs = false;
        addrs.insert(p);
        recordaddrs = true;
    }
    return p;
}
void operator delete(void *p) noexcept
{
    std::cout << "Called delete\n";
    if (recordaddrs)
    {
        recordaddrs = false;
        std::set<void *>::iterator it = addrs.find(p);
        if (it != addrs.end())
            addrs.erase(it);
        recordaddrs = true;
    }
    free(p);
}
void testone(int n)
{
    smart_ptr<double> dsp0;
    smart_ptr<double> dsp1{new double{3.14}};
    smart_ptr<double> dsp2, dsp3;
    switch (n)
    {
    default:
    {
        assert(false);
    }
    break;
    case 1:
    {
        assert(dsp0.ref_count() == 0);
    }
    break;
    case 2:
    {
        assert(dsp1.ref_count() == 1);
    }
    break;
    case 3:
    {
        dsp0 = dsp1;
        assert(dsp0.ref_count() == 2);
    }
    break;
    case 4:
    {
        dsp3 = dsp2 = dsp1;
        assert(dsp3.ref_count() == dsp2.ref_count() &&
               dsp1.ref_count() == dsp2.ref_count() &&
               dsp1.ref_count() == 3);
    }
    break;
    case 5:
    {
        dsp1 = dsp0;
        // assignment doesn't fail, what does
        assert(dsp1.ref_count() == 0 && dsp0.ref_count() == 0);
    }
    break;
    case 6:
    {
        assert(std::is_nothrow_constructible<smart_ptr<int>>::value);
        assert(std::is_nothrow_copy_constructible<smart_ptr<int>>::value);
        // possible XCode compiler bug for following two asserts
        // assert(std::is_nothrow_constructible<smart_ptr<int>,int*>::value);
        // assert(std::is_nothrow_assignable<A,A>::value);
        assert(std::is_nothrow_move_assignable<smart_ptr<int>>::value);
        assert(std::is_nothrow_move_constructible<smart_ptr<int>>::value);
        assert(!noexcept(std::declval<smart_ptr<int>>().clone()));
        assert(!noexcept(std::declval<smart_ptr<int>>().operator*()));
        assert(!noexcept(std::declval<smart_ptr<int>>().operator->()));
        assert(noexcept(std::declval<smart_ptr<int>>().ref_count()));
    }
    break;
    case 7:
    {
        {
            // testing constructor
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 8:
    {
        {
            // testing assignment operator
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1;
            osp1 = osp0;
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 9:
    {
        {
            // testing copy constructor
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1{osp0};
            assert(osp0.ref_count() == 2);
            assert(osp1.ref_count() == 2);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 10:
    {
        {
            // testing move constructor
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1{std::move(osp0)};
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 11:
    {
        {
            // testing move assignment
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(osp0.ref_count() == 1);
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1;
            osp1 = std::move(osp0);
            assert(osp1.ref_count() == 1);
            assert(osp0.ref_count() == 0);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 12:
    {
        {
            // testing move constructor
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(osp0.ref_count() == 1);
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1{std::move(osp0)};
            assert(osp1.ref_count() == 1);
            assert(osp0.ref_count() == 0);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 13:
    {
        {
            // testing move assignment
            smart_ptr<OurType> osp0{new OurType{0}};
            assert(osp0.ref_count() == 1);
            assert(itemcount() == 1);
            smart_ptr<OurType> osp1;
            osp1 = std::move(osp0);
            assert(osp1.ref_count() == 1);
            assert(osp0.ref_count() == 0);
            assert(itemcount() == 1);
        }
        assert(itemcount() == 0);
    }
    break;
    case 14:
    {
        {
            // testing assignment operator
            smart_ptr<OurType> osp0;
            assert(itemcount() == 0);
            smart_ptr<OurType> osp1;
            osp1 = osp0;
            assert(itemcount() == 0);
        }
        assert(itemcount() == 0);
    }
    break;
    case 15:
    {
        try
        {
            *dsp0;
            assert(0);
        }
        catch (...)
        {
        }
    }
    break;
    case 16:
    {
        smart_ptr<OurType> osp{new OurType{42}};
        try
        {
            assert((*osp).m_value == 42);
        }
        catch (...)
        {
            assert(0);
        }
    }
    break;
    case 17:
    {
        smart_ptr<OurType> osp;
        try
        {
            (*osp).m_value; // should throw
            assert(0);
        }
        catch (...)
        {
        }
    }
    break;
    case 18:
    {
        smart_ptr<OurType> osp{new OurType{42}};
        try
        {
            assert(osp->m_value == 42);
        }
        catch (...)
        {
            assert(0);
        }
    }
    break;
    case 19:
    {
        smart_ptr<OurType> osp;
        try
        {
            osp->m_value; // should throw
            assert(0);
        }
        catch (...)
        {
        }
    }
    break;
    case 20:
    {
        assert(!dsp0.clone());
        assert(!dsp1.clone());
    }
    break;
    case 21:
    {
        dsp3 = dsp2 = dsp1;
        assert(dsp1.clone());
        assert(dsp1.ref_count() == 1 && dsp2.ref_count() == 2 &&
               dsp3.ref_count() == 2);
        assert(*dsp1 == 3.14 && *dsp2 == 3.14 && *dsp3 == 3.14);
    }
    break;
    case 22:
    {
        dsp3 = dsp2 = dsp1;
        recordaddrs = true;
        throwBadAlloc = 1; // first allocation throws exception
        size_t oldSize = addrs.size();
        try
        {
            dsp1.clone();
            assert(0);
        }
        catch (std::bad_alloc)
        {
        }
        // test for strong guarantee, no change to dsp1
        assert(*dsp1 == *dsp2 && dsp1.ref_count() == dsp2.ref_count());
        assert(addrs.size() == oldSize);
        recordaddrs = false;
    }
    break;
    case 23:
    {
        // 2, 3 empty, 1 points to something
        // adress is a global void* set
        dsp3 = dsp2 = dsp1;
        recordaddrs = true;
        throwBadAlloc = 2; // second allocation throws exception
        size_t oldSize = addrs.size();

        try
        {
            dsp1.clone();
            assert(0);
        }
        catch (std::bad_alloc)
        {
        }
        // test for strong guarantee, no change to dsp1
        assert(*dsp1 == *dsp2 && dsp1.ref_count() == dsp2.ref_count());
        assert(addrs.size() == oldSize);
        recordaddrs = false;
    }
    break;
    case 24:
    {
        dsp3 = dsp2 = dsp1;
        assert(*dsp1 == *dsp2 && *dsp2 == *dsp3 && *dsp1 == 3.14);
        assert(dsp1.ref_count() == dsp2.ref_count() &&
               dsp2.ref_count() == dsp3.ref_count() &&
               dsp1.ref_count() == 3);
    }
    break;
    case 25:
    {
        dsp3 = dsp2 = dsp1;
        dsp3 = dsp0;
        assert(*dsp1 == *dsp2 && *dsp1 == 3.14);
        assert(dsp1.ref_count() == dsp2.ref_count() &&
               dsp1.ref_count() == 2 &&
               dsp3.ref_count() == 0);
    }
    }
}
int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
}

#endif
