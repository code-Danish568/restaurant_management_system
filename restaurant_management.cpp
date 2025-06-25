
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {
        name = "";
        age = 0;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
public:
    string employeeID;
    string position;

    Employee() {
        employeeID = "";
        position = "";
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "ID: " << employeeID << ", Position: " << position << endl;
    }
};

class Customer : public Person {
public:
    string customerID;
    string contactInfo;

    Customer() {
        customerID = "";
        contactInfo = "";
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "ID: " << customerID << ", Contact: " << contactInfo << endl;
    }
};

class MenuItem {
public:
    string itemName;
    double price;

    MenuItem() {
        itemName = "";
        price = 0.0;
    }

    void displayItem() {
        cout << itemName << ": $" << price << endl;
    }
};

class Order {
public:
    string orderID;
    Customer customer;
    MenuItem items[10];
    int itemCount;

    Order() {
        orderID = "";
        itemCount = 0;
    }

    void addItem() {
        if (itemCount < 10) {
            MenuItem item;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, item.itemName);
            cout << "Enter item price: ";
            cin >> item.price;
            items[itemCount++] = item;
        } else {
            cout << "Cannot add more than 10 items.\n";
        }
    }

    void displayOrder() {
        cout << "\nOrder ID: " << orderID << endl;
        cout << "Customer: " << customer.name << endl;
        cout << "Items:" << endl;
        double total = 0;
        for (int i = 0; i < itemCount; ++i) {
            items[i].displayItem();
            total += items[i].price;
        }
        cout << "Total Price: $" << total << endl;
    }
};

class Restaurant {
public:
    string name;
    Employee employees[100];
    Customer customers[100];
    MenuItem menu[50];
    int employeeCount;
    int customerCount;
    int menuCount;

    Restaurant() {
        name = "";
        employeeCount = 0;
        customerCount = 0;
        menuCount = 0;
    }

    void addEmployee() {
        if (employeeCount < 100) {
            Employee employee;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, employee.name);
            cout << "Enter age: ";
            cin >> employee.age;
            cin.ignore();
            cout << "Enter employee ID: ";
            getline(cin, employee.employeeID);
            cout << "Enter position: ";
            getline(cin, employee.position);
            employees[employeeCount++] = employee;
        } else {
            cout << "Cannot add more than 100 employees.\n";
        }
    }

    void addCustomer() {
        if (customerCount < 100) {
            Customer customer;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, customer.name);
            cout << "Enter age: ";
            cin >> customer.age;
            cin.ignore();
            cout << "Enter customer ID: ";
            getline(cin, customer.customerID);
            cout << "Enter contact info: ";
            getline(cin, customer.contactInfo);
            customers[customerCount++] = customer;
        } else {
            cout << "Cannot add more than 100 customers.\n";
        }
    }

    void addMenuItem() {
        if (menuCount < 50) {
            MenuItem item;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, item.itemName);
            cout << "Enter price: ";
            cin >> item.price;
            menu[menuCount++] = item;
        } else {
            cout << "Cannot add more than 50 menu items.\n";
        }
    }

    void takeOrder() {
        Order order;
        cin.ignore();
        cout << "Enter order ID: ";
        getline(cin, order.orderID);
        cout << "Enter customer name: ";
        getline(cin, order.customer.name);

        char addMore;
        do {
            order.addItem();
            cout << "Add another item? (y/n): ";
            cin >> addMore;
        } while (addMore == 'y' || addMore == 'Y');

        order.displayOrder();
    }
};

int main() {
    Restaurant restaurant;
    int choice;

    do {
        cout << "\nRestaurant Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Add Customer\n";
        cout << "3. Add Menu Item\n";
        cout << "4. Take Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                restaurant.addEmployee();
                break;
            case 2:
                restaurant.addCustomer();
                break;
            case 3:
                restaurant.addMenuItem();
                break;
            case 4:
                restaurant.takeOrder();
                break;
            case 5:
                cout << "Exiting the Restaurant System.\n";
                cout << "Created by Mohammad Danish" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
