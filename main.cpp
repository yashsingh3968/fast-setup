#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer {
    int id;
    string name;
    int units;
    float bill;
};

vector<Customer> customers;

// Bill calculation
float calculateBill(int units) {
    return units * 2.0;   // simple rate: Rs 2 per unit
}

// Keep data sorted
void sortCustomers() {
    sort(customers.begin(), customers.end(), [](Customer a, Customer b) {
        return a.id < b.id;
    });
}

// Binary Search
int binarySearch(int id) {
    int low = 0, high = customers.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (customers[mid].id == id)
            return mid;
        else if (customers[mid].id < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Add customer
void addCustomer() {
    Customer c;
    cout << "Enter ID: ";
    cin >> c.id;
    cout << "Enter Name: ";
    cin >> c.name;
    cout << "Enter Units: ";
    cin >> c.units;

    c.bill = calculateBill(c.units);

    customers.push_back(c);
    sortCustomers();

    cout << "Customer added successfully!\n";
}

// View all
void viewCustomers() {
    for (Customer c : customers) {
        cout << "\nID: " << c.id;
        cout << "\nName: " << c.name;
        cout << "\nUnits: " << c.units;
        cout << "\nBill: Rs " << c.bill << "\n";
    }
}

// Generate bill
void generateBill() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    int index = binarySearch(id);

    if (index != -1) {
        cout << "\nCustomer: " << customers[index].name;
        cout << "\nTotal Bill: Rs " << customers[index].bill << "\n";
    } else {
        cout << "Customer not found!\n";
    }
}

// Update customer
void updateCustomer() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    int index = binarySearch(id);

    if (index != -1) {
        cout << "Enter new units: ";
        cin >> customers[index].units;

        customers[index].bill = calculateBill(customers[index].units);

        cout << "Customer updated successfully!\n";
    } else {
        cout << "Customer not found!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Customer Billing System ---\n";
        cout << "1. Add Customer\n";
        cout << "2. View All Customers\n";
        cout << "3. Generate Bill\n";
        cout << "4. Search Customer (Binary Search)\n";
        cout << "5. Update Customer\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: viewCustomers(); break;
            case 3: generateBill(); break;
            case 4: {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                int index = binarySearch(id);
                if (index != -1)
                    cout << "Customer found: " << customers[index].name << "\n";
                else
                    cout << "Customer not found!\n";
                break;
            }
            case 5: updateCustomer(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
