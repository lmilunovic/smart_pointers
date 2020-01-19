#pragma once

#include <iostream>
namespace custom {

// TODO make it useable with std::unique_ptr<T>
template <typename T>
class debug_delete 
{

public:
    debug_delete (std::ostream& s = std::cerr) : os(s) { };

    void operator()(T* p) const
    {
        os << "Deleting unique_ptr" << std::endl; delete p;
    }

private:
    std:: ostream& os;
};

}