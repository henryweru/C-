#include <iostream>
#include <iomanip>  // For std::setw
#include <vector>
#include <string>

class Employee {
protected:
    int id;
    std::string name;
    double basic_salary;

public:
    Employee(int i, std::string n, double bs) : id(i), name(n), basic_salary(bs) {}

    virtual double calculateSalary() const = 0; 

    virtual void displayDetails() const {
        std::cout << std::setw(3) << id << std::setw(18) << name; 
    }

    virtual ~Employee() = default; 
};

class PermanentEmployee : public Employee {
public:
    PermanentEmployee(int i, std::string n, double bs) : Employee(i, n, bs) {}

    double calculateSalary() const override {
        return basic_salary; 
    }

    void displayDetails() const override {
        Employee::displayDetails();
        std::cout << std::setw(12) << "Permanent" << std::setw(12) << calculateSalary() << '\n';
    }
};

class ContractEmployee : public Employee {
private:
    int hours_worked;
    double hourly_rate;

public:
    ContractEmployee(int i, std::string n, double hr, int hw) 
        : Employee(i, n, 0), hours_worked(hw), hourly_rate(hr) {}

    double calculateSalary() const override {
        return hours_worked * hourly_rate; 
    }

    void displayDetails() const override {
        Employee::displayDetails();
        std::cout << std::setw(12) << "Contract" << std::setw(12) << calculateSalary() << '\n';
    }
};

class PayrollSystem {
private:
    std::vector<Employee*> employees;

public:
    ~PayrollSystem() {
        for (Employee* emp : employees) {
            delete emp;
        }
    }

    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void displaySalaries() const {
        std::cout << std::setw(3) << "ID" << std::setw(18) << "Name" << std::setw(12) << "Type" << std::setw(12) << "Salary\n";
        std::cout << "---------------------------------------------------------\n";
        for (const Employee* emp : employees) {
            emp->displayDetails();
        }
    }
};

int main() {
    PayrollSystem payroll;

    payroll.addEmployee(new PermanentEmployee(1, "patrick", 50000.0));
    payroll.addEmployee(new PermanentEmployee(2, "Dee", 550000.0));

    payroll.addEmployee(new ContractEmployee(3, "Billy", 2500.0, 160)); 
    payroll.addEmployee(new ContractEmployee(4, "Jack", 3089.0, 120)); 

    payroll.displaySalaries();

    return 0;
}
