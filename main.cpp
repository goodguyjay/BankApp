#include "BankAccount.hpp"

//TODO transformar esta merda em funcao
unsigned int matchAccountInfo(unsigned int userInput, BankAccount *fakeBank) {
    for (int i = 0; i < 3; i++) {
        if (fakeBank->getAccountNumber() != userInput) {
            cout << "["<< i + 1 << "] "
                 << "Sorry! No account matching that number was found. Please try again!" << endl;
            cin >> userInput;
        } else {
            return userInput;
        }
    }
    return false;
}

int main() {

    int choice = 0;
    auto fakeBank = new BankAccount("fake", 0, 0, 0);
    //auto test = new BankAccount("test account", 1111, 9999, 1500);
    unsigned int accCounter = 1000; //TODO change those variable names
    unsigned int accNumber = 0;
    unsigned int password;
    double amount;

    do {
        cout << "Hi! Welcome to FakeBank(not a scam)." << endl;
        cout << "How can may i help you?" << endl;
        cout << "----------------------------------" << endl;
        cout << "[1]I would like to open a account." << endl;
        cout << "[2]I would like to see my funds." << endl;
        cout << "[3]I would like to deposit funds into my account." << endl;
        cout << "[4]I would like to withdraw funds from my account." << endl;
        cout << "[5]I would like to delete my account." << endl;
        cout << "[0]Leave" << endl;
        cin >> choice;

        switch(choice) {
            case 1: {
                BankAccount::createAccount(fakeBank, accCounter);
                fakeBank->displayAccountInfo();
                accCounter++;
                break;
                // TODO this is absolute shit
            }

            case 2: {
                cout << "All right! Please type in your account number: (4 numbers) ";
                cin >> accNumber;

                for (int i = 0; i < 3; i++) {
                    if (fakeBank->getAccountNumber() != accNumber) {
                        cout << "[" << i + 1 << "] "
                             << "Sorry! No account matching that number was found. Please try again!" << endl;
                        cin >> accNumber;
                    } else {
                        break;
                    }
                }

                cout << "Hello " << fakeBank->getAccountHolderName() << " !" << endl;
                cout << "Type in your password: ";
                cin >> password;

                if (fakeBank->verifyPin(password)) {
                    cout << "Welcome!" << endl;
                    fakeBank->displayAccountInfo();
                } else {
                    cout << "nope" << endl;
                }

                break;
            }

            case 3: {
                cout << "All right! Please type in your account number: ";
                cin >> accNumber;

                if (!matchAccountInfo(accNumber, fakeBank)) {
                    return 1;
                }

                cout << "Alright, " << fakeBank->getAccountHolderName() << endl;
                cout << "How much you want to deposit?" << endl;
                cout << "U$";
                cin >> amount;
                fakeBank->deposit(amount); // TODO TRATAR VALORES NEGATIVOS
                fakeBank->displayAccountInfo();
                amount = 0;
                break;
            }

            case 4: {
                cout << "Alright, " << fakeBank->getAccountHolderName() << endl;
                cout << "How much you want to withdraw?" << endl;
                cout << "U$";
                cin >> amount;

                while (!fakeBank->withdraw(amount)) {
                    fakeBank->displayAccountInfo();
                    cin >> amount;
                }
                fakeBank->displayAccountInfo();
                amount = 0;
                break;
            }

            case 5: { //todo please fix this, jesus christ
                cout << "Okay, please type in the account number: ";
                cin >> accNumber;
                if (!matchAccountInfo(accNumber, fakeBank)) {
                    return 1;
                }
                cout << "Please type in your PIN: ";
                cin >> password;
                if (fakeBank->verifyPin(password)) {
                    char deleteChoice;
                    cout << "Are you sure? [Y] [N]";
                    cin >> deleteChoice;
                    if (std::tolower(deleteChoice) == 'y') {
                        delete fakeBank;
                        cout << "Account successfully deleted.";
                        break;
                    }
                } else {
                    cout << "Wrong password.";
                }

            }

            default:
                break;
        }

    } while (choice != 0);

    delete fakeBank;

    return 0;
}
