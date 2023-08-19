#include "core/Employee.hpp"

Employee::Employee(int empId, std::string name, std::string address):
    itsId(empId),
    itsName(name),
    itsAddress(address)
{
}

Employee::~Employee()
{
}

void Employee::setClassification(PaymentClassification* classification)
{
    itsClassification = classification;
}

void Employee::setSchedule(PaymentSchedule* schedule)
{
    itsPaymentSchedule = schedule;
}

void Employee::setPaymentMethod(PaymentMethod* method)
{
    itsPaymentMethod = method;
}
