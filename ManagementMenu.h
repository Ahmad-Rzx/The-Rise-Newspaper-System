#pragma once
#include<iostream>
#include<string>
#include "Graph.h"
#include "Client.h"
#include "DeliveryPerson.h"
#include "Delivery.h"
struct ManagementMenu{
    Graph* graph;
    Client* clients;
    DeliveryPerson* persons;
    Delivery* deliveries;
    int numClients;
    int numPersons;
    int numDeliveries;
};
void startUpSystem(ManagementMenu* menu, int numLocations);
void addClient(ManagementMenu* menu);
void addDeliveryPerson(ManagementMenu* menu);
void addDelivery(ManagementMenu* menu);
void printAllClients(ManagementMenu* menu);
void printAllDeliveryPersons(ManagementMenu* menu);
void printAllDeliveries(ManagementMenu* menu);
void saveSystem(ManagementMenu* menu, string filename);
void loadSystem(ManagementMenu* menu, string filename);
void freeSystem(ManagementMenu* menu);