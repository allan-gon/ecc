#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <exception>

class null_ptr_exception: public std::runtime_error{
    public:
        null_ptr_exception(const char* x): runtime_error(x){}
};

template < typename T >
class smart_ptr{
    public:
        smart_ptr(){
            // initialize ptr_ and ref_ to nullptr
            this->ptr_ = nullptr;
            this->ref_ = nullptr;
        }

        explicit smart_ptr(T* raw_ptr){
            // initialize ptr_ to raw_ptr and ref_ to 1
            this->ptr_ = raw_ptr;
            this->ref_ = new int { 1 };
        }

        smart_ptr(const smart_ptr & rhs){
            // if not self copy constructing
            if (this != &rhs){
                // shallow copy the values and increment ref_
                this->ptr_ = rhs.ptr_;
                this->ref_ = rhs.ref_;
                (*this->ref_)++;
            }
            // otherwise do nothing
        }
        
        smart_ptr(smart_ptr && rhs){
            // Move construct a pointer from rhs.
            if (this != &rhs){ // if not aliased
                // take ownership from rhs and fix dangling pointer
                this->ptr_ = rhs.ptr_;
                this->ref_ = rhs.ref_;
                rhs.ptr_ = nullptr;
                rhs.ref_ = nullptr;
            }
        }
        
        smart_ptr & operator = (const smart_ptr & rhs){
            // createsa shallow copy and decrements count before copying
            if (this == &rhs){ // handles aliasing
                return *this;
            }
            else if (this->ref_ == nullptr){ // if empty pointer
                // no need to delete anything or decrement the count
            }
            else if (*this->ref_ == 1){ // if this is the only shared ptr
                // de-alloc memory and fix dangling pointer
                delete this->ptr_;
                delete this->ref_;
                this->ptr_ = nullptr; // i think i dont need these 2 lines
                this->ref_ = nullptr;
            }
            else if (*this->ref_ > 0){ // if not the only shared ptr
                (*this->ref_)--; // decrement the count is sufficient
            }
            // shallow copy values and increment ref_
            this->ptr_ = rhs.ptr_;
            this->ref_ = rhs.ref_;
            (*this->ref_)++;
            return *this;
        }
        
        smart_ptr & operator = (smart_ptr && rhs){
            // steal the right-hand side's pointer data.
            if (this == &rhs){ // handles aliasing
                return *this;
            }
            else if (*this->ref_ == 1){ // if final ptr
                // de-alloc memory and fix dangling pointer
                delete this->ptr_;
                delete this->ref_;
                this->ptr_ = nullptr;
                this->ref_ = nullptr;
            }
            else{
                (*this->ref_)--; // if not the only ptr then decrement the count
            }
            // steal the values and reset the stolen from ptr
            this->ptr_ = rhs.ptr_;
            this->ref_ = rhs.ref_;
            rhs.ptr_ = nullptr;
            rhs.ref_ = nullptr;
            return *this;
        }

        bool clone(){
            // for an existing pointer, create new pointer which has a deep copy of
            // the value.
            if ((this->ptr_ == nullptr) || (*this->ref_ == 1)){ // dont clone if empty or only ptr
                return false;
            }
            // if full and more than one ptr
            (*this->ref_)--; // decrement the count
            this->ptr_ = new T {*this->ptr_}; // make a deep copy of the value
            this->ref_ = new int {1}; // set new count to 1
            return true;
        }

        int ref_count() const{
            // Returns the reference count of the pointed to data.
            if (this->ref_ == nullptr){ // if empty
                throw null_ptr_exception("Ref count is nullptr");
            }
            return *this->ref_;
        }

        T & operator * (){
            // return a reference to the value
            if (this->ptr_ == nullptr){ // if empty
                throw null_ptr_exception("Pointer is nullptr");
            }
            return *this->ptr_;
        }
        
        T * operator -> (){
            // return the pointer ptr_
            if (this->ptr_ == nullptr){ // if empty
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
        
        ~smart_ptr(){
            if ((this->ptr_ == nullptr) && (this->ref_ == nullptr)){ // destroyed but not hanging
                // do nothing. neccessary cond so decrem doesn't happen. would cause undefined behavior
            }
            else if (*this->ref_ == 1){ // the final ptr
                // de-alloc + fix dangling
                delete this->ptr_;
                delete this->ref_;
                this->ptr_ = nullptr;
                this->ref_ = nullptr;
            } else { // not final ptr
                // dont really do anything just reflect it in count
                (*this->ref_)--;
            }
        }

    private:
        T * ptr_; // pointer to the referred object
        int * ref_; // pointer to a reference count
};

#endif
