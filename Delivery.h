#pragma once
#include<iostream>
#include<string>
#include "Graph.h"
#include "Client.h"
#include "DeliveryPerson.h"
using namespace std;
struct Delivery{
    int deliveryID;
    int clientNo;
    int DeliveryPersonNo;
    int distance;
    int* route;
    int routeLength;
};
Delivery* createDelivery(int size);
void inputDelivery(Delivery*& deliveries, int &numDeliveries, Graph* graph,Client* clients,int numClients,DeliveryPerson* persons, int numPersons);
void printDelivery(Delivery& delivery,Client* clients,DeliveryPerson* persons,Graph* graph);
void saveDelivery(string filename,Delivery* deliveries,int numDeliveries);
void loadDelivery(string filename,Delivery* &deliveries,int &numDeliveries);
void freeDelivery(Delivery* &deliveries, int numDeliveries);
