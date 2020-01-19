#include <atomic>

namespace custom {

template <typename T>
class shared_ptr {

public:

    explicit shared_ptr() : pointer(nullptr) {}

    explicit shared_ptr(T* t) : pointer(t), reference_counter(1)  {}

private:

    T* pointer;

    std::atomic_size_t reference_counter;

};

}