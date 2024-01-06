#include "BankAccount.hpp"

void clearScreen() { std::cout << "\x1B[2J\x1B[H"; };

void clearMemory(BankAccount *fakeBankAccounts[]) {
    for (int i = 0; i < 500; i ++) {
        delete fakeBankAccounts[i];
    }

    delete[] fakeBankAccounts;
}

bool accountNumberValidation(unsigned int &accNumber, unsigned int &accCounter) {

    if (accNumber == 0) {
        return false;
    }

    int i = 0;

    while ((accNumber >= accCounter) && (accNumber > 9999) && (accNumber < 0)) {
        cout << "["<< i + 1 << "] " << "This account do not exist. Please try again." << endl;
        cin >> accNumber;
        i++;

        if (i == 3) {
            cout << "Too many number of attempts. Please try again later.";
            return false;
        }
    }

    return true;
}

int main() {

    int choice = 0;
    unsigned int accCounter = 1;
    unsigned int accNumber = 0;
    unsigned int password = 0;
    double amount = 0;
    int i = 0;

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
                *fakeAccount = BankAccount::createAccount(accCounter);
                fakeBankAccounts[accNumber] = fakeAccount;
                clearScreen();

                fakeBankAccounts[accNumber]->displayAccountInfo();
                accCounter++;
                break;
            }

            case 2: {
                cout << "All right! Please type in your account number (Type 0 to leave this menu): ";
                cin >> accNumber;

                if (!accountNumberValidation(accNumber, accCounter)) {
                    break;
                }

                if (!fakeBankAccounts[accNumber]->matchAccountInfo(accNumber)) {
                    cout << "Too many number of attempts. Please try again later." << endl;
                    clearMemory(fakeBankAccounts);
                    return 0;
                }
                clearScreen();

                cout << "Hello " << fakeBankAccounts[accNumber]->getAccountHolderName() << " !" << endl;
                cout << "Type in your password: ";
                cin >> password;

                i = 0;
                while (!fakeBankAccounts[accNumber]->verifyPin(password) && i < 4) {
                    cout << "["<< i + 1 << "] " << "The password do not match with this account. Please try again." << endl;
                    cin.ignore();
                    cin >> password;
                    i++;

                    if (i == 3) {
                        cout << "Too many number of wrong attempts. Please try again later.";
                        clearMemory(fakeBankAccounts);
                        return 0;
                    }
                }

                fakeBankAccounts[accNumber]->displayAccountInfo();

                break;
            }

            case 3: {
                cout << "All right! Please type in your account number (Type 0 to leave this menu): ";
                cin >> accNumber;

                if (!accountNumberValidation(accNumber, accCounter)) {
                    break;
                }

                if (!fakeBankAccounts[accNumber]->matchAccountInfo(accNumber)) {
                    cout << "Too many number of attempts. Please try again." << endl;
                    clearMemory(fakeBankAccounts);
                    return 0;
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
                cout << "All right! Please type in your account number (Type 0 to leave this menu): ";
                cin >> accNumber;

                if (!fakeBankAccounts[accNumber]->matchAccountInfo(accNumber)) {
                    cout << "Too many number of attempts. Please try again." << endl;
                    clearMemory(fakeBankAccounts);
                    return 0;
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
                cout << "All right! Please type in your account number (Type 0 to leave this menu): ";
                cin >> accNumber;

                if (!fakeBankAccounts[accNumber]->matchAccountInfo(accNumber)) {
                    cout << "Too many number of attempts. Please try again." << endl;
                    clearMemory(fakeBankAccounts);
                    return 0;
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
