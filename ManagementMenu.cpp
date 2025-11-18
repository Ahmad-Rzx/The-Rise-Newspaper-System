#include<iostream>
#include<string>
#include "ManagementMenu.h"
using namespace std;
void startUpSystem(ManagementMenu* menu, int numLocations){
    menu->graph = createGraph(numLocations);
    menu->clients = nullptr;
    menu->persons = nullptr;  
    menu->deliveries = createDelivery(0);
    menu->numClients = 0;
    menu->numPersons = 0;
    menu->numDeliveries = 0;
}
void addClient(ManagementMenu* menu){
    Client* newClients = new Client[menu->numClients + 1];
    for(int i = 0; i < menu->numClients; i++)
        newClients[i] = menu->clients[i];
    delete[] menu->clients;
    menu->clients = newClients;
    int newIndex = menu->numClients;
    menu->numClients += 1;      
    cout << "Enter details for client " <<newIndex + 1<< " :\n";
    cout << "Client ID: ";
    cin >> menu->clients[newIndex].clientID;
    cin.ignore();
    cout << "Client Name: ";
    getline(cin, menu->clients[newIndex].name);
    cout << "Location Index: ";
    cin >> menu->clients[newIndex].locationIdx;
    cout << "\n";
}
void addDeliveryPerson(ManagementMenu* menu){
    DeliveryPerson* newPersons = new DeliveryPerson[menu->numPersons + 1];
    for(int i = 0; i < menu->numPersons; i++)
        newPersons[i] = menu->persons[i];
    delete[] menu->persons;
    menu->persons = newPersons;
    int newIndex = menu->numPersons;
    menu->numPersons += 1;          
    cout << "Enter Details for Delivery Person " << (newIndex + 1) << ":\n";
    cout << "Delivery Person ID: ";
    cin >> menu->persons[newIndex].DeliveryPersonID;
    cin.ignore();
    cout << "Delivery Person Name: ";
    getline(cin, menu->persons[newIndex].name);
    menu->persons[newIndex].currLocation = 0;
    cout << "\n";
}
void addDelivery(ManagementMenu* menu){
    Delivery* newDeliveries = new Delivery[menu->numDeliveries + 1];
    for(int i = 0; i < menu->numDeliveries; i++){
        newDeliveries[i] = menu->deliveries[i];
    }
    delete[] menu->deliveries;
    menu->deliveries = newDeliveries;
    inputDelivery(menu->deliveries, menu->numDeliveries, menu->graph,menu->clients, menu->numClients, menu->persons, menu->numPersons);
}
void printAllClients(ManagementMenu* menu){
    printClients(menu->clients, menu->numClients);
}
void printAllDeliveryPersons(ManagementMenu* menu){
    printDeliveryPersons(menu->persons, menu->numPersons);
}
void printAllDeliveries(ManagementMenu* menu){
    for(int i =0;i<menu->numDeliveries;i++)
    printDelivery(menu->deliveries[i], menu->clients, menu->persons, menu->graph);
}
void saveSystem(ManagementMenu* menu, string filename){
    saveGraph(filename + "_graph.bin", menu->graph);
    saveClients(filename + "_clients.bin", menu->clients, menu->numClients);
    saveDeliveryPersons(filename + "_persons.bin", menu->persons, menu->numPersons);
    saveDelivery(filename + "_deliveries.bin", menu->deliveries, menu->numDeliveries);
}
void loadSystem(ManagementMenu* menu, string filename){
    loadGraph(filename + "_graph.bin", menu->graph);
    loadClients(filename + "_clients.bin", menu->clients, menu->numClients);
    loadDeliveryPersons(filename + "_persons.bin", menu->persons, menu->numPersons);
    loadDelivery(filename + "_deliveries.bin", menu->deliveries, menu->numDeliveries);
}
void freeSystem(ManagementMenu* menu){
    freeGraph(menu->graph);
    freeClients(menu->clients);
    freeDeliveryPersons(menu->persons);
    freeDelivery(menu->deliveries, menu->numDeliveries);
}