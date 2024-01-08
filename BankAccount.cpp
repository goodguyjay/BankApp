#include "BankAccount.hpp"

unsigned int BankAccount::accountGenerator = 1;

BankAccount::BankAccount() = default;

BankAccount::BankAccount(std::string accountHolderName, unsigned int pin, unsigned int accountNumber,
                         double accountBalance = 0) {
    this->accountHolderName = std::move(accountHolderName);
    this->pin = pin;
    this->accountNumber = accountNumber;
    this->accountBalance = accountBalance;
}

BankAccount BankAccount::createAccount() {
    string name;
    unsigned int pin = 0;
    cout << "All right! We'll need your first name to start: ";
    cin.ignore();
    getline(cin, name);
    cout << endl;

    cout << "Okay! Now please type your password (4 numbers): ";
    cin >> pin;

//TODO FIX THIS PLEASE DEAR GOD
/*    while(pin > 9999 || pin <= 0) {
        cout << "This password is not permitted. Please type a valid password with 4 numbers." << endl;
        cout << "New password: ";
        cin.ignore();
        pin = 0;
        cin >> pin;
    }*/

    BankAccount account(name, pin, BankAccount::getAccountGenerator(), 0);

    cout << "All done! You account number is " << account.getAccountNumber() << endl;
    cout << "You can enter with your account number and pin." << endl;
    cout << "Thanks for choosing FakeBank! (not a scam)" << endl;

    cout << endl;
    return account;
}

void BankAccount::displayAccountInfo() {
    cout << "----------------" << endl;
    cout << "Account number: " << this->accountNumber << endl;
    cout << "Name: " << this->accountHolderName <<endl;
    cout << "Balance: " << this->accountBalance << endl;
    cout << "----------------" << endl;
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

unsigned int BankAccount::matchAccountInfo(unsigned int userInput) const {
    // TODO PROHIBIT CHARACTERS
    for (int i = 0; i < 3; i++) {
        if (getAccountNumber() != userInput) {
            cout << "[" << i + 1 << "] "
            << "Sorry! No account matching that number was found. Please try again!" << endl;
            cin.ignore();
            userInput = 0;
            cin >> userInput;
        } else {
            return userInput;
        }
    }
    return false;
}

// TODO PROHIBIT CHARACTERS
bool BankAccount::isAccountNumberValid(unsigned int &accNumber) {

    if (accNumber == 0) {
        return false;
    }

    int i = 0;

    while ((accNumber >= BankAccount::getAccountGenerator()) || (accNumber > 9999)) {
        cout << "["<< i + 1 << "] " << "This account do not exist. Please try again." << endl;
        cin.ignore();
        accNumber = 0;
        cin >> accNumber;
        i++;

        if (accNumber == 0) {
            return false;
        }

        if (i == 3) {
            cout << "Too many number of attempts. Please try again later." << endl;
            return false;
        }
    }

    return true;
}

unsigned int BankAccount::getAccountGenerator() {
    return accountGenerator;
}

void BankAccount::incrementAccountGenerator() {
    BankAccount::accountGenerator++;
}

// TODO PROHIBIT CHARACTERS
bool BankAccount::isPasswordValid(unsigned int &inputPin) const {
    if(inputPin == 0) {
        return false;
    }

    unsigned int i = 0;
    while ((!this->verifyPin(inputPin)) || (inputPin > 9999)) {
        cout << "["<< i + 1 << "] " << "The password do not match with this account. Please try again." << endl;
        cin.ignore();
        inputPin = 0;
        cin >> inputPin;
        i++;

        if (i == 3) {
            cout << "Too many number of wrong attempts. Please try again later." << endl;
            return false;
        }
    }

    return true;
}
