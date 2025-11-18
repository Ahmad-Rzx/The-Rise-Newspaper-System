#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "ManagementMenu.h"
using namespace std;
void calculateDistances(Graph* graph){
    srand(time(0));
    for(int i = 0; i < graph->numLocations; i++){
        for(int j = 0; j < graph->numLocations; j++){
            if(i == j)
                graph->distances[i][j] = 0;
            else if (i < j){
                int dist = rand() % 20 + 1;
                graph->distances[i][j] = dist;
                graph->distances[j][i] = dist;
            }
        }
    }
}
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
    calculateDistances(menu.graph);
    cout << "\nDistance matrix calculated automatically!\n";
    printGraph(menu.graph);
    bool running = true;
    while (running) {
        cout<<"\n--- Newspaper Delivery Management ---\n";
        cout<<"1. Add Client\n2. Add Delivery Person\n3. Add Delivery\n";
        cout<<"4. Print All Clients\n5. Print All Delivery Persons\n6. Print All Deliveries\n";
        cout<<"7. Save System\n8. Load System\n9. Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        if(choice == 1) addClient(&menu);
        else if(choice == 2) addDeliveryPerson(&menu);
        else if(choice == 3) addDelivery(&menu);
        else if(choice == 4) printAllClients(&menu);
        else if(choice == 5) printAllDeliveryPersons(&menu);
        else if(choice == 6) printAllDeliveries(&menu);
        else if(choice == 7) {
            string filename; cout << "Enter filename prefix: "; cin >> filename;
            saveSystem(&menu, filename);
        }
        else if(choice == 8) {
            string filename; cout << "Enter filename prefix: "; cin >> filename;
            loadSystem(&menu, filename);
        }
        else if(choice == 9) {
            running = false;
            cout << "Exiting system...\n";
        }
        else cout << "Invalid choice! Try again.\n";
    }
    freeSystem(&menu);
    return 0;
}
