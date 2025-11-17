#include<iostream>
#include<string>
using namespace std;
#pragma once

struct Client{
    int clientID;
    string name;
    int locationIdx;
};
void inputClients(Client* clients, int numClients);
void printClients(Client* clients, int numClients);
void saveClients(string filename, Client* clients, int numClients);
void loadClients(string filename, Client*& clients, int& numClients);
void freeClients(Client*& clients);