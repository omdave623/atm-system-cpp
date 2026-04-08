#include <iostream>
using namespace std;

//  Base class 
class User {
protected:                 //  Encapsulation
    int pin;

public:
    //  Constructor
    User() {
        pin = 1234;
    }

    bool verifyPin(int enteredPin) {
        return (enteredPin == pin);
    }

    //  Virtual function (Runtime Polymorphism)
    virtual void display() {
        cout << "User Base Class\n";
    }
};

//  Derived class (Inheritance)
class ATM : public User {
private:                  // Encapsulation
    double balance;

public:
    //  Constructor
    ATM() {
        balance = 10000;
    }

    // Function Overriding
    void display() override {
        cout << "ATM System Ready\n";
    }

    void login() {
        int enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (verifyPin(enteredPin)) {
            display();   // calling overridden function
            menu();
        } else {
            cout << "Incorrect PIN!\n";
        }
    }

    void menu() {
        int choice;
        char again;

        do {
            cout << "\n ATM MENU \n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();   //  Overloading
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    cout << "Thank you for using ATM!\n";
                    again = 'n';
                    break;
                default:
                    cout << "Invalid choice!\n";
            }

            if (choice != 4) {
                cout << "\nDo you want another transaction? (y/n): ";
                cin >> again;
            }

        } while (again == 'y' || again == 'Y');
    }

    void checkBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }

    //  Compile-time Polymorphism (Function Overloading)
    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully!\n";
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs. " << amount << endl;
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
        
            cout << "Please collect your cash.\n";
        }
    }
};

//  Main function (Object creation)
int main() {
    ATM obj;   //  Object
    obj.login();
    return 0;
}