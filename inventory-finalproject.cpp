#include <iostream>

using namespace std;

// still need to implement file handling (reading and writing to a file)
void addItem(){
    cout << "Enter item ID: " << endl;
    cin  >> itemId;
    cout << "Enter item name: " << endl;
    cin  >> itemInput;
    cout << "Enter category: " << endl;
    cin  >> itemCategory;
    cout << "Enter stock quantity: " << endl;
    cin  >> stockQuantity;
    cout << "Enter unit price" << endl;
    cin  >> unitPrice;
}
void viewItems(){
    cout << "Item ID     Name     Category     Quantity      Unit Price" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "" << endl;
}
void updateQuantity(){
    cout << "Input item ID: " << endl;
    cin  >> itemId;
    cout << "Update stock (input a negative number to sell): " << endl;
}
void removeItem(){
    cout << "Input item ID:" << endl;
    cin >> itemId;
}
void generateReport(){
    cout << "Input category: " << endl;
    cin >> itemCategory;
    cout << "Stock report for Category:" << itemCategory << endl;
    cout << "--------------------------" << endl;
    cout << "Total Items:" << endl;
    cout << "Total stock value: " << endl;
}

int main()
{
    string itemId, itemInput, itemCategory, stockQuantity, unitPrice;
    string mainInput;

    cout << "Welcome to the Inventory Management System" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Add New Item" << endl;
    cout << "2. View All Items" << endl;
    cout << "3. Update Item Quantity" << endl;
    cout << "4. Remove an Item" << endl;
    cout << "5. Generate Stock Report" << endl;
    cout << "6. Save and Exit" << endl;

    switch(mainInput){
    case "1":
        addItem();
        break;
    case "2":
        viewItems();
        break;
    case "3"
        updateQuantity();
        break;
    case "4":
        removeItem();
        break;
    case "5":
        generateReport();
        break;
    case "6":
        // add savefile function here
    default:
        cout << "Invalid Input." << endl;
    }

    return 0;
}
