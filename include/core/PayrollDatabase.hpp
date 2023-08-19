#ifndef CORE_PAYROLL_DATABASE_HPP
#define CORE_PAYROLL_DATABASE_HPP

#include <map>
#include "Employee.hpp"

class PayrollDatabase {
public:
    void addEmployee(int empId, Employee* employee);
    Employee* getEmployee(int empId);
    void clear();

private:
    std::map<int, Employee*> itsEmployees;
};

extern PayrollDatabase GPayrollDatabase;

#endif
