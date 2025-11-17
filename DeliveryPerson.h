#include<iostream>
#include<string>
#pragma once
using namespace std;
struct DeliveryPerson{
    int DeliveryPersonID;
    string name;
    int currLocation;
};
void inputDeliveryPersons(DeliveryPerson* persons, int numPersons);
void printDeliveryPersons(DeliveryPerson* persons, int numPersons);
void saveDeliveryPersons(string filename, DeliveryPerson* persons, int numPersons);
void loadDeliveryPersons(string filename, DeliveryPerson* &persons, int& numPersons);
void freeDeliveryPersons(DeliveryPerson* &persons);