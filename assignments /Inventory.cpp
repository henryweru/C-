#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor to initialize a new product
    Product(string name, double price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    // Function to update stock quantity
    void updateStock(int newQuantity) {
        quantity = newQuantity;
    }

    // Function to display product details (marked as const)
    void display() const {
        cout << "Product: " << name << ", Price: $" << price 
             << ", Quantity: " << quantity << endl;
    }

    // Function to return product name (marked as const)
    string getName() const {
        return name;
    }

    // Function to return product quantity (marked as const)
    int getQuantity() const {
        return quantity;
    }
};

// Function to add a new product
void addProduct(vector<Product>& inventory) {
    string name;
    double price;
    int quantity;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter product quantity: ";
    cin >> quantity;

    Product newProduct(name, price, quantity);
    inventory.push_back(newProduct);

    cout << "Product added successfully!\n";
}

// Function to update stock of an existing product
void updateProductStock(vector<Product>& inventory) {
    string productName;
    int newQuantity;

    cout << "Enter product name to update: ";
    cin >> productName;

    for (auto& product : inventory) {
        if (product.getName() == productName) {
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            product.updateStock(newQuantity);
            cout << "Stock updated successfully!\n";
            return;
        }
    }

    cout << "Product not found in inventory.\n";
}

// Function to display all products
void displayInventory(const vector<Product>& inventory) {
    cout << "Inventory Report:\n";
    for (const auto& product : inventory) {
        product.display();
    }
}

int main() {
    vector<Product> inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add New Product\n";
        cout << "2. Update Product Stock\n";
        cout << "3. Display Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                updateProductStock(inventory);
                break;
            case 3:
                displayInventory(inventory);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
