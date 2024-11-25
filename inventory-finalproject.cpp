#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

void menu() {
	cout << "Welcome to Inventory Management System" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Add New Item" << endl;
    cout << "2. View All Items" << endl;
    cout << "3. Update Item Quantity" << endl;
    cout << "4. Remove an Item" << endl;
    cout << "5. Generate Stock Report" << endl;
    cout << "6. Save & Exit" << endl;
    cout << "Enter choice: " <<endl;
}

int main()
{
    char choiceInput;
    menu();
    cin >> choiceInput;
    switch (choiceInput){
    	case '1':
    		addItem();
    		break;
    	case '2':
    		addItem();
    		break;
    	case '3':
    		addItem();
    		break;
    	case '4':
    		addItem();
    		break;
    	case '5':
    		addItem();
    		break;
    	case '6':
    		addItem();
    		break;
    	
    }
    return 0;
}

void addItem() {
    
}

void viewItems() {
						 
}

void updateQuantity() {
    
}

void removeItem() {
    
}

void generateReport() {
    
}
