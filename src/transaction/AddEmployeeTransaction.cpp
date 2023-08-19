#include <iostream>
#include "transaction/AddEmployeeTransaction.hpp"

AddEmployeeTransaction::AddEmployeeTransaction(int employeeId, std::string employeeName, std::string employeeAddress):
    itsEmployeeId(employeeId),
    itsEmployeeName(employeeName),
    itsEmployeeAddress(employeeAddress)
{
}

AddEmployeeTransaction::~AddEmployeeTransaction()
{
    #ifdef DEBUG
    std::cout << "AddEmployeeTransaction::~AddEmployeeTransaction()" << std::endl;
    #endif
}

int AddEmployeeTransaction::getEmployeeId() const {
    return itsEmployeeId;
}
