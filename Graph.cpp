#include<iostream>
#include "Graph.h"
#include<string>
#include<fstream>
using namespace std;
Graph* createGraph(int numLocations){
    Graph* graph = new Graph;
    graph->numLocations = numLocations; 
    graph->distances = new int* [numLocations];
    for(int i =0; i< numLocations;i++){
        graph->distances[i] = new int[numLocations];
    }
    graph->locations = new string[numLocations];
    return graph;
}
void saveGraph(string filename, Graph*& graph){
    ofstream fout(filename, ios::binary);
    if (!fout){
        cout<<"Cannot Write the Graph in File!\n";
        return;
    }
    fout.write((char*)&graph->numLocations, sizeof(graph->numLocations));
    for(int i =0; i<graph->numLocations;i++){
        fout.write((char*)graph->distances[i],sizeof(int)*graph->numLocations);
    }
    for(int i =0; i<graph->numLocations;i++){
        int length = graph->locations[i].size();
        fout.write((char*)&length,sizeof(length));
        fout.write(graph->locations[i].c_str(),length);
    }
    fout.close();
}
void loadGraph(string filename, Graph*& graph) {
    ifstream fin(filename,ios::binary);
    if(!fin){
        cout<<"File cannot be Loaded!";
        return;
    }
    int num;
    fin.read((char*)&num,sizeof(num));
    graph = createGraph(num);
    for(int i =0; i<num;i++){
        fin.read((char*)graph->distances[i],sizeof(int)*num);
    }
    for(int i =0; i<num;i++){
        int length;
        fin.read((char*)&length,sizeof(length));
        char* temp_name = new char[length +1];
        fin.read(temp_name,length);
        temp_name[length] = '\0';
        graph->locations[i] = (string)temp_name;
        delete[] temp_name;
    }
    fin.close();
}
void printGraph(Graph* graph) {
    cout<<"Locations:- \n";
    for(int i =0;i<graph->numLocations;i++){
        int printer = i+1;
        cout<<printer<<" : "<<graph->locations[i]<<"\n";
    }
    cout<<"<-------------------------------------->\n";
    cout<<"The City Graph Depicting Distances Between Each Location:- \n";
    for(int i =0;i<graph->numLocations;i++){
        for(int j =0;j<graph->numLocations;j++){
            cout<<graph->distances[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void freeGraph(Graph*& graph) {
    for (int i = 0; i < graph->numLocations; i++)
        delete[] graph->distances[i];
    delete[] graph->distances;
    delete[] graph->locations;
    delete graph;
    graph = nullptr;
}
