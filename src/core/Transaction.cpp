#include <iostream>
#include "core/Transaction.hpp"

Transaction::~Transaction()
{
    #ifdef DEBUG
    std::cout << "Transaction::~Transaction()" << std::endl;
    #endif
}
