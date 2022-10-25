#include <exception>

class null_ptr_exception: public std::runtime_error{
    public:
        null_ptr_exception(const char* x): runtime_error(x){}
};

template < typename T >
class smart_ptr{
    public:
        smart_ptr(){
            // Create a smart_ptr that is initialized to nullptr. The
            // reference count should be initialized to nullptr.
            this->ptr_ = nullptr;
            this->ref_ = nullptr;
        }

        explicit smart_ptr(T* raw_ptr){
            // Create a smart_ptr that is initialized to raw_ptr. The
            // reference count should be one. Make sure it points to
            // the same pointer as the raw_ptr.
            this->ptr_ = raw_ptr;
            this->ref_ = new int { 1 };
        }

        smart_ptr(const smart_ptr & rhs){
            // Copy construct a pointer from rhs. The reference count
            // should be incremented by one.
            if (this != &rhs){ // if not aliased
                this->ptr_ = rhs.ptr_;
                this->ref_ = rhs.ref_;
                (*this->ref_)++;
            }
        }
        
        smart_ptr(smart_ptr && rhs){
            // Move construct a pointer from rhs.
            if (this != &rhs){ // if not aliased
                this->ptr_ = rhs.ptr_;
                this->ref_ = rhs.ref_;
                rhs.ptr_ = nullptr;
                rhs.ref_ = nullptr;
            }
        }
        
        smart_ptr & operator = (const smart_ptr & rhs){
            // This assignment should make a shallow copy of the
            // right-hand side's pointer data. The reference count
            // should be incremented as appropriate.
            if (this == &rhs){ // handles aliasing
                return *this;
            }
            else if (this->ref_ == nullptr){
                // pass
            }
            else if (*this->ref_ == 1){
                delete this->ptr_;
                delete this->ref_;
                this->ptr_ = nullptr;
                this->ref_ = nullptr;
            }
            else if (*this->ref_ > 0){
                (*this->ref_)--; // if not the only ptr then decrement the count
            }
            this->ptr_ = rhs.ptr_;
            this->ref_ = rhs.ref_;
            (*this->ref_)++;
            return *this;
        }
        
        smart_ptr & operator = (smart_ptr && rhs){
            // This move assignment should steal the right-hand side's
            // pointer data.
            if (this == &rhs){ // handles aliasing
                return *this;
            }
            else if (*this->ref_ == 1){
                delete this->ptr_;
                delete this->ref_;
                this->ptr_ = nullptr;
                this->ref_ = nullptr;
            }
            else{
                (*this->ref_)--; // if not the only ptr then decrement the count
            }
            this->ptr_ = rhs.ptr_;
            this->ref_ = rhs.ref_;
            rhs.ptr_ = nullptr;
            rhs.ref_ = nullptr;
            return *this;
        }

        bool clone(){
            // If the smart_ptr is either nullptr or has a reference
            // count of one, this function will do nothing and return
            // false. Otherwise, the referred to object's reference
            // count will be decreased and a new deep copy of the
            // object will be created. This new copy will be the
            // object that this smart_ptr points and its reference
            // count will be one.
            if ((this->ptr_ == nullptr) || (*this->ref_ == 1)){
                return false;
            }
            (*this->ref_)--;
            this->ptr_ = new T {*this->ptr_};
            this->ref_ = new int {1};
            return true;
        }

        int ref_count() const{
            // Returns the reference count of the pointed to data.
            if (this->ref_ == nullptr){
                // throw stdexcept;
            }
            return *this->ref_;
        }

        T & operator * (){
            // The dereference operator shall return a reference to
            // the referred object. Throws null_ptr_exception on
            // invalid access.
            if (this->ptr_ == nullptr){
                throw null_ptr_exception("Pointer is nullptr");
            }
            return *this->ptr_; // this line was this->*ptr; causes error
        }
        
        T * operator -> (){
            // The arrow operator shall return the pointer ptr_.
            // Throws null_ptr_exception on invalid access.
            if (this->ptr_ == nullptr){
                throw null_ptr_exception("Pointer was nullptr");
            }
            return this->ptr_;
        }

        const T* get_val(){
            if (this->ptr_ == nullptr){
                // throw stdexcept;
            }
            return this->ptr_;
        }

        const int* get_count(){
            if (this->ref_ == nullptr){
                // throw stdexcept
            }
            return this->ref_;
        }
        
        ~smart_ptr(){
            if ((this->ptr_ == nullptr) && (this->ref_ == nullptr)){ // destroyed but not hanging
                // do nothing. neccessary cond so decrem doesn't happen. would cause undefined behavior
            }
            else if (*this->ref_ == 1){ // the final ptr
                // de-alloc + fiz hanging
                delete this->ptr_;
                delete this->ref_;
                this->ptr_ = nullptr;
                this->ref_ = nullptr;
            } else { // not final ptr
                // dont really do anything just reflect it in count
                (*this->ref_)--;
            }
        } // deallocate all dynamic memory

    private:
        T * ptr_; // pointer to the referred object
        int * ref_; // pointer to a reference count
};
