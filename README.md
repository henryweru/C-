### Assignment 

## CASE 1 Inventory Management System

# Product class:
- Contains private data members (name, price, and quantity).
- The updateStock() function is used to change the product's stock.
- The display() function outputs the product's details.

### Running Case 1 
run on your terminal
```bash
  g++ Inventory.cpp -o Inventory
```
```bash
  ./Inventory
```

## CASE 2: Student Grade Calculation
Each student has:
- A name.
- A student ID.
- Marks for three assignments.
- Marks for two exams.

# Requirements:
> Design a class Student with data members for the student's name, ID, assignment marks, and exam marks.
> Write a C++ program to prompt the user to enter the student data and then calculate and display each student's final grade.

# TEST CODE
Run 
```bash
  g++ grades.cpp -o grades 
```
```bash
  ./grades
```

## CASE 3: Banking System

> Question:
> Design a class hierarchy for Account with SavingsAccount and CurrentAccount as derived classes. Write a C++ program that simulates account transactions such as deposits, > > withdrawals, interest calculation, and overdraft management.

- Account Class: Contains common data members for account number, customer name, and balance.
- SavingsAccount Class: Inherits from Account and earns interest.
- CurrentAccount Class: Inherits from Account and allows overdrafts.

## Classes and Hierarchy:
- Account class (Base Class):

- Contains common attributes: accountNumber, customerName, and balance.
- Implements deposit and display functions.
- withdraw is a pure virtual function (making Account an abstract class) and must be overridden by derived classes.

  ## Test code
  ```bash
  g++ Banking.cpp -o Banking 
  ```
  ```bash
  ./Banking
  ```
  ## CASE 4: Library Book System
  
Question:
> Create a class Book with appropriate attributes and functions. Write a C++ program that allows a librarian to:
> Borrow a book if it is available.
> Return a borrowed book.
> Display the list of available books. Consider appropriate error handling for edge cases like trying to borrow an already borrowed book.

## Test code 
 ```bash
  g++ books.cpp -o books
 ```
   ```bash
  ./books
   ```
   


   





