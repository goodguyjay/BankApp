#include "BankAccount.hpp"

void clearScreen() { std::cout << "\x1B[2J\x1B[H"; };

void clearMemory(BankAccount *fakeBankAccounts[]) {
    for (int i = 0; i < 500; i ++) {
        delete fakeBankAccounts[i];
    }

    delete[] fakeBankAccounts;
}

unsigned int authentication(BankAccount **fakeBankAccounts, unsigned int &accNumber) {
    unsigned int password;
    cout << "All right! Please type in your account number (Type 0 to leave this menu): ";
    cin >> accNumber;

    if (!BankAccount::isAccountNumberValid(accNumber)) {
        return 1;
    }

    if (!fakeBankAccounts[accNumber]->matchAccountInfo(accNumber)) {
        cout << "Too many number of attempts. Please try again later." << endl;
        return 1;
    }

    clearScreen();

    cout << "Hello " << fakeBankAccounts[accNumber]->getAccountHolderName() << " !"<< endl;
    cout << "Type in your password: ";
    cin >> password;

    if (!fakeBankAccounts[accNumber]->isPasswordValid(password)) {
        cout << "Too many number of attempts. Please try again later.";
        return 1;
    }

    return accNumber;
}

int main() {

    int choice = 0;
    unsigned int accNumber = 1;
    unsigned int password = 0;
    double amount = 0;
    int i;

    auto **fakeBankAccounts = new BankAccount *[500];
    for (i = 0; i < 500; i++) {
        fakeBankAccounts[i] = nullptr;
    }

    cout << "Hi! Welcome to FakeBank(not a scam)." << endl;
    cout << "How may i help you?" << endl;

    do {
        cout << "----------------------------------" << endl;
        cout << "[1]I would like to open a account." << endl;
        cout << "[2]I would like to see my funds." << endl;
        cout << "[3]I would like to deposit funds into my account." << endl;
        cout << "[4]I would like to withdraw funds from my account." << endl;
        cout << "[5]I would like to delete my account." << endl;
        cout << "[0]Leave" << endl;
        cin >> choice;
        clearScreen();

        switch(choice) {
            case 1: {
                auto *fakeAccount = new BankAccount();
                *fakeAccount = BankAccount::createAccount();
                accNumber = BankAccount::getAccountGenerator();
                fakeBankAccounts[accNumber] = fakeAccount;

                clearScreen();

                fakeBankAccounts[accNumber]->displayAccountInfo();
                BankAccount::incrementAccountGenerator();
                break;
            }

            case 2: {
                if(authentication(fakeBankAccounts, accNumber) == 1) {
                    break;
                }
                fakeBankAccounts[accNumber]->displayAccountInfo();

                break;
            }

            case 3: {
                if(authentication(fakeBankAccounts, accNumber) == 1) {
                    break;
                }

                cout << "Alright, " << fakeBankAccounts[accNumber]->getAccountHolderName() << endl;
                cout << "How much you want to deposit?" << endl;
                cout << "U$";
                cin >> amount;
                fakeBankAccounts[accNumber]->deposit(amount);

                fakeBankAccounts[accNumber]->displayAccountInfo();
                amount = 0;
                break;
            }

            case 4: {
                if(authentication(fakeBankAccounts, accNumber) == 1) {
                    break;
                }

                clearScreen();

                cout << "Hello " << fakeBankAccounts[accNumber]->getAccountHolderName() << " !" << endl;
                cout << "Type in your password: ";
                cin >> password;

                if (fakeBankAccounts[accNumber]->verifyPin(password)) {
                    cout << "Welcome!" << endl;
                    fakeBankAccounts[accNumber]->displayAccountInfo();
                } else {
                    cout << "The password does not match this account." << endl;
                    clearMemory(fakeBankAccounts);
                    return 0;
                }
                clearScreen();

                cout << "Alright, " << fakeBankAccounts[accNumber]->getAccountHolderName() << endl;
                cout << "How much you want to withdraw?" << endl;
                cout << "U$";
                cin >> amount;

                while (!fakeBankAccounts[accNumber]->withdraw(amount)) {
                    fakeBankAccounts[accNumber]->displayAccountInfo();
                    cin >> amount;
                }
                fakeBankAccounts[accNumber]->displayAccountInfo();
                amount = 0;
                break;
            }

            case 5: {
                if(authentication(fakeBankAccounts, accNumber) == 1) {
                    break;
                }

                clearScreen();

                cout << "Hello " << fakeBankAccounts[accNumber]->getAccountHolderName() << " !" << endl;
                cout << "Type in your password: ";
                cin >> password;

                if (fakeBankAccounts[accNumber]->verifyPin(password)) {
                    char deleteChoice;
                    cout << "Are you sure? [Y] [N]: ";
                    cin >> deleteChoice;
                    if (std::tolower(deleteChoice) == 'y') {
                        delete fakeBankAccounts[accNumber];
                        cout << "Account sucessfully deleted." << endl;
                        break;
                    }
                } else {
                    cout << "The password does not match this account." << endl;
                    clearMemory(fakeBankAccounts);
                    return 0;
                }

                clearScreen();

            }

            default:
                break;
        }

    } while (choice != 0);

    clearMemory(fakeBankAccounts);

    return 0;
}
