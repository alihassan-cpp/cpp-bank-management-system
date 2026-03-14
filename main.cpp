#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    string getName() {
        return name;
    }

    double getBalance() {
        return balance;
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
        saveToFile();
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
    void depositMoney() {

        int accNo;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        for (auto& a : accounts) {
            if (a.getAccountNumber() == accNo) {

                cout << "Enter amount to deposit: ";
                cin >> amount;

                a.deposit(amount);
                return;
            }
        }

        cout << "Account not found.\n";
    }
    void withdrawMoney() {

        int accNo;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        for (auto& a : accounts) {
            if (a.getAccountNumber() == accNo) {

                cout << "Enter amount to withdraw: ";
                cin >> amount;

                a.withdraw(amount);
                return;
            }
        }

        cout << "Account not found.\n";
    }
    void searchAccount() {

        int accNo;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        for (auto& a : accounts) {
            if (a.getAccountNumber() == accNo) {

                cout << "\nAccount Found:\n";
                a.display();
                return;
            }
        }

        cout << "Account not found.\n";
    }
    void deleteAccount() {

        int accNo;

        cout << "\nEnter Account Number to delete: ";
        cin >> accNo;

        for (auto it = accounts.begin(); it != accounts.end(); it++) {

            if (it->getAccountNumber() == accNo) {

                accounts.erase(it);
                saveToFile();
                cout << "Account deleted successfully.\n";
                return;
            }
        }

        cout << "Account not found.\n";
    }
    void saveToFile() {

        ofstream file("accounts.txt");

        for (auto& a : accounts) {

            file << a.getAccountNumber() << " "
                << a.getName() << " "
                << a.getBalance() << endl;
        }

        file.close();
    }
    void loadFromFile() {

        ifstream file("accounts.txt");

        int accNo;
        string name;
        double balance;

        while (file >> accNo >> name >> balance) {

            accounts.push_back(Account(accNo, name, balance));
        }

        file.close();
    }
};

int main() {

    Bank bank;
    bank.loadFromFile();
    int choice;

    while (true) {

        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Search Account\n";
        cout << "6. Delete Account\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bank.createAccount();
            break;
        
        case 2:
              bank.displayAccounts();
              break;
        
        case 3:
            bank.depositMoney();
            break;

        case 4:
            bank.withdrawMoney();
            break;

        case 5:
            bank.searchAccount();
            break;
        case 6:
            bank.deleteAccount();
            break;
        case 7: 
            cout << "Exiting program...\n";
            return 0;
      
        default: 
            cout << "Invalid choice.\n";
            
        }
    }
}
