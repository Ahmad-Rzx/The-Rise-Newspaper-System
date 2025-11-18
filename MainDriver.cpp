#include <iostream>
#include <string>
#include "ManagementMenu.h"
using namespace std;
int main() {
    ManagementMenu menu;
    int numLocations;
    cout << "Enter number of locations in the city: ";
    cin >> numLocations;
    cin.ignore();
    startUpSystem(&menu, numLocations);
    cout << "Enter names of all locations:\n";
    for (int i = 0; i < numLocations; i++) {
        cout << "Location " << (i + 1) << ": ";
        getline(cin, menu.graph->locations[i]);
    }
    bool program_executing = true;
    while (program_executing) {
        cout << "\n--- Newspaper Delivery Management System ---\n";
        cout << "1. Add Client\n";
        cout << "2. Add Delivery Person\n";
        cout << "3. Add Delivery\n";
        cout << "4. Print All Clients\n";
        cout << "5. Print All Delivery Persons\n";
        cout << "6. Print All Deliveries\n";
        cout << "7. Save System\n";
        cout << "8. Load System\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            addClient(&menu);
        } else if (choice == 2) {
            addDeliveryPerson(&menu);
        } else if (choice == 3) {
            addDelivery(&menu);
        } else if (choice == 4) {
            printAllClients(&menu);
        } else if (choice == 5) {
            printAllDeliveryPersons(&menu);
        } else if (choice == 6) {
            printAllDeliveries(&menu);
        } else if (choice == 7) {
            string filename;
            cout << "Enter filename prefix to save system: ";
            cin >> filename;
            saveSystem(&menu, filename);
        } else if (choice == 8) {
            string filename;
            cout << "Enter filename prefix to load system: ";
            cin >> filename;
            loadSystem(&menu, filename);
        } else if (choice == 9) {
            program_executing = false;
            cout << "Exiting system...\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
    freeSystem(&menu);
    return 0;
}
