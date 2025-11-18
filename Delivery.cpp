#include<iostream>
#include<string>
#include<fstream>
#include "Delivery.h"
using namespace std;
Delivery* createDelivery(int size){
    Delivery* deliveries=new Delivery[size];
    for(int i =0; i<size;i++){
        deliveries[i].deliveryID=-1;
        deliveries[i].clientNo=-1;
        deliveries[i].DeliveryPersonNo=-1;
        deliveries[i].distance=0;
        deliveries[i].route=nullptr;
        deliveries[i].routeLength=0;
    }
    return deliveries;
}
void inputDelivery(Delivery*& deliveries, int &numDeliveries, Graph* graph,Client* clients,int numClients,DeliveryPerson* persons, int numPersons){
    int index = numDeliveries;
    cout<<"Select A Client from 0 to "<<numClients-1<<" :";
    int clientIdx;
    cin>>clientIdx;
    while(clientIdx<0 || clientIdx > numClients-1){
        cout<<"Invalid Client Selected, Select Again";
        cin>>clientIdx;
    }
    cout<<"Select A Delivery Person from 0 to "<<numPersons-1<<" :";
    int DeliveryPersonIdx;
    cin>>DeliveryPersonIdx;
    while(DeliveryPersonIdx<0 || DeliveryPersonIdx > numPersons-1){
        cout<<"Invalid Delivery Person Selected, Select Again";
        cin>>DeliveryPersonIdx;
    }
    deliveries[index].deliveryID=index;
    deliveries[index].clientNo=clientIdx;
    deliveries[index].DeliveryPersonNo=DeliveryPersonIdx;
    int start = persons[DeliveryPersonIdx].currLocation;
    int end = clients[clientIdx].locationIdx;
    int dist[graph->numLocations];
    bool visited[graph->numLocations];
    int prev[graph->numLocations];
    for(int i=0;i<graph->numLocations;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
        prev[i]=-1;
    }
    dist[start]=0;
    for(int j=0;j<graph->numLocations;j++){
        int min_dist = INT_MAX;
        int currentPoint = -1;
        for(int k =0; k<graph->numLocations;k++){
            if(visited[k] == false && dist[k] < min_dist){
                min_dist = dist[k];
                currentPoint = k;
            }
        }
        if(currentPoint == -1){
            break;
        }
        if(currentPoint == end) break;
        else visited[currentPoint] = true;
        for(int l =0; l< graph->numLocations;l++){
            if(graph->distances[currentPoint][l]>0 && visited[l] == false){
                if(dist[currentPoint] + graph->distances[currentPoint][l] < dist[l]){
                dist[l] = dist[currentPoint] + graph->distances[currentPoint][l];
                prev[l] = currentPoint;
                }
            }
        } 
    }
    int temp = end;
    int routeLength = 0;
    while(temp != -1){
        routeLength +=1;
        temp = prev[temp];
    }
    deliveries[index].routeLength = routeLength;
    deliveries[index].route = new int[routeLength];
    temp = end;
    for(int i = routeLength - 1;i>=0;i--){
    deliveries[index].route[i] = temp;
    temp = prev[temp];
    }
    deliveries[index].distance = dist[end];
    persons[DeliveryPersonIdx].currLocation = clients[clientIdx].locationIdx;
    numDeliveries +=1;
}
void printDelivery(Delivery& delivery,Client* clients,DeliveryPerson* persons,Graph* graph){
    cout<<"Delivery ID: "<<delivery.deliveryID<<"\n";
    cout<<"<<  CLIENT DETAILS  >>\n";
    cout<<"Client Name: "<<clients[delivery.clientNo].name<<"\n";
    cout<<"Allocated Delivery Person: "<<clients[delivery.DeliveryPersonNo].name<<"\n";
    cout<<"\n\n<<   DELIVERY DETAILS >>\n";
    cout<<"\n Delivery Person Current Location:"<<persons[delivery.DeliveryPersonNo].currLocation<<"\n";
    cout<<"Distance travelled for Delivery: "<<delivery.distance<<"\n";
    cout<<"<<  Route   >>\n";
    for(int i =0; i<delivery.routeLength;i++){
        cout<<delivery.route[i];
        if(i!=delivery.routeLength-1){
            cout<<"->";
        }
        cout<<"\n";
    }
}
void saveDelivery(string filename,Delivery* deliveries,int numDeliveries){
    ofstream fout(filename, ios::binary);
    if(!fout){
        cout<<"Error opening file for writing!"<<"\n";
        return;
    }
    fout.write((char*)&numDeliveries, sizeof(int));
    for(int i = 0; i < numDeliveries; i++) {
        fout.write((char*)&deliveries[i].deliveryID, sizeof(int));
        fout.write((char*)&deliveries[i].clientNo, sizeof(int));
        fout.write((char*)&deliveries[i].DeliveryPersonNo, sizeof(int));
        fout.write((char*)&deliveries[i].distance, sizeof(int));
        fout.write((char*)&deliveries[i].routeLength, sizeof(int));
        if(deliveries[i].routeLength > 0){
            fout.write((char*)deliveries[i].route, sizeof(int) * deliveries[i].routeLength);
        }
    fout.close();
}
}
void loadDelivery(string filename,Delivery* &deliveries,int &numDeliveries){
    ifstream fin(filename, ios::binary);
    if(!fin){
        cout <<"Error opening file for reading!"<<"\n";
        return;
    }
    fin.read((char*)&numDeliveries, sizeof(int));
    deliveries = createDelivery(numDeliveries);
    for(int i = 0; i < numDeliveries; i++) {
        fin.read((char*)&deliveries[i].deliveryID, sizeof(int));
        fin.read((char*)&deliveries[i].clientNo, sizeof(int));
        fin.read((char*)&deliveries[i].DeliveryPersonNo, sizeof(int));
        fin.read((char*)&deliveries[i].distance, sizeof(int));
        fin.read((char*)&deliveries[i].routeLength, sizeof(int));
        if(deliveries[i].routeLength > 0) {
            deliveries[i].route = new int[deliveries[i].routeLength];
            fin.read((char*)deliveries[i].route, sizeof(int) * deliveries[i].routeLength);
        } else {
            deliveries[i].route = nullptr;
        }
    }
    fin.close();
}
void freeDelivery(Delivery* &deliveries, int numDeliveries){
    for(int i = 0; i < numDeliveries; i++){
        if(deliveries[i].route != nullptr){
            delete[] deliveries[i].route;
            deliveries[i].route = nullptr;
        }
    }
    delete[] deliveries;
    deliveries = nullptr;
}
