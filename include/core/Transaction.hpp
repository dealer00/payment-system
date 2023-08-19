#ifndef TRANSACTION_TRANSACTION_HPP
#define TRANSACTION_TRANSACTION_HPP

class Transaction {
public:
    virtual ~Transaction() = 0;

    virtual void execute() = 0;
};

#endif
