#include <iostream>
#include "core/Employee.hpp"
#include "core/PayrollDatabase.hpp"
#include "transaction/AddSalariedEmployeeTransaction.hpp"

AddSalariedEmployeeTransaction::AddSalariedEmployeeTransaction(int empId, std::string name, std::string address, float salary):
    AddEmployeeTransaction(empId, name, address),
    itsEmployeeSalary(salary)
{
}

AddSalariedEmployeeTransaction::~AddSalariedEmployeeTransaction()
{
    #ifdef DEBUG
    std::cout << "AddSalariedEmployee::~AddSalariedEmployee()" << std::endl;
    #endif
}

void AddSalariedEmployeeTransaction::execute()
{
    Employee* e = new Employee(getEmployeeId(), itsEmployeeName, itsEmployeeAddress);

    GPayrollDatabase.addEmployee(getEmployeeId(), e);
}
