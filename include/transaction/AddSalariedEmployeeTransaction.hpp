#ifndef TRANSACTION_ADD_SALARIED_EMPLOYEE_TRANSACTION_HPP
#define TRANSACTION_ADD_SALARIED_EMPLOYEE_TRANSACTION_HPP

#include <string>
#include "AddEmployeeTransaction.hpp"

class AddSalariedEmployeeTransaction: public AddEmployeeTransaction {
public:
    AddSalariedEmployeeTransaction(int empId, std::string name, std::string address, float salary);
    ~AddSalariedEmployeeTransaction();

    void execute();

private:
    float itsEmployeeSalary;
};

#endif
