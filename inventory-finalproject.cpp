#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

struct Item {
    string id;
    string name;
    string category;
    int quantity;
    double price;
};

vector<Item> inventory;
const string FILENAME = "inventory.txt";

void loadInventory() {
    ifstream file(FILENAME);
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '-') continue;

        Item item;
        if (line.substr(0, 3) == "ID:") {
            item.id = line.substr(4);
            getline(file, line);
            item.name = line.substr(6);
            getline(file, line);
            item.category = line.substr(10);
            getline(file, line);
            item.quantity = stoi(line.substr(10));
            getline(file, line);
            item.price = stod(line.substr(7));

            inventory.push_back(item);
        }
    }
    file.close();
}

void saveInventory() {
    ofstream file(FILENAME);

    for (const Item& item : inventory) {
        file << "ID: " << item.id << "\n"
            << "Name: " << item.name << "\n"
            << "Category: " << item.category << "\n"
            << "Quantity: " << item.quantity << "\n"
            << "Price: " << fixed << setprecision(2) << item.price << "\n"
            << "------------------------\n";
    }
    file.close();
}

void addItem() {
    Item item;
    cout << "Enter item ID: ";
    cin >> item.id;

    for (const Item& existing : inventory) {
        if (existing.id == item.id) {
            cout << "Error: Item ID already exists!\n";
            return;
        }
    }

    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, item.name);
    cout << "Enter category: ";
    getline(cin, item.category);

    while (true) {
        cout << "Enter stock quantity: ";
        if (cin >> item.quantity) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Enter unit price: ";
        if (cin >> item.price) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    inventory.push_back(item);
    cout << "Item added successfully!\n";
}

void viewItems() {
    cout << left << setw(10) << "Item ID"
        << setw(20) << "Name"
        << setw(15) << "Category"
        << setw(10) << "Quantity"
        << setw(12) << "Unit Price" << endl;
    cout << string(67, '-') << endl;

    for (const Item& item : inventory) {
        cout << left << setw(10) << item.id
            << setw(20) << item.name
            << setw(15) << item.category
            << setw(10) << item.quantity
            << "Php" << fixed << setprecision(2) << item.price << endl;
    }
}

void updateQuantity() {
    string itemId;
    cout << "Input item ID: ";
    cin >> itemId;

    for (Item& item : inventory) {
        if (item.id == itemId) {
            int change;
            while (true) {
                cout << "Update stock (input a negative number to sell): ";
                if (cin >> change) {
                    if (item.quantity + change < 0) {
                        cout << "Error: Not enough stock!\n";
                        return;
                    }
                    item.quantity += change;
                    cout << "Stock updated successfully!\n";
                    return;
                }
                else {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
    cout << "Error: Item not found!\n";
}

void removeItem() {
    string itemId;
    cout << "Input item ID: ";
    cin >> itemId;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == itemId) {
            inventory.erase(it);
            cout << "Item removed successfully!\n";
            return;
        }
    }
    cout << "Error: Item not found!\n";
}

void generateReport(string category = "") {
    double totalValue = 0;
    int totalItems = 0;

    cout << "\nStock Report";
    if (!category.empty()) {
        cout << " for Category: " << category;
    }
    cout << "\n--------------------------\n";

    for (const Item& item : inventory) {
        if (category.empty() || item.category == category) {
            totalItems += item.quantity;
            totalValue += item.quantity * item.price;
        }
    }

    cout << "Total Items: " << totalItems << endl;
    cout << "Total stock value: Php" << fixed << setprecision(2) << totalValue << endl;
}

int main() {
    loadInventory();
    while (true) {
        cout << "\nWelcome to the Inventory Management System\n";
        cout << "------------------------------------------\n";
        cout << "1. Add New Item\n";
        cout << "2. View All Items\n";
        cout << "3. Update Item Quantity\n";
        cout << "4. Remove an Item\n";
        cout << "5. Generate Stock Report\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";

        int choice;

        // Input validation for menu choice
        while (true) {
            if (cin >> choice) {
                if (choice >= 1 && choice <= 6) {
                    break;
                }
                else {
                    cout << "Invalid Input. Please enter a number between 1 and 6.\n";
                }
            }
            else {
                cout << "Invalid Input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            viewItems();
            break;
        case 3:
            updateQuantity();
            break;
        case 4:
            removeItem();
            break;
        case 5: {
            cout << "Input category (press Enter for all categories): ";
            cin.ignore();
            string category;
            getline(cin, category);
            generateReport(category);
            break;
        }
        case 6:
            saveInventory();
            cout << "Inventory saved. Goodbye!\n";
            return 0;
        }
    }

    return 0;
}
