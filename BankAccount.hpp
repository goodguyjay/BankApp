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
    BankAccount();
    static BankAccount createAccount(unsigned int accNumber);
    void displayAccountInfo();
    bool verifyPin(unsigned int inputPin) const;
    void deposit(double depositValue);
    bool withdraw(double withdrawValue);
    //void deleteAccount(BankAccount *account); //TODO check if this is useful anyhow
    unsigned int getAccountNumber() const;
    unsigned int getPin(); //TODO check if this is useful anyhow
    string getAccountHolderName();
    //bool isAccountNumberValid(unsigned int accNumber);
    unsigned int matchAccountInfo(unsigned int userInput);
    //unsigned int matchAccount();
};
