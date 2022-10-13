template < typename T >
class smart_ptr{
    public:
        smart_ptr(){
            this->ptr_ = nullptr;
            this->ref_ = nullptr;
        }
        // Create a smart_ptr that is initialized to nullptr. The
        // reference count should be initialized to nullptr.

        explicit smart_ptr(T * raw_ptr){
            this->ptr_ = raw_ptr;
            this->ref_ =  1;
        }
        // Create a smart_ptr that is initialized to raw_ptr. The
        // reference count should be one. Make sure it points to
        // the same pointer as the raw_ptr.

        smart_ptr(const smart_ptr & rhs);
        // Copy construct a pointer from rhs. The reference count
        // should be incremented by one.
        
        smart_ptr(smart_ptr && rhs);
        // Move construct a pointer from rhs.
        
        smart_ptr & operator = (const smart_ptr & rhs);
        // This assignment should make a shallow copy of the
        // right-hand side's pointer data. The reference count
        // should be incremented as appropriate.
        
        smart_ptr & operator = (smart_ptr && rhs);
        // This move assignment should steal the right-hand side's
        // pointer data.

        bool clone(){
            if ((this->ptr_ == nullptr) || (this->ref_ == 1)){
                return false;
            }
            // TODO: Check that this function signature is correct
        }
        // If the smart_ptr is either nullptr or has a reference
        // count of one, this function will do nothing and return
        // false. Otherwise, the referred to object's reference
        // count will be decreased and a new deep copy of the
        // object will be created. This new copy will be the
        // object that this smart_ptr points and its reference
        // count will be one.

        int ref_count() const{
            return *this->ref_;
        }
        // Returns the reference count of the pointed to data.

        T & operator * ();
        // The dereference operator shall return a reference to
        // the referred object. Throws null_ptr_exception on
        // invalid access.
        
        T * operator -> ();
        // The arrow operator shall return the pointer ptr_.
        // Throws null_ptr_exception on invalid access.
        
        ~smart_ptr(){
            delete this->ptr_;
            delete this->ref_;
        } // deallocate all dynamic memory

    private:
        T * ptr_; // pointer to the referred object
        int * ref_; // pointer to a reference count
};
