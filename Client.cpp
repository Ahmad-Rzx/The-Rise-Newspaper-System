#include<iostream>
#include<string>
#include<fstream>
#include "Client.h"
using namespace std;
void inputClients(Client* clients, int numClients){
    for(int i =0; i<numClients;i++){
        int printer = i+1;
        cout<<"Enter details for client: "<<printer<<"\n";
        cout<<"Client ID: ";
        cin>>clients[i].clientID;
        cin.ignore();
        cout<<"Client Name: ";
        getline(cin,clients[i].name);
        cout<<"Location Index: ";
        cin>>clients[i].locationIdx;
        cout<<"\n";
    }
}
void printClients(Client* clients, int numClients){
    cout<<"Clients Details:- \n";
    for(int i =0; i<numClients;i++){
        int printer = i+1;
        cout<<"Client "<<printer<<": \n";
        cout<<"ID: "<<clients[i].clientID<<"\n";
        cout<<"Name: "<<clients[i].name<<"\n";
        cout<<"Location Index: "<<clients[i].locationIdx<<"\n\n";
    }
}
void saveClients(string filename, Client* clients, int numClients){
    ofstream fout(filename, ios::binary);
    if(!fout){
        cout<<"Cannot Write Clients to File!\n";
        return;
    }
    fout.write((char*)&numClients,sizeof(numClients));
    for(int i =0; i<numClients;i++){
        fout.write((char*)&clients[i].clientID,sizeof(clients[i].clientID));
        int length = clients[i].name.size();
        fout.write((char*)&length,sizeof(length));
        fout.write(clients[i].name.c_str(),length);
        fout.write((char*)&clients[i].locationIdx,sizeof(clients[i].locationIdx));
    }
    fout.close();
}
void loadClients(string filename, Client*& clients, int& numClients){
    int num;
    ifstream fin(filename, ios::binary);
    if(!fin){
        cout<<"File cannot be Loaded!\n";
        return;
    }
    fin.read((char*)&num,sizeof(num));
    clients = new Client[num];
    for(int i =0; i<num; i++){
        fin.read((char*)&clients[i].clientID,sizeof(clients[i].clientID));
        int length;
        fin.read((char*)&length,sizeof(length));
        char* temp_name = new char[length +1];
        fin.read(temp_name,length);
        temp_name[length] = '\0';
        clients[i].name = (string)temp_name;
        delete[] temp_name;
        fin.read((char*)&clients[i].locationIdx,sizeof(clients[i].locationIdx));
    }
    fin.close();
}
void freeClients(Client*& clients){
    delete[] clients;
    clients = nullptr;
}