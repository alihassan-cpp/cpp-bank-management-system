#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Account(int accNo, string n, double bal) {
        accountNumber = accNo;
        name = n;
        balance = bal;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------------\n";
    }
};

class Bank {
private:
    vector<Account> accounts;

public:

    void createAccount() {

        int accNo;
        string name;
        double balance;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        cin.ignore();   

        cout << "Enter Name: ";
        getline(cin, name);   

        cout << "Enter Initial Balance: ";
        cin >> balance;

        accounts.push_back(Account(accNo, name, balance));

        cout << "\nAccount created successfully.\n";
    }
    void displayAccounts() {

        if (accounts.empty()) {
            cout << "\nNo accounts found.\n";
            return;
        }

        cout << "\n--- Account List ---\n";

        for (auto& a : accounts) {
            a.display();
        }
    }
};

int main() {

    Bank bank;
    int choice;

    while (true) {

        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
        {
            bank.createAccount();
            break;
        }
        case 2:{
              bank.displayAccounts();
              break;
        }
        case 3: {
            cout << "Exiting program...\n";
            return 0;
        }
        default: {
            cout << "Invalid choice.\n";
            }
        }
    }
}
