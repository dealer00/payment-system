#include "core/Employee.hpp"
#include "core/PayrollDatabase.hpp"

PayrollDatabase GPayrollDatabase;

void PayrollDatabase::addEmployee(int empId, Employee* employee)
{
    itsEmployees[empId] = employee;
}

Employee* PayrollDatabase::getEmployee(int empId)
{
    return itsEmployees[empId];
}

void PayrollDatabase::clear()
{
    itsEmployees.clear();
}
