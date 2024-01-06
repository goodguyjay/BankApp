#include "BankAccount.hpp"

BankAccount::BankAccount() = default;

BankAccount::BankAccount(std::string accountHolderName, unsigned int pin, unsigned int accountNumber,
                         double accountBalance = 0) {
    this->accountHolderName = std::move(accountHolderName);
    this->pin = pin;
    this->accountNumber = accountNumber;
    this->accountBalance = accountBalance;
}

/*BankAccount BankAccount::createAccount(BankAccount *fakeAccount, unsigned int accNumber) {
    string name;
    unsigned int temp_pin;
    cout << "All right! We'll need your name to start: ";
    cin >> name;

    cout << endl;

    cout << "Okay! Now please type your password (4 numbers): ";
    cin >> temp_pin;

    fakeAccount = new BankAccount(name, temp_pin, accNumber, 0);

    cout << "All done! You account number is " << accNumber << endl;
    cout << "You can enter with your account number and pin." << endl;
    cout << "Thanks for choosing FakeBank! (not a scam)" << endl;

    cout << endl;

    return *fakeAccount;
}*/

BankAccount BankAccount::createAccount(unsigned int accNumber) {
    string name;
    unsigned int temp_pin;
    cout << "All right! We'll need your name to start: ";
    cin.ignore();
    getline(cin, name);


    cout << endl;

    cout << "Okay! Now please type your password (4 numbers): ";
    cin >> temp_pin;

    BankAccount tempAccount(name, temp_pin, accNumber, 0);

    cout << "All done! You account number is " << accNumber << endl;
    cout << "You can enter with your account number and pin." << endl;
    cout << "Thanks for choosing FakeBank! (not a scam)" << endl;

    cout << endl;

    return tempAccount;
}

void BankAccount::displayAccountInfo() {
    cout << "----------------" << endl;
    cout << "Account number: " << this->accountNumber << endl;
    cout << "Name: " << this->accountHolderName <<endl;
    cout << "Balance: " << this->accountBalance << endl;
    cout << "----------------" << endl;
}

unsigned int BankAccount::getPin() {
    return this->pin;
}

string BankAccount::getAccountHolderName() {
    return accountHolderName;
}

unsigned int BankAccount::getAccountNumber() const {
    return accountNumber;
}

bool BankAccount::verifyPin(unsigned int inputPin) const {
    if(this->pin == inputPin) {
        return true;
    }
    return false;
}

void BankAccount::deposit(double depositValue) {
    while(depositValue <= 0) {
        cout << "Invalid value! Please try again." << endl;
        cout << "U$";
        cin >> depositValue;
    }
    this->accountBalance += depositValue;
}

bool BankAccount::withdraw(double withdrawValue) {
    if (this->accountBalance < withdrawValue) {
        cout << "There's not enough currency in your account." << endl;
        return false;
    }
    this->accountBalance -= withdrawValue;
    return true;
}

/*
void BankAccount::deleteAccount(BankAccount *account) {
    delete account;
}
*/

/*bool BankAccount::isAccountNumberValid(unsigned int accNumber) {
    // this is a fucking wackjob idea but it'll work i promise
    if(accNumber <= 9999 && accNumber >= 1000) {
        return true;
    }

    return false;
}*/

unsigned int BankAccount::matchAccountInfo(unsigned int userInput) const {
    for (int i = 0; i < 3; i++) {
        if (this->getAccountNumber() != userInput) {
            cout << "[" << i + 1 << "] "
            << "Sorry! No account matching that number was found. Please try again!" << endl;
            cin >> userInput;
        } else {
            return userInput;
        }
    }
    return false;
}
