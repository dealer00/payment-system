#ifndef TRANSACTION_ADD_EMPLOYEE_TRANSACTION_HPP
#define TRANSACTION_ADD_EMPLOYEE_TRANSACTION_HPP

#include <string>
#include "core/Transaction.hpp"

class AddEmployeeTransaction: public Transaction {
public:
    AddEmployeeTransaction(int employeeId, std::string employeeName, std::string employeeAddress);
    virtual ~AddEmployeeTransaction() = 0;

    int getEmployeeId() const;

protected:
    int itsEmployeeId;
    std::string itsEmployeeName;
    std::string itsEmployeeAddress;
};

#endif
