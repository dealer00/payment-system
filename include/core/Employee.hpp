#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include "PaymentClassification.hpp"
#include "PaymentMethod.hpp"
#include "PaymentSchedule.hpp"

class Employee {
    public:
        Employee(int, std::string, std::string);
        ~Employee();

        void setClassification(PaymentClassification* classification);
        void setSchedule(PaymentSchedule* schedule);
        void setPaymentMethod(PaymentMethod* method);

        int getId() const { return itsId; }
        std::string getName() const { return itsName; }
        std::string getAddress() const { return itsAddress; }

    private:
        int itsId;
        std::string itsName;
        std::string itsAddress;

        PaymentClassification* itsClassification;
        PaymentSchedule* itsPaymentSchedule;
        PaymentMethod* itsPaymentMethod;
};

#endif
