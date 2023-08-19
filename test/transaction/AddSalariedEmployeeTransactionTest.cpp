#include <gtest/gtest.h>
#include "core/Employee.hpp"
#include "core/PayrollDatabase.hpp"
#include "transaction/AddSalariedEmployeeTransaction.hpp"

TEST(AddSalariedEmployeeTransaction, execute)
{
    int empId = 1;

    AddSalariedEmployeeTransaction t(empId, "Bogdan", "Dom", 2500.00);

    t.execute();

    Employee* e = GPayrollDatabase.getEmployee(empId);

    if (e) {
        EXPECT_TRUE("Bogdan" == e->getName());
    } else {
        FAIL() << "Employee not exists!";
    }
}
