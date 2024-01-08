#pragma once
#include <iostream>
using std::string, std::cout, std::endl, std::cin;

class BankAccount {
private:
    string accountHolderName;
    unsigned int pin = 0000;
    unsigned int accountNumber = 0;
    double accountBalance = 0;
    static unsigned int accountGenerator;
public:
    BankAccount(string accountHolderName, unsigned int pin, unsigned int accountNumber, double accountBalance);
    BankAccount();
    static BankAccount createAccount();
    void displayAccountInfo();
    bool verifyPin(unsigned int inputPin) const;
    void deposit(double depositValue);
    bool withdraw(double withdrawValue);
    //void deleteAccount(BankAccount *account); //TODO check if this is useful anyhow
    unsigned int getAccountNumber() const;
    unsigned int getPin(); //TODO check if this is useful anyhow
    string getAccountHolderName();
    //bool isAccountNumberValid(unsigned int accNumber);
    unsigned int matchAccountInfo(unsigned int userInput) const ;
    static bool isAccountNumberValid(unsigned int &accNumber);
    //unsigned int matchAccount();
    static unsigned int getAccountGenerator();
    static void setAccountGenerator(unsigned int accountGenerator);

    static unsigned int setAccountNumber();

    static void incrementAccountGenerator();

    bool isPasswordValid(unsigned int &inputPin) const;
};

//unsigned int BankAccount::accountGenerator = 1;
