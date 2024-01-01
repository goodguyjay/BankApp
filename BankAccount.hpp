#pragma once
#include <iostream>
using std::string, std::cout, std::endl, std::cin;

class BankAccount {
private:
    string accountHolderName;
    unsigned int pin = 0000;
    unsigned int accountNumber = 0;
    double accountBalance = 0;

public:
    BankAccount(string accountHolderName, unsigned int pin, unsigned int accountNumber, double accountBalance);
    static void createAccount(BankAccount *fakeAccount, unsigned int accNumber);
    void displayAccountInfo();
    //void displayAccountFunds(unsigned int accNumber,unsigned int pin); TODO LATER
    bool verifyPin(unsigned int inputPin);
    void deposit(double depositValue);
    bool withdraw(double withdrawValue);
    void deleteAccount(BankAccount *account);
    unsigned int getAccountNumber() const;
    unsigned int getPin();
    string getAccountHolderName();
    bool isAccountNumberValid(unsigned int accNumber);
    //unsigned int matchAccount();
};
