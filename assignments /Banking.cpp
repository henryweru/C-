#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    string customerName;
    double balance;

public:
    Account(string accountNum, string name, double bal) {
        accountNumber = accountNum;
        customerName = name;
        balance = bal;
    }

    // Deposit method
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
    }


    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    
    virtual void display() const {
        cout << "Account Number: " << accountNumber << "\n"
             << "Customer Name: " << customerName << "\n"
             << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate; 

public:
    SavingsAccount(string accountNum, string name, double bal, double rate)
        : Account(accountNum, name, bal), interestRate(rate) {}

    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: $" << interest << ". New balance: $" << balance << endl;
    }

    void display() const override {
        cout << "Savings Account\n";
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit; 
public:
    CurrentAccount(string accountNum, string name, double bal, double overdraft)
        : Account(accountNum, name, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Overdraft limit exceeded! Withdrawal denied." << endl;
        }
    }

    void display() const override {
        cout << "Current Account\n";
        Account::display();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings("36457",
                           "Henry",
                            2000.0,
                            3.5);
    
    CurrentAccount current("7948", "Paul", 500.0, 1000.0);

    cout << "\n--- Savings Account Transactions ---\n";
    savings.display();
    savings.deposit(500);
    savings.withdraw(300);
    savings.addInterest(); 

    cout << "\n--- Current Account Transactions ---\n";
    current.display();
    current.deposit(200);
    current.withdraw(600);  
    current.withdraw(1500);  

    return 0;
}
