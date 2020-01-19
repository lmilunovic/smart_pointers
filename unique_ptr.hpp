#pragma once

#include "debug_delete.hpp"

namespace custom {

// TODO typedefs for element_type and deleter_type
template <typename T, typename Deleter = custom::debug_delete<T>>
class unique_ptr {

public:

    explicit unique_ptr() : pointer(nullptr) { }
    explicit unique_ptr(T* t) : pointer(t) { }
    explicit unique_ptr(T* t, Deleter d) : pointer(t), deleter(d) { }

    ~unique_ptr(){
        deleter(pointer);
    }

    void reset(T* ptr = nullptr) { 
        deleter(ptr);
        pointer = ptr;
    }

    unique_ptr(const unique_ptr& other) = delete;
    unique_ptr& operator=(const unique_ptr& other) = delete;
    
    // TODO handle deleter too
    unique_ptr(unique_ptr&& u) {
       *this = std::move(u);
    }   
   
    unique_ptr& operator=(unique_ptr&& other) {
        this->swap(other);
        return *this;
    }    

    T* release(){
        T* p = pointer;
        pointer = nullptr;
        return p;
    }

    // TODO handle deleter too
    void swap(unique_ptr& other) {
        std::swap(this->pointer, other.pointer);
    }

    T* get() const { return pointer; }

    Deleter get_deleter() const { return deleter; }

    bool empty() const { return !pointer; }

    T* operator->() const {
        return pointer;
    }

    T operator*() const {
        return *pointer;
    }

private: 
    T* pointer;
    Deleter deleter;

};

}
