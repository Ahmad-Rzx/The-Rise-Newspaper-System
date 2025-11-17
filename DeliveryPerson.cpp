#include<iostream>
#include<string>
#include<fstream>
#include "DeliveryPerson.h"
using namespace std;
void inputDeliveryPersons(DeliveryPerson* persons, int numPersons){
    for(int i =0; i<numPersons;i++){
        int printer = i+1;
        cout<<"Enter Details for Delivery Person "<<printer<<"\n";
        cout<<"Enter Delivery Person ID: ";
        cin>>persons[i].DeliveryPersonID;
        cin.ignore();
        cout<<"Enter Delivery Person's Name: ";
        getline(cin,persons[i].name);
        persons[i].currLocation = 0;
        cout<<"\n";
    }
}
void printDeliveryPersons(DeliveryPerson* persons, int numPersons){
    cout<<"Delivery Persons Details:- \n";
    for(int i =0; i<numPersons;i++){
        int printer = i+1;
        cout<<"Delivery Person "<<printer<<": \n";
        cout<<"ID: "<<persons[i].DeliveryPersonID<<"\n";
        cout<<"Name: "<<persons[i].name<<"\n";
        cout<<"Current Location Index: "<<persons[i].currLocation<<"\n\n";
    }
}
void saveDeliveryPersons(string filename, DeliveryPerson* persons, int numPersons){
    ofstream fout(filename,ios::binary);
    if(!fout){
        cout<<"Cannot Write Delivery Persons to File!";
        return;
    }
    fout.write((char*)&numPersons,sizeof(numPersons));
    for(int i =0; i<numPersons;i++){
        fout.write((char*)&persons[i].DeliveryPersonID,sizeof(persons[i].DeliveryPersonID));
        int length = persons[i].name.size();
        fout.write((char*)&length,sizeof(length));
        fout.write(persons[i].name.c_str(),length);
        fout.write((char*)&persons[i].currLocation,sizeof(persons[i].currLocation));
    }
    fout.close();
}
void loadDeliveryPersons(string filename, DeliveryPerson* &persons, int& numPersons){
    ifstream fin(filename,ios::binary);
    if (!fin){
        cout<<"Unable to Read Delivery Persons Data from File!";
        return;
    }
    int num;
    fin.read((char*)&num,sizeof(num));
    persons = new DeliveryPerson[num];
    for(int i =0; i<num;i++){
        fin.read((char*)&persons[i].DeliveryPersonID,sizeof(persons[i].DeliveryPersonID));
        int length;
        fin.read((char*)&length,sizeof(length));
        char* temp_name = new char[length +1];
        fin.read(temp_name,length);
        temp_name[length] = '\0';
        persons[i].name = (string)temp_name;
        delete[] temp_name;
        fin.read((char*)&persons[i].currLocation,sizeof(persons[i].currLocation));
    }
    fin.close();
}
void freeDeliveryPersons(DeliveryPerson* &persons){
    delete[] persons;
    persons = nullptr;
}