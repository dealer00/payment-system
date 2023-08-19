#include <iostream>
#include "core/Employee.hpp"
#include "core/Transaction.hpp"
#include "transaction/AddSalariedEmployeeTransaction.hpp"

using std::cout;
using std::endl;

void displayEmployee(const Employee& e);

int main()
{
    Employee e(1, "Sebastian", "Grójec");

    displayEmployee(e);

    Transaction* transaction = new AddSalariedEmployeeTransaction(1, e.getName(), e.getAddress(), 0.0);

    transaction->execute();

    delete transaction;

    return 0;
}

void displayEmployee(const Employee& e)
{
    cout << "Employee (id: " << e.getId() << ")\n"
        << "Name: " << e.getName() << "\n"
        << "Address: " << e.getAddress() << "\n"
        << "----------------" << endl
    ;
}
