#include<iostream>
#include<string>
#include<cstring>
#pragma once
using namespace std;

struct Graph{
    int** distances; //Stores Distances 
    int numLocations; //Total Number of Locations
    string* locations; // Array of Location Names
};

Graph* createGraph(int numLocations);
void saveGraph(string filename, Graph*& graph);
void loadGraph(string filename, Graph*& graph);
void printGraph(Graph* graph);
void freeGraph(Graph*& graph);